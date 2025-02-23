#ifndef SAMPLY_SAMPLER_H
#define SAMPLY_SAMPLER_H

#include "stdbool.h"

#include "darrT.h"
#include "insert_only_ht.h"
#include "symbol_manager.h"
#include "thread.h"

#if __cplusplus
extern "C" {
#endif

enum sample_status_result {
	sample_status_result_NONE,
	sample_status_result_SUCCESS,
	sample_status_result_SUSPEND_FAILED,
	sample_status_result_GET_CONTEXT_FAILED,
	sample_status_result_RESUME_FAILED
};

typedef struct sampler_task sampler_task;
struct sampler_task {
	const char* filename;
	process* process;
	enum sample_status_result status_result;
};

typedef struct record record;
struct record {
	strv symbol_name; /* Function name. */
	address address;  /* Address. */
	int line_number;  /* Line number associated with the address. */
	int counter;      /* Count number of time this address has been sampled. */
};

typedef struct sampler sampler;
struct sampler {

	/* Thread kept alive to perform the sampling. */
	thread_ptr_t thread;

	/* Timer only used to sleep threads. */
	thread_timer_t sleeper;

	bool must_end_sampling;

	/* Current task. */
	sampler_task* task;

	/* Number of sample from the current or last task. */
	size_t sample_count;

	/* Map to store the results by address. */
	ht results;

	/* We need the symbol_manager to load informations from a process
	   to retrieve some information (module name, line number)
	   and display them to the user. */
	symbol_manager mgr;
};

void sampler_init(sampler* s, struct string_store* store);

/* Stop sampling and wait for the thread to be finished. */
int sampler_destroy(sampler* s);

/* Add new sampling if there is not already one running. */
bool sampler_run(sampler* s, sampler_task* task);

/* Stop sampling. */
void sampler_stop(sampler* s);

#if __cplusplus
}
#endif

#endif /* SAMPLY_SAMPLER_H */