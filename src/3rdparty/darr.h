#ifndef DARR_H
#define DARR_H

/*
   darr is a more or less type safe dynamic array.
   This is an alternative implementation to github.com/kevreco/re.lib/darrT.h
   ... using macro. 

   Example of use:

       void main() {
       
           darr(int) items;
           darr_init(&items);
       
           darr_push_back(&item, 1);
       }

   Macros and method with double underscores like "darr__to_any" are not meant to be used.
*/

#include <string.h>  /* memmove, memcpy */
#include <stdbool.h> /* bool */

#ifndef DARR_ASSERT
#include <assert.h>
#define DARR_ASSERT assert
#endif

#ifndef DARR_MALLOC
#include <stdlib.h>
#define DARR_MALLOC malloc
#endif

#ifndef DARR_REALLOC
#include <stdlib.h>
#define DARR_REALLOC realloc
#endif

#ifndef DARR_FREE
#include <stdlib.h>
#define DARR_FREE free
#endif

#if __cplusplus
extern "C" {
#endif

#define DARR_DEFAULT_CAPACITY 64

#define darr(type)      \
    struct {             \
        type* data;      \
        size_t size;     \
        size_t capacity; \
    }

typedef darr(char) darr_any;
typedef bool(*darr_predicate_t)(void* left, void* right);

/* Initialize array. No allocation performed. */
static inline void darr_any_init(darr_any* arr);

/* Destroy array. Deallocate memory if allocated. */
static inline void darr_any_destroy(darr_any* arr);

/* Remove items but does not deallocate anythings. */
static inline void darr_any_clear(darr_any* arr);

/* Create enough space to contains 'count' number of items. */
static inline void darr_any_ensure_space(darr_any* arr, size_t sizeof_value, size_t count);

/* Insert space at 'index' and increase the size of the array. */
static inline void darr_any_insert_many_space(darr_any* arr, size_t sizeof_value, size_t index, size_t count);

/* Insert space and then copy then values. */
static inline void darr_any_insert_many(darr_any* arr, size_t sizeof_value, size_t index, void* values_ptr, size_t count);

/* Insert space and then copy one value. */
static inline void darr_any_insert_one(darr_any* arr, size_t sizeof_value, size_t index, void* value);

/* Equivalent of std::lower_bound.
   Overload for darr_any. */
static inline size_t darr_any_lower_bound_predicate(darr_any* arr, size_t sizeof_value, void* value, darr_predicate_t less);

/* Equivalent of std::upper_bound.
   Overload for darr_any. */
static inline size_t darr_any_upper_bound_predicate(darr_any* arr, size_t sizeof_value, void* value, darr_predicate_t less);
/* Equivalent of std::lower_bound. */
static inline size_t mem_lower_bound_predicate(void* data_ptr, size_t sizeof_value, size_t left, size_t right, void* value, darr_predicate_t less);
/* Equivalent of std::upper_bound. */
static inline size_t mem_upper_bound_predicate(void* data_ptr, size_t sizeof_value, size_t left, size_t right, void* value, darr_predicate_t less);

/* Assume the array to be sorted.
   Insert one value at the correct place. */
static inline void darr_any_insert_one_sorted(darr_any* arr, size_t sizeof_value, void* value, darr_predicate_t less);
/* Assume the array to be sorted.
   Returns index of the already existing value or the inserted value. */
static inline size_t darr_any_get_or_insert(darr_any* arr, size_t sizeof_value, void* value, darr_predicate_t less);

/* Use duck typing to enforce a kind of compile-time safety. */
#define darr__ducktype_equals_to_any(arr) \
do { \
    darr_any ident = { \
       .data = (char*)(arr)->data, \
       .size = (arr)->size,        \
       .capacity = (arr)->capacity \
    }; \
    DARR_ASSERT(sizeof(void*) == sizeof((arr)->data) && "DARR TYPE ERROR (data)"); \
    DARR_ASSERT(sizeof(size_t) == sizeof((arr)->size) && "DARR TYPE ERROR (size)"); \
    DARR_ASSERT(sizeof(size_t) == sizeof((arr)->capacity) && "DARR TYPE ERROR (capacity)"); \
} while(0)

/* Convert darr to darr_any. */
#define darr__to_any(ident, arr)       \
    darr__ducktype_equals_to_any(arr); \
    darr_any* ident = (darr_any*)(arr)  \

#define darr_sizeof_value(arr) sizeof((arr)->data[0])

#define darr_init(arr) \
do { \
    darr__to_any(any, arr); \
    darr_any_init(any); \
}  while(0)

#define darr_destroy(arr) \
do { \
    darr__to_any(any, arr); \
    darr_any_destroy(any); \
}  while(0)

#define darr_clear(arr) \
do { \
    darr__to_any(any, arr); \
    darr_any_clear(any); \
}  while(0)

#define darr_insert_many(arr, index, values_ptr, count) \
do { \
    darr__to_any(any, arr); \
    darr_any_insert_many(any, darr_sizeof_value(arr), (index), (values_ptr), (count)); \
}  while(0)

#define darr_push_back_many(type, arr, values_ptr, count) \
do { \
    darr__to_any(any, arr); \
    darr_any_insert_many(any, darr_sizeof_value(arr), (arr)->size, (values_ptr), (count)); \
} while (0)

#define darr_push_back(arr, value)  \
do { \
    darr__to_any(any, arr); \
    darr_any_insert_many_space(any, darr_sizeof_value(arr), (arr)->size, 1); \
    (arr)->data[(arr)->size-1] = (value); \
} while (0)

#define darr_at(arr, i) ((arr)->data[i]);

#define darr_insert_one_sorted(arr, value, less) \
do { \
    darr__to_any(any, arr); \
    darr_any_insert_one_sorted(any, darr_sizeof_value(arr), (value), (less)); \
} while (0)

#define darr_ensure_space(arr, count) \
do { \
    darr__to_any(any, arr); \
    darr_any_ensure_space(any, darr_sizeof_value(arr), (count)); \
} while (0)

#define darr_get_or_insert(arr, value, value_ptr, less) \
do { \
    darr__to_any(any, arr); \
    size_t index = darr_any_get_or_insert(any, darr_sizeof_value(arr), &(value), less); \
    (value_ptr) = (arr)->data + index; \
} while(0)

/*
------------------------------------------------------------------------------
Implementation
------------------------------------------------------------------------------
*/

static inline void darr_any_init(darr_any* arr)
{
    memset(arr, 0, sizeof(darr_any));
}

static inline void darr_any_destroy(darr_any* arr)
{
    DARR_FREE(arr->data);
}

static inline void darr_any_clear(darr_any* arr)
{
    arr->size = 0;
}

static inline void darr_any_ensure_space(darr_any* arr, size_t sizeof_value, size_t count)
{
    if (arr->size + count > arr->capacity)
    {
        if (arr->capacity == 0)
        {
            arr->capacity = DARR_DEFAULT_CAPACITY;
        }

        /* Double capacity if capacity is reached. */
        while (arr->size + count > arr->capacity)
        {
            arr->capacity *= 2;
        }

        void* mem = DARR_REALLOC(arr->data, arr->capacity * sizeof_value);
        if (!mem)
        {
            free((arr)->data); /* Free old memory. */
            DARR_ASSERT(0 && "Could not allocated memory.");
            exit(1);
        }
        arr->data = (char*)mem;
    }
}

static inline void darr_any_insert_many_space(darr_any* arr, size_t sizeof_value, size_t index, size_t count)
{
    size_t count_to_move = arr->size - index;
    DARR_ASSERT(arr != NULL); 
    DARR_ASSERT(count != 0);
    DARR_ASSERT(index >= 0);
    DARR_ASSERT(index <= arr->size);
    darr_any_ensure_space(arr, sizeof_value, arr->size + count);
    if (count_to_move > 0)
    {
        memmove(
            arr->data + ((index + count) * sizeof_value),
            arr->data + (index * sizeof_value),
            count_to_move * sizeof_value);
    }
    arr->size += count;
}

static inline void darr_any_insert_many(darr_any* arr, size_t sizeof_value, size_t index, void* values_ptr, size_t count)
{
    /* Insert spaces at index. */
    darr_any_insert_many_space(arr, sizeof_value, index, count);
    /* Copy values to fillup the spaces. */
    memcpy(arr->data + (index * sizeof_value), values_ptr, count * sizeof_value);
}

static inline void darr_any_insert_one(darr_any* arr, size_t sizeof_value, size_t index, void* value)
{
    darr_any_insert_many(arr, sizeof_value, index, value, 1);
}

static inline void darr_any_insert_one_sorted(darr_any* arr, size_t sizeof_value, void* value, darr_predicate_t less)
{
    size_t index = darr_any_lower_bound_predicate(arr, sizeof_value, value, less);
    darr_any_insert_one(arr, sizeof_value, index, value);
}

static inline size_t darr_any_lower_bound_predicate(darr_any* arr, size_t sizeof_value, void* value, darr_predicate_t less)
{
    return mem_lower_bound_predicate(arr->data, sizeof_value, 0, arr->size, value, less);
}

static inline size_t darr_any_upper_bound_predicate(darr_any* arr, size_t sizeof_value, void* value, darr_predicate_t less)
{
    return mem_upper_bound_predicate(arr->data, sizeof_value, 0, arr->size, value, less);
}

static inline size_t mem_lower_bound_predicate(void* data_ptr, size_t sizeof_value, size_t left, size_t right, void* value, darr_predicate_t less)
{
    char* ptr = (char*)data_ptr;
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

static inline size_t mem_upper_bound_predicate(void* data_ptr, size_t sizeof_value, size_t left, size_t right, void* value, darr_predicate_t less)
{
    char* ptr = (char*)data_ptr;
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

static inline size_t darr_any_get_or_insert(darr_any* arr, size_t sizeof_value, void* value, darr_predicate_t less)
{
    size_t index = darr_any_lower_bound_predicate(arr, sizeof_value, value, less);
    if (index == arr->size  /* End was reached */
        || less(value, (arr->data + (index * sizeof_value))) /* Found value is not equal to the value in parameter. */
        )
    {
        darr_any_insert_one(arr, sizeof_value, index, value);
    }
    return index;
}

#if __cplusplus
}
#endif

#endif /* darr_H */