#ifndef SAMPLY_H
#define SAMPLY_H

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

#endif /* SAMPLY_H */