#include "sampler.h"

#include "darrT.h"
#include "strv.h"

#include "samply.h"
#include "utils/log.h"

enum sample_status_result {
	sample_status_result_NONE,
	sample_status_result_SUCCESS,
	sample_status_result_SUSPEND_FAILED,
	sample_status_result_GET_CONTEXT_FAILED,
	sample_status_result_RESUME_FAILED,
	sample_status_result_PROCESS_EXITED
};

static int sample_thread_procedure(sampler* s);
static enum sample_result get_sample(sampler* s, process* process);

static ht_hash_t hash_pointer(record* item);
static bool items_are_same(record* left, record* right);
static void items_swap(record* left, record* right);

void sampler_init(sampler* s)
{
	memset(s, 0, sizeof(sampler));

	ht_init(&s->results, sizeof(record), hash_pointer, (ht_predicate_t)items_are_same, items_swap, 1024);

	string_store_init(&s->string_store);
	symbol_manager_init(&s->mgr, &s->string_store);

	s->thread = thread_create(sample_thread_procedure, s, THREAD_STACK_SIZE_DEFAULT);

	thread_timer_init(&s->sleeper);

	int number_of_element = 1;
	int number_of_element_ready = 0;
	thread_queue_init(&s->thread_queue, number_of_element, s->command_buffer, number_of_element_ready);
}

int sampler_destroy(sampler* s)
{
	sampler_stop(s);

	// Push the exit command
	{
		s->command.type = sampler_command_type_EXIT;

		thread_queue_produce(&s->thread_queue, &s->command, THREAD_QUEUE_WAIT_INFINITE);
	}

	// Wait for the thread to exit
	int thread_return_value = thread_join(s->thread);

	thread_destroy(s->thread);

	thread_timer_term(&s->sleeper);

	ht_destroy(&s->results);

	string_store_destroy(&s->string_store);

	thread_queue_term(&s->thread_queue);

	symbol_manager_destroy(&s->mgr);

	return thread_return_value;
}

bool sampler_run(sampler* s, process* process)
{
	ht_clear(&s->results);
	s->sample_count = 0;

	s->command.type = sampler_command_type_START_SAMPLING;
	s->command.process = *process;

	bool added = thread_queue_produce(&s->thread_queue, &s->command, 0);

	if (added)
	{
		s->must_end_sampling = false;
		s->is_running = true;
	}
	else
	{
		log_error("Process not added to the sampler");
	}

	return added;
}

bool sampler_is_running(sampler* s)
{
	return s->is_running;
}

void sampler_stop(sampler* s)
{
	s->must_end_sampling = true;
}

static int sample_thread_procedure(sampler* s)
{
	thread_set_high_priority();

	while (!s->must_end_thread)
	{
		int no_timeout = 0;
		/* Wait until there is a new task. */
		sampler_command* cmd = (sampler_command*)thread_queue_consume(&s->thread_queue, THREAD_QUEUE_WAIT_INFINITE);
		if (cmd)
		{
			switch (cmd->type)
			{
			default:
			{
				SMP_ASSERT(0 && "Unknown command.");
				break;
			}
			case sampler_command_type_NONE:
			{
				SMP_ASSERT(0 && "Uninitialized command.");
				break;
			}
			case sampler_command_type_EXIT:
			{
				s->must_end_thread = true;
				break;
			}
			case sampler_command_type_START_SAMPLING:
			{
				process process = cmd->process;

				// Try to waif for the process to be initialized in order to properly load symbols.
				// We don't care about the result actually.
				WaitForInputIdle(process.process_handle, INFINITE);

				int nanoseconds = 1000000;
				thread_timer_wait(&s->sleeper, nanoseconds);

				/* Load process symbols. */
				symbol_manager_load(&s->mgr, process.process_handle);

				enum sample_result status_result = sample_status_result_NONE;

				/* Get sample while the status is "success". */
				while (!s->must_end_sampling
					&& process_is_running(&process)
					&& (status_result = get_sample(s, &process))
					&& status_result == sample_status_result_SUCCESS)
				{
					/* Continue */
				}

				symbol_manager_unload(&s->mgr);
				/* @TODO check if it's necessary. */
				thread_timer_wait(&s->sleeper, nanoseconds);

				/* Sampling is not running anymore. */
				s->is_running = false;

				break;
			}
			}
		}
		else
		{
			log_debug("Sampler command was null, this is likely due to a timeout.");
			s->is_running = false;
		}
	}

	log_debug("Sampler thread exited");
	return s->must_end_thread ? 0 : -1;
}

/*
	On Windows getting a sample is
		- Suspend thread.
		- Get address of the current function.
		- Resume thread.
		- Store address in hash table and increment counter
*/
static enum sample_result get_sample(sampler* s, process* process)
{
	if (!process_is_running(process))
	{
		return sample_status_result_PROCESS_EXITED;
	}
#if _WIN32
	HANDLE thread_handle = process->thread_handle;
	DWORD result = SuspendThread(thread_handle);

	if (result == (DWORD)(-1))
	{
		return sample_status_result_SUSPEND_FAILED;
	}

	CONTEXT thread_ctx = {0};
	thread_ctx.ContextFlags = CONTEXT_CONTROL;

	if (!GetThreadContext(thread_handle, &thread_ctx))
	{
		return sample_status_result_GET_CONTEXT_FAILED;
	}

	address addr = thread_ctx.Rip;

	DWORD resume_result = ResumeThread(thread_handle);
	if (resume_result == (DWORD)(-1))
	{
		return sample_status_result_RESUME_FAILED;
	}

	record item = {0};
	item.address = addr;
	
	/* @TODO document those lines. */
	record* inserted = (record*)ht_get_or_insert(&s->results, &item);
	inserted->counter += 1;

	/* @TODO retrieve symbol name after sampling. */
	if (inserted->symbol_name.size == 0) 
	{
		inserted->symbol_name = symbol_manager_get_symbol_name(&s->mgr, addr);

		symbol_manager_get_location(&s->mgr, addr, &inserted->source_file, &inserted->line_number);

		inserted->module_name = symbol_manager_get_module_name(&s->mgr, addr);
	}

#endif

	s->sample_count += 1;
	return sample_status_result_SUCCESS;
}

static ht_hash_t hash_pointer(record* item)
{
	return item->address;
}

static bool items_are_same(record* left, record* right)
{
	return left->address == right->address;
}

static void items_swap(record* left, record* right)
{
	record tmp = *left;
	*left = *right;
	*right = tmp;
}