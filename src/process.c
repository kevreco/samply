#include "process.h"
#include "utils/log.h"

#include "samply.h"

bool args_are_valid(cmd_args args)
{
#ifdef _WIN32
	return args != NULL;
#else
	return args.argv != NULL;
#endif
}

void process_init(process* p)
{
	memset(p, 0, sizeof(process));

#if _WIN32
	p->file_name_buffer = (buffer_char_type*)SMP_MALLOC(SMP_MAX_PATH_BYTE_BUFFER_SIZE);
#endif
}

bool process_init_with_args(process* p, cmd_args args)
{
	process_init(p);

	if (args == NULL) {
		log_error("Process initialized with empty arguments");
		return false;
	}

	p->args = args;

	p->created = true;

	return true;
}

bool process_init_with_strv(process* p, strv str)
{
	process_init(p);

	if (!str.size) {
		log_error("Process initialized with empty string");
		return false;
	}
	
	samply_convert_utf8_to_wchar(p->file_name_buffer, SMP_MAX_PATH_WCHAR_BUFFER_SIZE, str);

	p->args = p->file_name_buffer;
	
	p->created = true;

	return true;
}

void process_destroy(process* p)
{

#if _WIN32
	SMP_FREE(p->file_name_buffer);
	CloseHandle(p->process_handle);
	CloseHandle(p->thread_handle);
#else
#error "process_destroy not implemented yet"
#endif
}

bool process_run_async(process* p)
{
#ifdef _WIN32
	STARTUPINFO si = {
		.cb = sizeof(STARTUPINFO)
	};
	PROCESS_INFORMATION pi = { 0 };

	BOOL created = CreateProcessW(
		NULL,    /* lpApplicationName */
		p->args, /* lpCommandLine */
		NULL,    /* lpProcessAttributes */
		NULL,    /* lpThreadAttributes */
		FALSE,   /* bInheritHandles */
		CREATE_SUSPENDED, /* dwCreationFlags */
		NULL,    /* lpEnvironment */
		NULL,    /* lpCurrentDirectory */
		&si,     /* lpStartupInfo */
		&pi);

	if (!created)
	{
		log_error("Could not create process: %lu", p->process_handle, GetLastError());
		return false;
	}

	p->process_handle = pi.hProcess;
	p->thread_handle = pi.hThread;
#else
#error "process_run not implemented yet"
#endif
	return true;
}
bool process_wait(process* p)
{
#ifdef _WIN32
	DWORD result = WaitForSingleObject(p->process_handle, INFINITE);

	if (result == WAIT_FAILED) {
		log_error("Could not wait on process '%d': %lu", p->process_handle, GetLastError());
		return false;
	}

	DWORD exit_status;
	if (!GetExitCodeProcess(p->process_handle, &exit_status)) {
		log_error("Could not get process exit code: %lu", GetLastError());
		return false;
	}

#else
#error "process_wait not implemented yet"
#endif
	return true;
}
bool process_run_sync(process* p)
{
	return process_run_async(p)
		&& process_wait(p);
}

void process_resume(process* p)
{
	DWORD ignore;
	ignore = ResumeThread(p->thread_handle);
}

void process_kill_if_created(process* p)
{
	if (p->created)
	{
		BOOL ignore;
		ignore = TerminateProcess(p->process_handle, 1);
	}
}

bool process_is_running(process* p)
{
	if (!p->process_handle)
	{
		return false;
	}

	bool terminated = WaitForSingleObject(p->process_handle, 0) == WAIT_OBJECT_0;
	return !terminated;
}

void process_stop(process* p)
{
#ifdef _WIN32
	TerminateProcess(p->process_handle, 1);

	/* From the documentation WaitForSingleObject needs to be called
	   if we want to make sure the process has terminated (in case it's asynchronous). */
	WaitForSingleObject(p->process_handle, INFINITE);
#else
#error "process_stop not implemented yet"
#endif
}