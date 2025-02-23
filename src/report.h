#ifndef SAMPLY_REPORT_H
#define SAMPLY_REPORT_H

#include "stdio.h"   /* FILE */
#include "stdbool.h" /* bool */

#include "strv.h"
#include "darrT.h"
#include "arena_alloc.h"
#include "sampler.h" /* record */
#include "string_store.h"

#if __cplusplus
extern "C" {
#endif

typedef struct summed_record summed_record;
struct summed_record {
	size_t symbol_hash;
	strv symbol_name;
	strv module_name;
	strv source_file_name;
	size_t counter;
};

typedef darrT(record) records;
typedef darrT(summed_record) summed_records;

typedef struct report report;
struct report {
	string_store* string_store;

	size_t sample_count;
	/* Contains struct of records sorted by name then by count. */
	/* @TODO this is not used yet.. */
	records records_by_name;
	/* Contains struct of (function name, number of sample), sorted by count:
			func1 425
			func2 11
	*/
	summed_records summary_by_count;

	/* Arena to allocate data when loaded from a file. */
	re_arena arena;
};

void report_init(report* r, string_store* s);
void report_destroy(report* r);

/* Reset allocated buffers without deallocating them. */
void report_clear(report* r);

/*-----------------------------------------------------------------------*/
/* OUTPUT - Convert report to something else. */
/*-----------------------------------------------------------------------*/

/* Print to FILE. */
void report_print_to_file(report* s, FILE* f);

/* Save summary to filepath */
bool report_save_to_filepath(report* r, const char* filepath);

/* Save summary to FILE */
void report_save_to_file(report* r, FILE* f);

/*-----------------------------------------------------------------------*/
// INPUT - Load report from something else.
/*-----------------------------------------------------------------------*/

/* Clear report and load from sampler. */
void report_load_from_sampler(report* r, sampler* s);

/* Clear report and load from filepath. */
bool report_load_from_filepath(report* r, const char* filepath);

/* Clear report and load from FILE. */
void report_load_from_file(report* r, FILE* f);

#if __cplusplus
}
#endif

#endif /* SAMPLY_REPORT_H */