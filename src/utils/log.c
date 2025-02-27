#include "log.h"

#include "stdio.h"
#include <stdarg.h> /* va_start, va_end */

static void log_v(FILE* file, const char* prefix, const char* fmt, va_list args);

void log_error(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    log_v(stderr, "ERROR ", fmt, args);
    va_end(args);
}

void log_warning(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    log_v(stderr, "WARNING ", fmt, args);
    va_end(args);
}

void log_debug(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
#if _DEBUG
    log_v(stdout, "DEBUG ", fmt, args);
#endif
    va_end(args);
}

void log_message(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    log_v(stdout, "", fmt, args);
    va_end(args);
}

static void log_v(FILE* file, const char* prefix, const char* fmt, va_list args)
{
	va_list args_copy;
	va_copy(args_copy, args);

	fprintf(file, "%s", prefix);
	vfprintf(file, fmt, args_copy);
	fprintf(file, "\n");
}