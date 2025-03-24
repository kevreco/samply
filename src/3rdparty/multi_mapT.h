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
	mem_lower_bound_predicate((arr)->data, darrT_sizeof_value(arr), 0, (arr)->size, &(value), (less))

#define multip_mapT_upper_bound(arr, value,  less) \
	mem_upper_bound_predicate((arr)->data, darrT_sizeof_value(arr), 0, (arr)->size, &(value), (less))

/* Get first item */
#define multip_mapT_get_at_lower_bound(arr, value_for_look_up, result_ptr, less) \
do { \
    darrT_to_any(any, arr); \
	size_t index = darr_any_lower_bound_predicate(any, darrT_sizeof_value(arr), &(value_for_look_up), (less)); \
	bool found = index != (arr)->size \
		&& !((less)(&(value_for_look_up), (arr)->data + index)); \
	result_ptr = found \
		? &(arr)->data[index] \
		: NULL; \
} while(0)


#endif /* MULTI_MAPT_H */