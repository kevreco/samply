#ifndef SAMPLY_PROCESS_H
#define SAMPLY_PROCESS_H

#if _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#endif

#include "stdbool.h"

#include "strv.h"

#if __cplusplus
extern "C" {
#endif

#ifdef _WIN32

typedef wchar_t* cmd_args;
typedef HANDLE handle;
typedef DWORD exit_code;
typedef DWORD64 address;
typedef wchar_t buffer_char_type;

#else /* UNIX */

typedef cmd_args cmd_args;
struct {
	int argc;
	char** argv;
};
typedef int handle;
typedef int exit_code;
typedef size_t address;
typedef char file_buffer;
#endif

bool args_are_valid(cmd_args args);

typedef struct process process;
struct process {
	cmd_args args;
	handle process_handle;
	handle thread_handle;
	exit_code exit_code;
#if _WIN32
	buffer_char_type* file_name_buffer;
#endif
	bool created; /* Was created by Samply. */
};

void process_init(process* p);
bool process_init_with_args(process* p, cmd_args args);
bool process_init_with_strv(process* p, strv strv);
void process_destroy(process* p);

bool process_run_async(process* p);
bool process_wait(process* p);
bool process_run_sync(process* p);

/* Since process are created suspended with need to resume them before sampling. */
void process_resume(process* p);
/* Kill created process in case symbols are not loaded. */
void process_kill_if_created(process* p);

bool process_is_running(process* p);

void process_stop(process* p);

#if __cplusplus
}
#endif

#endif /* SAMPLY_PROCESS_H */