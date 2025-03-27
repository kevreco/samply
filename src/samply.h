#ifndef SAMPLY_H
#define SAMPLY_H

#include "strv.h"

#define SMP_APP_NAME "Samply"
#define SMP_ICON_PATH_LITERAL "./resources/samply.ico"

/* Version of the application. */
#define SMP_APP_VERSION_NUMBER (4)
#define SMP_APP_VERSION_TEXT "0.0.4-dev"

/* Version of the binary file format of the summary. */
#define SMP_SUMMARY_VERSION_NUMBER (1)
#define SMP_SUMMARY_VERSION_TEXT "0.0.1-dev"

#ifndef SMP_ASSERT
#include <assert.h>
#define SMP_ASSERT   assert
#endif

#ifndef SMP_MALLOC
#include <stdlib.h>
#define SMP_MALLOC malloc
#endif

#ifndef SMP_FREE
#include <stdlib.h>
#define SMP_FREE free
#endif

#ifdef _WIN32
#define SMP_MAX_PATH_BYTE_BUFFER_SIZE (1024 * sizeof(wchar_t))
#define SMP_MAX_PATH_WCHAR_BUFFER_SIZE (SMP_MAX_PATH_BYTE_BUFFER_SIZE / (sizeof(wchar_t)))
#else
#define SMP_MAX_PATH_BYTE_BUFFER_SIZE (1024)
#endif

#ifdef _MSC_VER
#define SMP_CDECL __cdecl
#else
#define SMP_CDECL
#endif

#if __cplusplus
extern "C" {
#endif

void samply_qsort(void* item_ptr, size_t count, size_t size_of_element, int (*comp)(const void*, const void*));

size_t samply_djb2_hash(strv str);

#ifdef _WIN32

int samply_convert_utf8_to_wchar_size(strv chars);

int samply_convert_utf8_to_wchar(wchar_t* buffer, size_t buffer_size, strv chars);

#endif

#if __cplusplus
}
#endif

#endif /* SAMPLY_H */