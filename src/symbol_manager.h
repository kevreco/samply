#ifndef SAMPLY_SYMBOL_MANAGER_H
#define SAMPLY_SYMBOL_MANAGER_H

#include "arena_alloc.h" /* re_arena */
#include "darrT.h"
#include "strv.h" /* strv */

#include "process.h" /* For handle type. */

#if __cplusplus
extern "C" {
#endif

#if _WIN32

typedef struct module module;
struct module {
	address base_of_dll;
	strv name;
};
	
#else
	#warning "UNIX-like not implemented yet."
#endif

typedef darrT(module) modules;

typedef struct symbol_manager symbol_manager;
struct symbol_manager {
	struct string_store* string_store;
	handle process_handle;
	modules modules;
#if _WIN32
	char* symbol_buffer;
#endif
};

void symbol_manager_init(symbol_manager* m, struct string_store* s);
void symbol_manager_destroy(symbol_manager* m);
void symbol_manager_clear(symbol_manager* m);

/* Load symbols of specified process. */
void symbol_manager_load(symbol_manager* m, handle process_handle);

/* Get symbol name from the process loaded by symbol_manager_load. */
strv symbol_manager_get_symbol_name(symbol_manager* m, address addr);

/* Get location (source file and line number) from address. */
void symbol_manager_get_location(symbol_manager* m, address addr, strv* source_file, size_t* line_number);

#if __cplusplus
}
#endif

#endif /* SAMPLY_SYMBOL_MANAGER_H */