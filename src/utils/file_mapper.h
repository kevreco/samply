#ifndef SAMPLY_FILE_MAPPER_H
#define SAMPLY_FILE_MAPPER_H

#include "darrT.h"
#include "strv.h"
#include "wchar.h"

#if _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include "windows.h"
#endif

#if __cplusplus
extern "C" {
#endif

/* To mmap a file we need to use a string view as file path.
   Since the string view is not null-terminated we need a buffer to build the file path.
   This file_mapper is only there to reuse a buffer. */
typedef struct file_mapper file_mapper;
struct file_mapper {

#ifdef _WIN32
    darrT(wchar_t) chars;
#else
    darrT(char) chars;
#endif

};

typedef struct readonly_file readonly_file;
struct readonly_file {

#if _WIN32
    HANDLE handle;
    FILE_ID_INFO info;
#else
    int fd;
    struct stat st;
#endif
    strv view;
};

void file_mapper_init(file_mapper* fm);
void file_mapper_destroy(file_mapper* fm);

bool file_mapper_open(file_mapper* fm, readonly_file* file, strv filepath);
bool file_mapper_close(file_mapper* fm, readonly_file* file);

void readonly_file_init(readonly_file* file);
bool readonly_file_is_opened(readonly_file* file);

#if __cplusplus
}
#endif

#endif /* SAMPLY_FILE_MAPPER_H */