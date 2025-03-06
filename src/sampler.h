#ifndef SAMPLY_SAMPLER_H
#define SAMPLY_SAMPLER_H

#include "stdbool.h"

#include "thread.h"
#include "darrT.h"
#include "insert_only_ht.h"

#include "symbol_manager.h"
#include "string_store.h"

#if __cplusplus
extern "C" {
#endif

enum sampler_command_type {
	sampler_command_type_NONE,
	sampler_command_type_START_SAMPLING,
	sampler_command_type_EXIT
};

typedef struct sampler_command sampler_command;
struct sampler_command {
	enum sampler_command_type type;
	/* sampler task only used for the sampler_command_type_START_SAMPLING command. */
	process process;
};

typedef struct record record;
struct record {
	address address;     /* Address. */
	strv symbol_name;    /* Function name. */
	strv module_name;    /* Module name. */
	strv source_file;    /* Source file associated with the address. */
	size_t line_number;  /* Line number associated with the address. */
	size_t counter;      /* Count number of time this address has been sampled. */
};

typedef struct sampler sampler;
struct sampler {

	string_store string_store;

	/* Thread kept alive to perform the sampling. */
	thread_ptr_t thread;

	/* Timer only used to sleep the sampler thread. */
	thread_timer_t sleeper;

	/* Command to pass command to the sampler thread from another thread. */
	thread_queue_t thread_queue;

	/* Command buffer for the thread_queue */
	sampler_command* command_buffer[1];

	/* Actually reusable command that will be passed in the thread_queue. */
	sampler_command command;

	bool must_end_sampling;
	bool must_end_thread;

	bool is_running;
	/* Number of sample from the current or last task. */
	size_t sample_count;

	/* Map to store the results by address. */
	ht results;

	/* We need the symbol_manager to load informations from a process
	   to retrieve some information (module name, line number)
	   and display them to the user. */
	symbol_manager mgr;
};

void sampler_init(sampler* s);

/* Stop sampling and wait for the thread to be finished. */
int sampler_destroy(sampler* s);

/* Set process to sampler if there is not already one running.
   Returns true if it was successfuly added. */
bool sampler_run(sampler* s, process* process);

/* Sampling is running. */
bool sampler_is_running(sampler* s);

/* Stop sampling. */
void sampler_stop(sampler* s);

#if __cplusplus
}
#endif

#endif /* SAMPLY_SAMPLER_H */