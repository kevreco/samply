#include "sampler.h"

#include "darrT.h"
#include "strv.h"

#include "log.h"

static int sample_thread_procedure(sampler* s);
static enum sample_result get_sample(sampler* s);

static ht_hash_t hash_pointer(record* item);
static bool items_are_same(record* left, record* right);
static void items_swap(record* left, record* right);

void sampler_init(sampler* s)
{
	memset(s, 0, sizeof(sampler));
	symbol_manager_init(&s->mgr);

	s->thread = thread_create(sample_thread_procedure, s, THREAD_STACK_SIZE_DEFAULT);

	thread_timer_init(&s->sleeper);

	ht_init(&s->results, sizeof(record), hash_pointer, (ht_predicate_t)items_are_same, items_swap, 1024);
}

int sampler_destroy(sampler* s)
{
	sampler_stop(s);

	int thread_return_value = thread_join(s->thread);

	thread_destroy(s->thread);

	thread_timer_term(&s->sleeper);

	ht_destroy(&s->results);

	return thread_return_value;
}

bool sampler_run(sampler* s, sampler_task* task)
{
	if (s->task)
	{
		log_error("Cannot run new sampling, while another is running");
		return false;
	}

	s->must_end_sampling = false;
	s->task = task;
	s->sample_count = 0;
	ht_clear(&s->results);

	return true;
}

void sampler_stop(sampler* s)
{
	s->must_end_sampling = true;
	s->task = 0;
}

static int sample_thread_procedure(sampler* s)
{
	thread_set_high_priority();

	while (!s->must_end_sampling)
	{
		/* Wait until there is a new task. */
		while (s->task == 0 && !s->must_end_sampling)
		{
			int nanoseconds = 1000;
			thread_timer_wait(&s->sleeper, nanoseconds);
		}

		if (!s->must_end_sampling)
		{
			symbol_manager_load(&s->mgr, s->task->process->process_handle);
		}

		if (!s->must_end_sampling)
		{
			enum sample_result status_result = sample_status_result_NONE;

			/* Get sample while the status is "success". */
			while (!s->must_end_sampling
				&& process_is_running(s->task->process)
				&& (status_result = get_sample(s))
				&& status_result == sample_status_result_SUCCESS)
			{
				/* Continue */
			}
		
			s->task->status_result = status_result;
		}

		/* Set task to null to make the thread sleep. */
		s->task = 0;
	}

	return s->must_end_sampling ? -1 : 0;
}

/*
	On Windows getting a sample is
		- Suspend thread.
		- Get address of the current function.
		- Resume thread.
		- Store address in hash table and increment counter
*/
static enum sample_result get_sample(sampler* s)
{
#if _WIN32
	HANDLE thread_handle = s->task->process->thread_handle;
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
	/* @TODO retrieve module name. */
	/* @TODO retrieve source file name. */
	/* @TODO retrieve line number. */
	if (inserted->symbol_name.size == 0) 
	{
		inserted->symbol_name = symbol_manager_get_symbol_name(&s->mgr, addr);
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