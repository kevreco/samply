/*

SUMMARY:

    Arena allocator.
    
    See end of file for license information.
    
    Allocator that allocate chunks or memory and never free until the allocator itself is destroyed.
    The capacity of a chunk is a multiple of a chunk_min_capacity provided when the allocator is created.
    Each chunk are stored as header of the allocated memory and count as used memory.

    The allocator can be cleared and reuse without deallocating memory.

    Do this
        #define RE_AA_IMPLEMENTATION
    before you include this file in *one* C or C++ file to create the implementation.

NOTES:

    Virtual allocation can be used with:
        #define RE_AA_VIRTUAL_ALLOC
        
    Non-virtual allocation are aligned by default but can be disable with:
        #define RE_AA_ALIGN_MALLOC (0)

    Assert can be redefined with:
        #define RE_AA_ASSERT(x) my_assert(x)

    malloc and free can be redefined with:
        #define RE_AA_MALLOC(x) my_malloc(x)
        #define RE_AA_FREE(x) my_free(x)

EXAMPLE:

    #define RE_AA_IMPLEMENTATION
    #include "arena_alloc.h"
    
    int main() {

        re_arena a;
        re_arena_init(&a, 16 * 1024);

        void * mem = re_arena_alloc(&a, 64);
        void * mem2 = re_arena_alloc(&a, 128);

        do_something_with_mem(mem);
        do_something_with_mem(mem2);

        re_arena_destroy(&a);

        return 0;
    }
*/

#ifndef RE_AA_H
#define RE_AA_H

#ifndef RE_AA_API
#define RE_AA_API
#endif

#ifndef RE_AA_ASSERT
#include <assert.h>
#define RE_AA_ASSERT(x) assert(x)
#endif

#ifndef RE_AA_MALLOC
#include <stdlib.h>
#define RE_AA_MALLOC(x) malloc(x)
#endif

#ifndef RE_AA_FREE
#include <stdlib.h>
#define RE_AA_FREE(x) free(x)
#endif

#ifndef RE_AA_ALIGNMENT
#define RE_AA_ALIGNMENT (sizeof(void*) * 2)
#endif

/* Is ignored if RE_AA_VIRTUAL_ALLOC is used */
#ifndef RE_AA_ALIGN_MALLOC
#define RE_AA_ALIGN_MALLOC (1)
#endif

#ifdef RE_AA_VIRTUAL_ALLOC
#ifdef _WIN32
#include <windows.h>  /* VirtualAlloc */
#else
#include <sys/mman.h> /* mmap */
#endif
#endif

#include "stddef.h" /* ptrdiff_t */

#define RE_AA_SIZEOF_CHUNK_ALIGNED (align_up(sizeof(re_chunk), RE_AA_ALIGNMENT))

typedef struct re_chunk re_chunk;
struct re_chunk {
    re_chunk* next;
    size_t size;
    size_t capacity;
    ptrdiff_t alignment_offset; /* In case of alignment on malloc */
};

typedef struct re_arena re_arena;
struct re_arena {
    re_chunk* first;
    re_chunk* last;
    size_t chunk_min_capacity;
};

/* Initialize the arena, this does not allocate anything.
   Chunk must be a power of two.
*/
RE_AA_API void re_arena_init(re_arena* a, size_t chunk_min_capacity);

/* Destroy an arena. */
RE_AA_API void re_arena_destroy(re_arena* a);

/* Clear memory but does not deallocate anything. */
RE_AA_API void re_arena_clear(re_arena* a);

/* Allocate memory. */
RE_AA_API void* re_arena_alloc(re_arena* a, size_t byte_size);

/* Debug print some internal values. */
RE_AA_API void re_arena_debug_print(re_arena* a);

RE_AA_API size_t re_arena_allocated_chunk_count(re_arena* a);

typedef struct re_arena_state re_arena_state;
struct re_arena_state {
    re_chunk* chunk;
    size_t size;
};

/* Save where we are (int which chunk and at which position) in case we want to rollback. */
RE_AA_API re_arena_state re_arena_save_state(re_arena* a);
RE_AA_API void re_arena_rollback_state(re_arena* a, re_arena_state s);

#endif /* RE_ARENA_ALLOC_H */

#ifdef RE_AA_IMPLEMENTATION

#include <string.h>
#include <stdio.h>

static re_chunk* alloc_chunk(size_t byte_size);
static void free_chunk(re_chunk* c);
static void clear_chunk(re_chunk* c);

static size_t is_power_of_two(size_t v);
static size_t align_up(size_t v, size_t byte_alignment);
static size_t compute_capacity_to_allocate(re_arena* a, size_t byte_size);

RE_AA_API void
re_arena_init(re_arena* a, size_t chunk_min_capacity)
{
    RE_AA_ASSERT(is_power_of_two(chunk_min_capacity));
    RE_AA_ASSERT(chunk_min_capacity > sizeof(re_arena));

    memset(a, 0, sizeof(re_arena));
    a->chunk_min_capacity = chunk_min_capacity;
}

RE_AA_API void
re_arena_destroy(re_arena* a)
{
    re_chunk* c = a->first;
    while (c)
    {
        re_chunk* to_free = c;
        c = c->next;
        free_chunk(to_free);
    }
    a->first = NULL;
    a->last = NULL;
}

RE_AA_API void
re_arena_clear(re_arena* a)
{
    re_chunk* c = a->first;
    while (c)
    {
        clear_chunk(c);
        c = c->next;
    }

    a->last = a->first;
}

RE_AA_API void*
re_arena_alloc(re_arena* a, size_t byte_size)
{
    /* If there was no block allocated we allocate a new one */
    if (a->last == NULL) {
        RE_AA_ASSERT(a->first == NULL);
        size_t to_allocate = compute_capacity_to_allocate(a, byte_size);
        re_chunk* new_block = alloc_chunk(to_allocate);
        a->last = new_block;
        a->first = new_block;
    }
    else
    {
        /* If we want more data than the capacity we go to the next block (if it's not the last). */
        while (a->last->size + byte_size > a->last->capacity
            && a->last->next != NULL)
        {
            a->last = a->last->next;
        }

        /* If we reached the end and the capacity is reached. we alloc a new block */
        if (a->last->size + byte_size > a->last->capacity)
        {
            RE_AA_ASSERT(a->last->next == NULL);
            size_t to_allocate = compute_capacity_to_allocate(a, byte_size);
            a->last->next = alloc_chunk(to_allocate);
            a->last = a->last->next;
        }
    }
  
    /* Retrieve the memory ptr of the last block */
    char* result = ((char*)a->last + a->last->size);

    a->last->size += byte_size;
    return (void*)result;
}

RE_AA_API void
re_arena_debug_print(re_arena* a)
{
    size_t chunk_count = 0;
    size_t total_size = 0;
    size_t total_capacity = 0;

    re_chunk* c = a->first;
    while (c)
    {
        chunk_count += 1;
        total_size += c->size;
        total_capacity += c->capacity;
        c = c->next;
    }

    printf("arena: block count: %zu, total size: %zu, total capacity : %zu \n", chunk_count, total_size, total_capacity);
}

RE_AA_API size_t
re_arena_allocated_chunk_count(re_arena* a)
{
    size_t chunk_count = 0;

    re_chunk* c = a->first;
    while (c)
    {
        chunk_count += 1;
        c = c->next;
    }

    return chunk_count;
}


RE_AA_API re_arena_state
re_arena_save_state(re_arena* a)
{
    re_arena_state state;
    memset(&state, 0, sizeof(re_arena_state));

    if (!a->last)
    {
        state.chunk = a->last;
        state.size = 0;
    }
    else
    {
        state.chunk = a->last;
        state.size = a->last->size;
    }

    return state;
}

RE_AA_API void
re_arena_rollback_state(re_arena* a, re_arena_state state)
{
    if (!state.chunk)
    {
        re_arena_clear(a);
        return;
    }

    re_chunk* c = state.chunk->next;
    
    while (c)
    {
        clear_chunk(c);
        c = c->next;
    }

    a->last = state.chunk;
    a->last->size = state.size;
}

#include "stdio.h"

static re_chunk*
alloc_chunk(size_t byte_size)
{
    RE_AA_ASSERT(is_power_of_two(byte_size));

    size_t alignment_offset = 0;
    char* data = NULL;

#ifdef RE_AA_VIRTUAL_ALLOC

#ifdef _WIN32
    data = (char*)VirtualAlloc(NULL, byte_size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (data == NULL || data == INVALID_HANDLE_VALUE)
    {
        RE_AA_ASSERT(0 && "VirtualAlloc() failed.");
        return NULL;
    }
#else
    data = (char*)mmap(NULL, byte_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    if (data == MAP_FAILED)
    {
        RE_AA_ASSERT(0 && "mmap failed.");
        return NULL;
    }
#endif

#else

    /* Default malloc */
    data = (char*)RE_AA_MALLOC(byte_size);
    if (data == NULL)
    {
        RE_AA_ASSERT(0 && "malloc failed.");
        return NULL;
    }
   
    /* Adjust alignment if necessary. */
#ifdef RE_AA_ALIGNMENT

    char* aligned_memory = (char*)align_up((size_t)data, RE_AA_ALIGNMENT);
    
    RE_AA_ASSERT(aligned_memory >= data);

    alignment_offset = aligned_memory - data;

    RE_AA_ASSERT(alignment_offset >= 0);

    data = data + alignment_offset;
#endif

#endif
    /* Construct the block. */
    re_chunk* c = (re_chunk*)data;
    c->alignment_offset = alignment_offset;
    c->next = NULL;
    /* Block is instanciated within the allocated memory. So we count it as allocated memory. */
    c->size = RE_AA_SIZEOF_CHUNK_ALIGNED + c->alignment_offset;
    c->capacity = byte_size;

    return c;
}

static void
free_chunk(re_chunk* c)
{
#ifdef RE_AA_VIRTUAL_ALLOC
#ifdef _WIN32
    if (c != NULL || c != INVALID_HANDLE_VALUE)
    {
        if (!VirtualFree((LPVOID)c, c->capacity, MEM_RELEASE))
        {
            RE_AA_ASSERT(0 && "VirtualFree() failed.");
        }
    }
#else
    int ret = munmap(c, c->capacity);
    RE_AA_ASSERT(ret == 0);
#endif

#else
    /* NOTE: Alignment_offset is 0 if RE_AA_ALIGNMENT is not enabled */
    char* ptr = (char*)c;
    RE_AA_FREE(ptr - c->alignment_offset);
#endif
}

static void clear_chunk(re_chunk* c)
{
    /* The size of the chunk is the initial allocated value. */
    c->size = RE_AA_SIZEOF_CHUNK_ALIGNED + c->alignment_offset;
}

/* Next power of two if it's not already one. */
static size_t
next_power_of_two(size_t x) {
    if (x <= 1) return 1;
    int power = 2;
    x--;
    while (x >>= 1) power <<= 1;
    return power;
}

static size_t
is_power_of_two(size_t v)
{
    return 0 == (v & (v - 1));
}

static size_t
align_up(size_t v, size_t byte_alignment)
{
    /* Align must be a power of two */
    RE_AA_ASSERT(is_power_of_two(byte_alignment) && "Must align to a power of two.");
    return (v + (byte_alignment - 1)) & ~(byte_alignment - 1);
}

static size_t
compute_capacity_to_allocate(re_arena* a, size_t min_required_byte_size)
{
    min_required_byte_size = align_up(min_required_byte_size, RE_AA_ALIGNMENT);

    /* The chunk itself is part of the allocated memory so we add it to the byte_size. */
    min_required_byte_size += RE_AA_SIZEOF_CHUNK_ALIGNED;

    /* Increase capacity until it fits the allocated bytes.*/
    size_t capacity_to_allocate = a->chunk_min_capacity;
    while (capacity_to_allocate < min_required_byte_size)
    {
        capacity_to_allocate *= 2;
    }

    capacity_to_allocate = next_power_of_two(capacity_to_allocate);
    return capacity_to_allocate;
}

#endif /* RE_AA_IMPLEMENTATION */

/*
------------------------------------------------------------------------------
This software is available under 2 licenses -- choose whichever you prefer.
------------------------------------------------------------------------------
ALTERNATIVE 1 - The MIT License (MIT)

Copyright (c) 2024 kevreco

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
------------------------------------------------------------------------------
ALTERNATIVE 2 - Public Domain (www.unlicense.org)

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <https://unlicense.org>
------------------------------------------------------------------------------
*/