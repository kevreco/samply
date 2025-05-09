#include "gui/gui.hpp"

#include "string.h"
#include "stdio.h"

#include "process.h"
#include "sampler.h"
#include "report.h"

#define LITERAL_STREQUAL(str, literal_str) (strncmp(str, literal_str, sizeof(literal_str) - 1) == 0)

cmd_args get_args_to_run(char** argv);
bool run_process(process* p, sampler* s);

int main(int argc, char** argv)
{
    (void)argc;
    sampler s;
    sampler_init(&s);
    report report;
    report_init(&report);

    int exit_code = 0;
    bool no_subprocess_error = true;

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
        if (process_init_with_args(&p, args))
        {
            no_subprocess_error = run_process(&p, &s);

            /* Report */
            {
                /* Load report from sampler. */
                report_load_from_sampler(&report, &s);

                /* If GUI is displayed no need to display thge report in the console. */
                if (!show_gui)
                {
                    /* Display report in std output. */
                    report_print_to_file(&report, stdout);

/* To test if save/load from/to a file is working. */
#if 0 

                    /* Re-display data in std output to check if they actually match. */
                    if (!report_save_to_filepath(&report, "test.bin"))
                    {
                        return false;
                    }

                    if (!report_load_from_filepath(&report, "test.bin"))
                    {
                        return false;
                    }
                    /* Should display the same text as the first "print_to_file" above. */
                    report_print_to_file(&report, stdout);

#endif
                }
            }
            process_destroy(&p);
        }
    }

    if (show_gui)
    {
        gui g = { &s, &report };

        g.set_command_line_from_args(args);
        
        exit_code = g.show();
    }

    sampler_destroy(&s);
    report_destroy(&report);

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

bool run_process(process* p, sampler* s)
{
    if (!process_run_async(p))
    {
        return false;
    }

    sampler_run(s, p);

    if (!process_wait(p))
    {
        return false;
    }
    sampler_stop(s);
   
    return true;
}