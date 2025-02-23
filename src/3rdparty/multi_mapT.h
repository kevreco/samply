#ifndef MULTI_MAPT_H
#define MULTI_MAPT_H

/*
   This multi_map is intended to be used as a key/value map where multiple values are associated with a single key
   and where the values are sorted.
*/

#ifndef DARRT_H
#error "multi_mapT.h needs to be included after darrT.h"
#endif

#define multi_mapT(type) darrT(type)

#define multi_mapT_init(arr) darrT_init(arr)
#define multi_mapT_destroy(arr) darrT_destroy(arr)
#define multi_mapT_clear(arr) darrT_clear(arr)

#define multip_mapT_lower_bound(arr, value,  less) \
	darr_lower_bound_predicate((arr)->data, 0, (arr)->size, &(value), sizeof(*(arr)->data), (less))

/* Get first item */
#define multip_mapT_get_at_lower_bound(arr, value_for_look_up, result_ptr, less) \
do { \
	size_t index = darr_lower_bound_predicate((arr)->data, 0, (arr)->size, &(value_for_look_up), sizeof(*(arr)->data), (less)); \
	bool found = index != (arr)->size \
		&& !((less)(item, darr_ptr(&m->arr, index))); \
	result_ptr = found \
		? &(arr)->data[index] \
		: NULL; \
} while(0)

/* Insert a value using the 'less' predicate, if the value already exists it's still added to the array. */
#define multi_mapT_insert(arr, item, less) \
do { \
	size_t index = darr_lower_bound_predicate((arr)->data, 0, (arr)->size, &v, sizeof(*(arr)->data), (less)); \
	darrT_insert_many((arr), index, &(v), 1); \
} while(0)

#endif /* MULTI_MAPT_H */