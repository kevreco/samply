#include "string_store.h"

#include "string.h" /* memcpy */

#include "samply.h"

static ht_hash_t strv_hash(strv* item);
static bool strv_are_same(strv* left, strv* right);
static void strv_swap(strv* left, strv* right);

void string_store_init(string_store* s)
{
	ht_init(&s->map, sizeof(strv), strv_hash, (ht_predicate_t)strv_are_same, strv_swap, 0);

	int chunk_min_capacity = 4 * 1024;
	re_arena_init(&s->arena, chunk_min_capacity);
}

void string_store_destroy(string_store* s)
{
	ht_destroy(&s->map);
	re_arena_destroy(&s->arena);
}

strv* string_store_get_or_create(string_store* s, strv value)
{
	/* Save index if we need to rollback. */
	re_arena_state state = re_arena_save_state(&s->arena);

	// @TODO try to avoid rolling back and memcpy the strv value.

	/* Preallocate data. */
	void* mem = re_arena_alloc(&s->arena, value.size);
	memcpy(mem, value.data, value.size);
	strv newly_allocated_string = {
		.data = mem,
		.size = value.size
	};

	strv* result = ht_get_or_insert(&s->map, &newly_allocated_string);

	bool already_existed = result->data != newly_allocated_string.data;
	if (already_existed)
	{
		/* Rollback allocation if the string already existed. */
		re_arena_rollback_state(&s->arena, state);
	}
	return result;
}

static ht_hash_t strv_hash(strv* item)
{
	return samply_djb2_hash(*item);
}

static bool strv_are_same(strv* left, strv* right)
{
	return strv_equals(*left, *right);
}

static void strv_swap(strv* left, strv* right)
{
	strv tmp = *left;
	*left = *right;
	*right = tmp;
}