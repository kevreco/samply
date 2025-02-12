#include "gui/gui.hpp"

#include "string.h"

#include "process.h"

#define LITERAL_STREQUAL(str, literal_str) (strncmp(str, literal_str, sizeof(literal_str) - 1) == 0)

cmd_args get_args_to_run(char** argv);

int main(int argc, char** argv)
{
    // If the command line contains "--run" everything after will
    // run from a child process.
    // Example:
    //      samply --run app --with --args
    // Will run
    //      app --with --args 
    // 
    cmd_args args = get_args_to_run(argv);
    if (args_are_valid(args))
    {
        process p;
        if (!process_init(&p, args))
        {
            return -1;
        }
        if (!process_run_async(&p))
        {
            return -1;
        }
        if (!process_wait(&p))
        {
            return -1;
        }
    }

    (void)argc;
    bool show_gui = true;

    // Parse arguments.
    while (argv && *argv)
    {
        if (LITERAL_STREQUAL(*argv, "--no-gui"))
        {
            show_gui = false;
        }
        argv += 1;
    }

    if (show_gui)
    {
        gui g;
        return g.show();
    }

    return 0;
}

#if _WIN32

cmd_args get_args_to_run(char** argv)
{
    /* Search the first occurrence of the wide character string. Return null if not found. */
    wchar_t* cursor = wcswcs(GetCommandLineW(), L"--run");

    /* Skip --run */
    cursor += wcslen(L"--run"); 

    /* Skip leading whitespace. */
    while (cursor && iswspace(*cursor))
    {
        cursor += 1;
    }

    return cursor;
}

#else
#error "get_args_to_run not supported yet"
#endif