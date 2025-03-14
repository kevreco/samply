#include "symbol_manager.h"

#if _WIN32
/* Specificaly include windows without "LEAN_AND_MEAN" here */
#include <windows.h>
#include <dbghelp.h> /* To retrieve the symbols. */
#include <psapi.h> /* GetModuleBaseNameA  */
#endif

#include "samply.h"
#include "utils/log.h"
#include "string_store.h"

void symbol_manager_init(symbol_manager* m, struct string_store* s)
{
	memset(m, 0, sizeof(symbol_manager));

	m->string_store = s;

#if _WIN32
	// From the MSDN documentation:
	//     https://learn.microsoft.com/en-us/windows/win32/debug/retrieving-symbol-information-by-address
	// The buffer for PSYMBOL_INFO must be large enough to contain the large symbol name.
	// However, when I use the example provided the buffer is not large enough
	// so I rounded up to 4096 and everything is working fine now.
	m->symbol_buffer = SMP_MALLOC(SMP_MAX_PATH_BYTE_BUFFER_SIZE);
#endif
}

void symbol_manager_destroy(symbol_manager* m)
{
	SMP_FREE(m->symbol_buffer);
}

#if _WIN32
static inline const wchar_t* wcsrchr_s(const wchar_t* str, const size_t len, const wchar_t c)
{
	for (const wchar_t* cursor = str + len; cursor >= str; cursor -= 1) {
		if (cursor[0] == c) {
			return cursor;
		}
	}
	return NULL;
}

#endif

void symbol_manager_prepare_for_load(symbol_manager* m, handle process_handle)
{
	(void)m;
#if _WIN32
	/* Try to wait for the process to be initialized in order to properly load symbols.
	We don't care about the result. */
	DWORD ignore;
	ignore = WaitForInputIdle(process_handle, INFINITE);
#else
	(void)process_handle;
#endif
}

bool symbol_manager_load(symbol_manager* m, handle process_handle)
{
#if _WIN32

	SymSetOptions(SymGetOptions() | SYMOPT_LOAD_LINES | SYMOPT_DEBUG);

	if (m->initialized)
	{
		log_error("Symbol already initialized, this must be done only once. %d", process_handle);
		return false;
	}

	/* Don't invade the process right now, SymRefreshModuleList will do it later.
	   Module refresh is done once the search paths are setup.
	*/
	bool fInvadeProcess = false;

	if (!SymInitialize(process_handle, NULL, fInvadeProcess))
	{
		log_error("Could not initialize symbols: %d", process_handle);
		return false;
	}

	wchar_t* buffer_begin = (wchar_t*)m->symbol_buffer;
	wchar_t* buffer = (wchar_t*)m->symbol_buffer;
	memset(buffer, 0, SMP_MAX_PATH_BYTE_BUFFER_SIZE);

	DWORD remaining_size = SMP_MAX_PATH_WCHAR_BUFFER_SIZE;

	/* Return the length of the path, or 0 */
	DWORD path_len = GetEnvironmentVariableW(L"_NT_SYMBOL_PATH", buffer, remaining_size);

	/* Adjust buffer */
	buffer += path_len;
	remaining_size -= path_len;
	
	/* Add separator in case the path was found. */
	if (path_len)
	{
		buffer[path_len] = L';';
		buffer += 1;
		remaining_size -= 1;
	}

	/* Get directory path of the running app. */
	DWORD size = remaining_size;
	if (!QueryFullProcessImageNameW(process_handle, 0, buffer, &size))
	{
		log_warning("QueryFullProcessImageNameW failed: %d", GetLastError());
	}
	/* Set the symbol search path after SymInitialize */
	else 
	{
		buffer += size;
		remaining_size -= size;
		
		/* Get last directory separator to guess the shrink the path and make it */
		wchar_t* buf_ptr = (wchar_t*)wcsrchr_s(buffer_begin, buffer - buffer_begin, '\\');
		if (buf_ptr != NULL)
		{
			buf_ptr[0] = '\0';
		}

		if (!SymSetSearchPathW(process_handle, buffer_begin))
		{
			log_warning("SymSetSearchPathW failed: %d", GetLastError());
		}
	}

	/* Not sure why but SymRefreshModuleList sometime fails and placing this Sleep fixed the issue... */
	Sleep(1);

	if (!SymRefreshModuleList(process_handle))
	{
		log_warning("SymRefreshModuleList  failed: %ul", GetLastError());
		return false;
	}

	m->initialized = true;
	m->process_handle = process_handle;

#else
#error "symbol_manager_load not implemented yet"
#endif

	return true;
}

void symbol_manager_unload(symbol_manager* m)
{
#if _WIN32
	if (!m->initialized)
	{
		return;
	}

	if (!SymCleanup(m->process_handle))
	{
		log_error("Could not cleanup symbols");
	}
	m->process_handle = 0;
	m->initialized = false;
#else
#error "symbol_manager_unload not implemented yet"
#endif
}

strv symbol_manager_get_symbol_name(symbol_manager* m, address addr)
{
	if (!m->initialized)
	{
		return (strv)STRV("");
	}

#if _WIN32
	DWORD64  dwDisplacement = 0;
	PSYMBOL_INFO pSymbol = (PSYMBOL_INFO)m->symbol_buffer;

	pSymbol->SizeOfStruct = sizeof(SYMBOL_INFO);
	pSymbol->MaxNameLen = MAX_SYM_NAME;

	if (!SymFromAddr(m->process_handle, addr, &dwDisplacement, pSymbol))
	{
		return (strv)STRV("");
	}

	strv symbol = strv_make_from(pSymbol->Name, pSymbol->NameLen);
	strv* s = string_store_get_or_create(m->string_store, symbol);
	return *s;
#else
#error "symbol_manager_get_symbol_name not implemented yet"
#endif
}

strv symbol_manager_get_module_name(symbol_manager* m, address addr)
{
	if (!m->initialized)
	{
		return (strv)STRV("");
	}

	HMODULE hModule = NULL;
	GetModuleHandleEx(
		GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS
		| GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, /* DWORD dwFlags*/
		(void*)addr, /* LPCWSTR lpModuleName */
		&hModule   /* HMODULE* phModule */
	);

	DWORD name_len = GetModuleBaseNameA(GetCurrentProcess(), hModule, m->symbol_buffer, MAX_PATH);

	if (name_len == 0)
	{
		return (strv)STRV("");
	}

	strv module_name;
	module_name.data = m->symbol_buffer;
	module_name.size = (size_t)name_len;

	strv* s = string_store_get_or_create(m->string_store, module_name);
	return *s;
}

void symbol_manager_get_location(symbol_manager* m, address addr, strv* source_file, size_t* line_number)
{
	if (!m->initialized)
	{
		return;
	}

	DWORD displacement = 0;
	IMAGEHLP_LINE64 line;
	line.SizeOfStruct = sizeof(IMAGEHLP_LINE64);

	if (SymGetLineFromAddr64(m->process_handle, addr, &displacement, &line))
	{
		strv filepath = strv_make_from_str(line.FileName);
		strv* s = string_store_get_or_create(m->string_store, filepath);
		*source_file = *s;
		*line_number = line.LineNumber;
	}
	else
	{
		*source_file = (strv)STRV("");
		*line_number = 0;
	}
}