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
	m->symbol_buffer = malloc(4 * 1024);
#endif
}

void symbol_manager_destroy(symbol_manager* m)
{
	free(m->symbol_buffer);
}

void symbol_manager_load(symbol_manager* m, handle process_handle)
{
#if _WIN32

	SymSetOptions(SymGetOptions() | SYMOPT_LOAD_LINES);

	if (m->initialized)
	{
		log_error("Symbol already initialized, this must be done only once. %d", process_handle);
		return;
	}

	if (!SymInitialize(process_handle, NULL, TRUE))
	{
		/* @TODO Get string from GetLastError and display it. */
		log_error("Could not initialize symbols: %d", process_handle);
		return;
	}

	m->initialized = true;
	m->process_handle = process_handle;

#else
#error "symbol_manager_load not implemented yet"
#endif
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