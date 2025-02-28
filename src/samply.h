#ifndef SAMPLY_H
#define SAMPLY_H

#define SMP_APP_NAME "Samply"

/* Version of the application. */
#define SMP_APP_VERSION_NUMBER (1)
#define SMP_APP_VERSION_TEXT "0.0.1-dev"

/* Version of the binary file format of the summary. */
#define SMP_SUMMARY_VERSION_NUMBER (1)
#define SMP_SUMMARY_VERSION_TEXT "0.0.1-dev"

#ifndef SMP_ASSERT
#include <assert.h>
#define SMP_ASSERT   assert
#endif

#ifdef _MSC_VER
#define SMP_CDECL __cdecl
#else
#define SMP_CDECL
#endif

#include "strv.h"

#if __cplusplus
extern "C" {
#endif

static inline size_t samply_djb2_hash(strv str)
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

#if __cplusplus
}
#endif

#endif /* SAMPLY_H */