#ifndef SAMPLY_PROCESS_H
#define SAMPLY_PROCESS_H

#if _WIN32
#include <windows.h>
#endif

#include "stdbool.h"

#if __cplusplus
extern "C" {
#endif

#ifdef _WIN32

typedef wchar_t* cmd_args;
typedef HANDLE handle;
typedef DWORD exit_code;
typedef DWORD64 address;

#else /* UNIX */

typedef cmd_args cmd_args;
struct {
	int argc;
	char** argv;
};
typedef int handle;
typedef int exit_code;
typedef size_t address;
#endif

bool args_are_valid(cmd_args args);

typedef struct process process;
struct process {
	cmd_args args;
	handle process_handle;
	handle thread_handle;
	exit_code exit_code;
};

bool process_init(process* p, cmd_args args);
void process_destroy(process* p);

bool process_run_async(process* p);
bool process_wait(process* p);
bool process_run_sync(process* p);

bool process_is_running(process* p);

void process_stop(process* p);

#if __cplusplus
}
#endif

#endif /* SAMPLY_PROCESS_H */