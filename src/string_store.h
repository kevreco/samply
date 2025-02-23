#ifndef SAMPLY_STRING_STORE_H
#define SAMPLY_STRING_STORE_H

#include "strv.h"
#include "arena_alloc.h" /* re_arena */
#include "insert_only_ht.h"

/* Handle string interning to avoid allocating too much data. */

#if __cplusplus
extern "C" {
#endif

typedef struct string_store string_store;
struct string_store {
	ht map;
	re_arena arena;
};

void string_store_init(string_store* s);
void string_store_destroy(string_store* s);

strv* string_store_get_or_create(string_store* s, strv value);


#if __cplusplus
}
#endif

#endif /* SAMPLY_STRING_store_H */