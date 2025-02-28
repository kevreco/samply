#include "report.h"

#include "samply.h"
#include "sampler.h"
#include "utils/log.h"

static char magic1_samp[4] = { 's', 'a', 'm', 'p' };
static char magic2_summ[4] = { 's', 'u', 'm', 'm' };
static uint64_t zero = 0;

/*

Summary Binary Format:

header	   |--------------------------|
		   | 1) magic number 1        | b8 x 4  | 's' 'a' 'm' 'p'
		   | 2) magic number 2        | b8 x 4  | 's' 'u' 'm' 'm'
		   | 3) zero                  | uint64
		   | 2) version number        | uint64
		   | 3) version info          | b8 x 32 | // null-terminated string of 32 byte (which include the null-terminated char).
		   | 4) total sampling count  | uint64
		   | 5) total symbol count    | uint64
frame 0..N | -------------------
		   | 1) symbol sampling count | uint64
		   | 2) symbol name size      | uint64
		   | 3) symbol name data      | ...
		   | 4) module name size      | uint64
		   | 5) module name data      | ...
		   | 6) source file name size | uint64
		   | 7) source file name data | ...
		   | 8) line number           | ...
*/

typedef struct summary_binary_header_v1 summary_binary_header_v1;
struct summary_binary_header_v1 {
	char magic1[4];
	char magic2[4];
	uint64_t zero;
	uint64_t version_number;
	char version_text[32];
	uint64_t total_sampling_count;
	uint64_t total_entry_count;
};

static bool summed_record_by_count_predicate_less(summed_record* left, summed_record* right);
static bool record_by_file_predicate_less(record* left, record* right);
static bool record_by_line_predicate_less(record* left, record* right);

/* Sort by source file, then by line number, then by address. */
static bool record_predicate_less(record* left, record* right);

static void upsert_record(report* r, record* rec);

static void update_summary_with(report* r, record* rec);
static int compare_summed_record(summed_record* left, summed_record* right);

static void write_bytes(FILE* f, void* data, size_t byte_count);
static void read_bytes(FILE* f, void* data, size_t byte_count);

static void write_uint64(FILE* f, uint64_t value);
static void read_uint64(FILE* f, uint64_t* v);

static void write_strv(FILE* f, strv str);
static void read_strv(FILE* f, re_arena* a, strv* str);

void report_init(report* r)
{
	memset(r, 0, sizeof(report));

	darrT_init(&r->summary_by_count);
	multi_mapT_init(&r->records);

	size_t min_chunk_capacity = 4 * 1024;
	re_arena_init(&r->arena, min_chunk_capacity);

	string_store_init(&r->string_store);
}

void report_destroy(report* r)
{
	darrT_destroy(&r->summary_by_count);

	multi_mapT_init(&r->records);

	re_arena_destroy(&r->arena);

	string_store_destroy(&r->string_store);
}

void report_clear(report* r)
{
	darrT_clear(&r->summary_by_count);
	
	multi_mapT_clear(&r->records);

	re_arena_clear(&r->arena);
}

/*-----------------------------------------------------------------------*/
/* OUTPUT - Convert report to something else. */
/*-----------------------------------------------------------------------*/

void report_print_to_file(report* r, FILE* f)
{
	double percent = 0;
	double count_f = (double)r->sample_count;
	fprintf(f, "Sample count: %zu\n", r->sample_count);

	/* Print summary */
	for (int i = 0; i < r->summary_by_count.size; i += 1)
	{
		summed_record item = darrT_at(&r->summary_by_count, i);
		percent = (double)item.counter / count_f;
		printf("%.2f" "\t" "%zu" "\t" STRV_FMT "\n", percent, item.counter, STRV_ARG(item.symbol_name));
	}
}

bool report_save_to_filepath(report* r, const char* filepath)
{
	FILE* f = fopen(filepath, "wb");
	if (!f)
	{
		log_error("Could not save to file '%s'", filepath);
		return false;
	}
	report_save_to_file(r, f);

	bool success = fclose(f) == 0;
	return success;
}

void report_save_to_file(report* r, FILE* f)
{
	summary_binary_header_v1 header =
	{
		.zero = zero,
		.version_number = SMP_SUMMARY_VERSION_NUMBER,
		.version_text = { SMP_SUMMARY_VERSION_TEXT },
		.total_sampling_count = r->sample_count,
		.total_entry_count = r->summary_by_count.size
	};
	memcpy(&header.magic1, &magic1_samp, sizeof(magic1_samp));
	memcpy(&header.magic2, &magic2_summ, sizeof(magic2_summ));

	write_bytes(f, &header, sizeof(summary_binary_header_v1));

	for (int i = 0; i < r->summary_by_count.size; i += 1)
	{
		summed_record item = r->summary_by_count.data[i];
		/* 1) symbol sampling count */
		write_uint64(f, item.counter);
		/* 2) symbol name size */
		/* 3) symbol name data */
		write_strv(f, item.symbol_name);
		/* 4) module name size */
		/* 5) module name data */
		write_strv(f, item.module_name);
		/* 6) source file name size */
		/* 7) source file name data */
		write_strv(f, item.source_file_name);
		/* 8) line number */
		write_uint64(f, item.line_number);
	}
}

/*-----------------------------------------------------------------------*/
/* INPUT - Load report from something else. */
/*-----------------------------------------------------------------------*/

void report_load_from_sampler(report* r, sampler* s)
{
	report_clear(r);

	r->sample_count = s->sample_count;

	ht_cursor c;
	ht_cursor_init(&s->results, &c);

	size_t total_counter_check = 0;

	while (ht_cursor_next(&c))
	{
		record* item = ht_cursor_item(&c);

		update_summary_with(r, item);
		upsert_record(r, item);

		total_counter_check += item->counter;
	}

	/* Sort entries by counters. */
	qsort(r->summary_by_count.data, r->summary_by_count.size, sizeof(summed_record), compare_summed_record);

	SMP_ASSERT(total_counter_check == s->sample_count);
}

bool report_load_from_filepath(report* r, const char* filepath)
{
	FILE* f = fopen(filepath, "rb");
	if (!f)
	{
		log_error("Could not save to file '%s'", filepath);
		return false;
	}

	report_load_from_file(r, f);

	bool success = fclose(f) == 0;
	return success;
}

void report_load_from_file(report* r, FILE* f)
{
	report_clear(r);

	summary_binary_header_v1 header;
	read_bytes(f, &header, sizeof(summary_binary_header_v1));

	SMP_ASSERT(memcmp(&header.magic1, &magic1_samp, sizeof(header.magic1)) == 0);
	SMP_ASSERT(memcmp(&header.magic2, &magic2_summ, sizeof(header.magic2)) == 0);
	SMP_ASSERT(header.zero == zero);
	SMP_ASSERT(header.version_number == SMP_SUMMARY_VERSION_NUMBER);

	log_debug("Loaded data:");
	log_debug("magic1:         \"%c%c%c%c\"",
		header.magic1[0], header.magic1[1], header.magic1[2], header.magic1[3]);
	log_debug("magic2:         \"%c%c%c%c\"",
		header.magic2[0], header.magic2[1], header.magic2[2], header.magic2[3]);
	log_debug("version:        %zu",    header.version_number);
	log_debug("version text:   \"%s\"", header.version_text);
	log_debug("sampling count: %zu",    header.total_sampling_count);
	log_debug("entry count:    %zu",    header.total_entry_count);

	for (int i = 0; i < header.total_entry_count; i += 1)
	{
		summed_record item = {0};
	
		/* 1) symbol sampling count */
		read_uint64(f, &item.counter);
		/* 2) symbol name size */
		/* 3) symbol name data */
		read_strv(f, &r->arena, &item.symbol_name);
		/* 4) module name size */
		/* 5) module name data */
		read_strv(f, &r->arena, &item.module_name);
		/* 6) source file name size */
		/* 7) source file name data */
		read_strv(f, &r->arena, &item.source_file_name);
		/* 8) line number */
		read_uint64(f, &item.line_number);
		
		darrT_push_back(summed_record , &r->summary_by_count, item);
	}
}

record_range record_range_make()
{
	record_range r;
	memset(&r, 0, sizeof(record_range));
	return r;
}

record_range record_range_for_file(record* records, size_t count, strv filepath)
{
	record_range range;
	record rec = { 0 };
	rec.source_file = filepath;
	size_t lower = darr_lower_bound_predicate(records, 0, count, &rec, sizeof(rec), (darr_predicate_t)record_by_file_predicate_less);
	size_t upper = darr_upper_bound_predicate(records, 0, count, &rec, sizeof(rec), (darr_predicate_t)record_by_file_predicate_less);

	range.begin = records + lower;
	range.end = records + upper;

	return range;
}

record_range record_range_for_line(record* records, size_t count, size_t line_number)
{
	record_range range;
	record rec = { 0 };
	rec.line_number = line_number;
	size_t lower = darr_lower_bound_predicate(records, 0, count, &rec, sizeof(rec), record_by_line_predicate_less);
	size_t upper = darr_upper_bound_predicate(records, 0, count, &rec, sizeof(rec), record_by_line_predicate_less);

	range.begin = records + lower;
	range.end = records + upper;

	return range;
}

static bool summed_record_by_count_predicate_less(summed_record* left, summed_record* right)
{
	return left->symbol_hash < right->symbol_hash;
}

static bool record_by_file_predicate_less(record* left, record* right)
{
	return strv_lexicagraphical_compare(left->source_file, right->source_file) < 0;
}

static bool record_by_line_predicate_less(record* left, record* right)
{
	return left->line_number < right->line_number;
}

/* Sort by source file, then by line number, then by address. */
static bool record_predicate_less(record* left, record* right)
{
	int cmp = strv_lexicagraphical_compare(left->source_file, right->source_file);
	if (cmp != 0)
		return cmp < 0;

	if (left->line_number != right->line_number)
		return left->line_number < right->line_number;

	return left->address < right->address;
}

static void upsert_record(report* r, record* rec)
{
	record line = *rec;
	size_t index = multip_mapT_lower_bound(&r->records, line, record_predicate_less);

	/* Item has been found if the index is within the array, and the item queried is not equal to the item at the index*/
	bool found = index != r->records.size
		&& (!record_predicate_less(&line, &r->records.data[index]));
	
	/* If the item already exist we merge the counters. */
	if (found)
	{
		r->records.data[index].counter += rec->counter;
	}
	else
	{
		darrT_insert_many(record, &r->records, index, &line, 1);
	}
}

static void update_summary_with(report* r, record* rec)
{
	summed_record init = { 0 };
	init.symbol_hash = samply_djb2_hash(rec->symbol_name);
	init.symbol_name = rec->symbol_name;
	init.module_name = rec->module_name;
	init.source_file_name = rec->source_file;
	init.line_number = rec->line_number;

	summed_record* result = 0;
	darrT_get_or_insert(summed_record , &r->summary_by_count, init, result, summed_record_by_count_predicate_less);
	result->counter += rec->counter;
}

static int SMP_CDECL compare_summed_record(const summed_record* left, const summed_record* right)
{
	if (left->counter < right->counter)
		return 1;
	if (left->counter > right->counter)
		return -1;
	return 0;
}

static void write_bytes(FILE* f, void* data, size_t byte_count)
{
	fwrite(data, byte_count, 1, f);
}

static void read_bytes(FILE* f, void* data, size_t byte_count)
{
	fread(data, byte_count, 1, f);
}

static void write_uint64(FILE* f, uint64_t value)
{
	fwrite(&value, sizeof(uint64_t), 1, f);
}

static void read_uint64(FILE* f, uint64_t* v)
{
	fread(v, sizeof(uint64_t), 1, f);
}

static void write_strv(FILE* f, strv str)
{
	/* Write size first */
	fwrite(&str.size, sizeof(str.size), 1, f);
	/* Then write string data. */
	fwrite(str.data, str.size, 1, f);
}

static void read_strv(FILE* f, re_arena* a, strv* str)
{
	size_t size;
	fread(&size, sizeof(size_t), 1, f);

	void* mem = re_arena_alloc(a, size);
	fread(mem, size, 1, f);

	*str = strv_make_from(mem, size);
}