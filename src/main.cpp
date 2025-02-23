#include "gui/gui.hpp"

#include "string.h"
#include "stdio.h"

#include "process.h"
#include "sampler.h"
#include "report.h"

#define LITERAL_STREQUAL(str, literal_str) (strncmp(str, literal_str, sizeof(literal_str) - 1) == 0)

cmd_args get_args_to_run(char** argv);
bool run_process(process* p, sampler* s, report* report);

int main(int argc, char** argv)
{
    string_store store;
    string_store_init(&store);
    sampler s;
    sampler_init(&s, &store);
    report report;
    report_init(&report, &store);

    int exit_code = 0;
    bool no_subprocess_error = true;
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
        if (process_init(&p, args))
        {
            no_subprocess_error = run_process(&p, &s, &report);

            process_destroy(&p);
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
        gui g = { &s, &report };

        // @TODO do not return since resources must be destroyed.
        exit_code = g.show();
    }

    sampler_destroy(&s);
    report_destroy(&report);
    string_store_destroy(&store);

    if ( !no_subprocess_error )
    {
        exit_code = 1;
    }

    return exit_code;
}

#if _WIN32

cmd_args get_args_to_run(char** argv)
{
    (void)argv;

    /* Search the first occurrence of the wide character string. Return null if not found. */
    wchar_t* cursor = wcswcs(GetCommandLineW(), L"--run");

    if (cursor != NULL)
    {
        /* Skip --run */
        cursor += wcslen(L"--run");

        /* Skip leading whitespace. */
        while (cursor && iswspace(*cursor))
        {
            cursor += 1;
        }
    }

    return cursor;
}

#else
#error "get_args_to_run not supported yet"
#endif

bool run_process(process* p, sampler* s, report* report)
{
    if (!process_run_async(p))
    {
        return false;
    }

    sampler_task task = { 0 };
    task.process = p;
    sampler_run(s, &task);

    if (!process_wait(p))
    {
        return false;
    }
    sampler_stop(s);
    /* Load report from sampler. */
    report_load_from_sampler(report, s);

    /* Display report in std output. */
    report_print_to_file(report, stdout);

#if 0 /* To test if save/load from/to a file is working. */

    /* Re-display data in std output to check if they actually match. */
    if (!report_save_to_filepath(report, "test.bin"))
    {
        return false;
    }

    if (!report_load_from_filepath(report, "test.bin"))
    {
        return false;
    }
    /* Should display the same text as the first "print_to_file" above. */
    report_print_to_file(report, stdout);

#endif

    return true;
}