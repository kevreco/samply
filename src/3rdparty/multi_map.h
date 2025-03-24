#ifndef MULTI_MAP_H
#define MULTI_MAP_H

/*
   This multi_map is intended to be used as a key/value map where multiple values are associated with a single key
   and where the values are sorted.
*/

#ifndef DARR_H
#error "multi_map.h needs to be included after darr.h"
#endif

#define multi_map(type) darr(type)

#define multi_map_init(arr) darr_init(arr)
#define multi_map_destroy(arr) darr_destroy(arr)
#define multi_map_clear(arr) darr_clear(arr)

#define multip_map_lower_bound(arr, value,  less) \
	mem_lower_bound_predicate((arr)->data, darr_sizeof_value(arr), 0, (arr)->size, &(value), (less))

#define multip_map_upper_bound(arr, value,  less) \
	mem_upper_bound_predicate((arr)->data, darr_sizeof_value(arr), 0, (arr)->size, &(value), (less))

/* Get first item */
#define multip_map_get_at_lower_bound(arr, value_for_look_up, result_ptr, less) \
do { \
    darr_to_any(any, arr); \
	size_t index = darr_any_lower_bound_predicate(any, darr_sizeof_value(arr), &(value_for_look_up), (less)); \
	bool found = index != (arr)->size \
		&& !((less)(&(value_for_look_up), (arr)->data + index)); \
	result_ptr = found \
		? &(arr)->data[index] \
		: NULL; \
} while(0)


#endif /* MULTI_MAPT_H */