#include "samply.h"

#include <stdlib.h> /* qsort */

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#endif

void samply_qsort(void* item_ptr, size_t count, size_t size_of_element, int (*comp)(const void*, const void*))
{
    qsort(item_ptr, count, size_of_element, comp);
}

size_t samply_djb2_hash(strv str)
{

#define SMP_HASH_INIT (5381)
#define SMP_HASH(h, c) ((((h) << 5) + (h)) + (c))

    size_t hash = SMP_HASH_INIT;
    size_t i = 0;
    while (i < str.size)
    {
        hash = SMP_HASH(hash, str.data[i]);
        i += 1;
    }

    return hash;

#undef SMP_HASH_INIT
#undef SMP_HASH
}

#ifdef _WIN32

int samply_convert_utf8_to_wchar_size(strv chars)
{
    return MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, chars.data, (int)chars.size, NULL, 0);
}

int samply_convert_utf8_to_wchar(wchar_t* buffer, size_t buffer_size, strv chars)
{
    int result = 0;

    if (buffer_size != 0)
    {
        /* Convert From UTF-8. */
        result = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, chars.data, (int)chars.size, buffer, (int)buffer_size);
    }

    /* Ensure that the buffer ends with a null terminated wchar. */
    buffer[result] = L'\0';
    return result;
}

#endif