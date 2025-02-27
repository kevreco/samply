#ifndef DARRT_H
#define DARRT_H

/*
   darrT is a more or less type safe dynamic array.
   it's lightweigt alternative to github.com/kevreco/darrT.h
   ... using macro.
   Not sure I like it. 
*/

#include <stdlib.h>  /* realloc */
#include <stdbool.h> /* bool */

#ifndef DARR_ASSERT
#include <assert.h>
#define DARR_ASSERT   assert
#endif

#if __cplusplus
extern "C" {
#endif

#define DARR_DEFAULT_CAPACITY 64

#define darrT(type)      \
    struct {             \
        type* data;      \
        size_t size;     \
        size_t capacity; \
    }
    
typedef darrT(char) darr_void;
typedef bool(*darr_predicate_t)(void* left, void* right);

#define darrT_init(darr) \
    do { \
        memset((darr), 0, sizeof(*(darr))); \
    } while (0)

#define darrT_destroy(darr) \
    do { \
        free((darr)->data); \
    } while (0)

#define darrT_clear(darr) \
    do { \
        (darr)->size = 0; \
    } while (0)

/* Insert space at 'index' and increase the size of the array. */
#define darrT_insert_many_space(type, arr, index, count) \
do { \
    size_t count_to_move = (arr)->size - (index); \
    DARR_ASSERT((arr) != NULL); \
    DARR_ASSERT((count) != 0); \
    DARR_ASSERT((index) >= 0); \
    DARR_ASSERT((index) <= (arr)->size); \
    size_t sizeof_value = sizeof(*(arr)->data); \
    darrT_ensure_space(type, (arr), (arr)->size + (count)); \
    if (count_to_move > 0) \
    { \
        memmove((arr)->data + ((index) + (count)), (arr)->data + (index), count_to_move * sizeof_value); \
    } \
    (arr)->size += count; \
} while(0) 

/* Insert space and then copy then values. */
#define darrT_insert_many(type, arr, index, values_ptr, count) \
do { \
    darrT_insert_many_space(type, arr, index, count); \
    for(int i = 0; i < (count); i += 1) { \
        (arr)->data[index + i] = (values_ptr)[i]; \
    } \
}  while(0)

/* Insert values at the end of the array. */
#define darrT_push_back_many(type, arr, values_ptr, count) \
    darrT_insert_many(type, arr, (arr)->size, values_ptr, count)

#define darrT_push_back(type, arr, value)  \
    do { \
        darrT_insert_many_space(type, (arr), (arr)->size, 1); \
        (arr)->data[(arr)->size-1] = (value); \
    } while (0)

#define darrT_at(darr, i) ((darr)->data[i]);

/* Insert to a sorted array, using a predicate. */
#define darrT_insert_one_sorted(type, arr, value, less) \
do { \
        type v = (value); \
        size_t index = darr_lower_bound_predicate((arr)->data, 0, (arr)->size, &v, sizeof(*(arr)->data), (less)); \
        darrT_insert_many(type, (arr), index, &v, 1); \
} while (0)

/* Make enough space. */
#define darrT_ensure_space(type, arr, count) \
do { \
    if ((arr)->size + (count) > (arr)->capacity) \
    { \
        if ((arr)->capacity == 0) \
        { \
            (arr)->capacity = DARR_DEFAULT_CAPACITY; \
        } \
        while ((arr)->size + (count) > (arr)->capacity) \
        { \
            (arr)->capacity *= 2; \
        } \
        void* mem = realloc((arr)->data, (arr)->capacity * sizeof(*(arr)->data)); \
        if (!mem) { free((arr)->data); DARR_ASSERT(0 && "Could not allocated memory."); exit(1); } \
        (arr)->data = (type*)mem; \
    } \
} while (0)

inline size_t darr_lower_bound_predicate(void* void_ptr, size_t left, size_t right, void* value, size_t sizeof_value, darr_predicate_t less)
{
    char* ptr = (char*)void_ptr;
    size_t count = right - left;
    size_t step;
    size_t mid; /* index of the found value */

    while (count > 0) {
        step = count >> 1; /* count divide by two using bit shift */

        mid = left + step;

        if (less(ptr + (mid * sizeof_value), value) != 0) {
            left = mid + 1;
            count -= step + 1;
        }
        else {
            count = step;
        }
    }
    return left;
}

inline size_t darr_upper_bound_predicate(void* void_ptr, size_t left, size_t right, void* value, size_t sizeof_value, darr_predicate_t less)
{
    char* ptr = (char*)void_ptr;
    size_t count = right - left;
    size_t step;
    size_t mid; /* index of the found value */

    while (count > 0) {
        step = count >> 1; /* count divide by two using bit shift */

        mid = left + step;

        if (less(value, ptr + (mid * sizeof_value)) == 0) {
            left = mid + 1;
            count -= step + 1;
        }
        else {
            count = step;
        }
    }
    return left;
}

/* If value already exist, set it to value_ptr.
   Example:

       Type* result;
       Type to_insert = { ... }
       darrT_get_or_insert(arr, to_insert, result, less);
       // If to_insert did not exist yet it's inserted.
       // result always contains the new added item or the already existing item.
*/
#define darrT_get_or_insert(type, arr, value, value_ptr, less) \
do { \
    size_t index = darr_lower_bound_predicate((arr)->data, 0, (arr)->size, &(value), sizeof(*(arr)->data), (less)); \
    if (index == (arr)->size || (less)(&(value), ((arr)->data + index))) \
    { \
        darrT_insert_many(type, (arr), index, &(value), 1); \
    } \
    (value_ptr) = (arr)->data + index; \
} while(0)

#if __cplusplus
}
#endif

#endif /* DARRT_H */