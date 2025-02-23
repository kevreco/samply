#include "symbol_manager.h"

#include <dbghelp.h> /* To retrive the symbols. */

#include "samply.h"
#include "log.h"
#include "string_store.h"

void symbol_manager_init(symbol_manager* m, struct string_store* s)
{
	memset(m, 0, sizeof(symbol_manager));

	m->string_store = s;
	darrT_init(&m->modules);

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
	darrT_destroy(&m->modules);
	free(m->symbol_buffer);
}

#if _WIN32

BOOL CALLBACK EnumModules(
	PCSTR   ModuleName,
	DWORD64 BaseOfDll,
	PVOID   UserContext)
{
	symbol_manager* m = (symbol_manager*)UserContext;

	return TRUE;
}

#endif

void symbol_manager_load(symbol_manager* m, handle process_handle)
{
#if _WIN32
	if (!SymInitialize(process_handle, NULL, TRUE))
	{
		/* @TODO Get string from GetLastError and display it. */
		log_error("Could not initialize symbols");
		return;
	}

	if (!SymEnumerateModules64(process_handle, EnumModules, m))
	{
		/* @TODO Get string from GetLastError and display it. */
		log_error("Could not enumerate modules symbols");
	}

	m->process_handle = process_handle;
#else
#error "symbol_manager_load not implemented yet"
#endif
}

static strv unknown_symbol = STRV("<unknown-symbol>");
static strv out_of_mem_symbol = STRV("<out-of-memory>");

strv symbol_manager_get_symbol_name(symbol_manager* m, address addr)
{
#if _WIN32
	DWORD64  dwDisplacement = 0;
	PSYMBOL_INFO pSymbol = (PSYMBOL_INFO)m->symbol_buffer;

	pSymbol->SizeOfStruct = sizeof(SYMBOL_INFO);
	pSymbol->MaxNameLen = MAX_SYM_NAME;

	if (!SymFromAddr(m->process_handle, addr, &dwDisplacement, pSymbol))
	{
		return unknown_symbol;
	}

	strv symbol = strv_make_from(pSymbol->Name, pSymbol->NameLen);
	strv* s = string_store_get_or_create(m->string_store, symbol);
	return *s;
#else
#error "symbol_manager_get_symbol_name not implemented yet"
#endif
}

void symbol_manager_clear(symbol_manager* m)
{
#if _WIN32
	if (!SymCleanup(m->process_handle))
	{
		log_error("Could not cleanup symbols");
	}
#else
#error "symbol_manager_clear not implemented yet"
#endif
}