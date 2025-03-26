#define CB_IMPLEMENTATION
#include "cb/cb.h"
#include "cb/cb_add_files.h"
#include "cb/cb_assert.h"

/* Forward declarations */

static const char* build_with(const char* config);
static void my_project(const char* project_name, const char* toolchain, const char* config);

/* Main */

int main()
{
    cb_init();

    build_with("Release");

    cb_clear(); /* Clear all values of cb. */

    const char* ac_exe = build_with("Debug");

    cb_destroy();

    return 0;
}

/* Shortcut to create a project with default config flags. */
static void my_project(const char* project_name, const char* toolchain, const char* config)
{
    cb_project(project_name);

    cb_set_f(cb_OUTPUT_DIR, ".build/%s_%s/%s/", toolchain, config, project_name);

    cb_bool is_debug = cb_str_equals(config, "Debug");

    if (is_debug
        /* @FIXME sanitize=address require clang with msvc*/
        && cb_str_equals(toolchain, "gcc")
        )
    {
        cb_add(cb_CXFLAGS, "-fsanitize=address"); /* Address sanitizer, same flag for gcc and msvc. */
    }

    if (cb_str_equals(toolchain, "msvc"))
    {
        cb_add(cb_CXFLAGS, "/Zi");   /* Produce debugging information (.pdb) */

        /* Use alternate location for the .pdb.
           In this case it will be next to the .exe */
        cb_add(cb_LFLAGS, "/pdbaltpath:%_PDB%"); 

        cb_add(cb_DEFINES, "UNICODE");
        cb_add(cb_DEFINES, "_UNICODE");
            
        if (is_debug)
        {
            cb_add(cb_LFLAGS, "/MANIFEST:EMBED");
            cb_add(cb_LFLAGS, "/INCREMENTAL:NO"); /* No incremental linking */

            cb_add(cb_CXFLAGS, "-Od");   /* Disable optimization */
            cb_add(cb_DEFINES, "DEBUG"); /* Add DEBUG constant define */
        }
        else
        {
            cb_add(cb_CXFLAGS, "-O1");   /* Optimization level 1 */
        }
    }
    else if (cb_str_equals(toolchain, "gcc"))
    {
        if (is_debug)
        {
            cb_add(cb_CXFLAGS, "-g");    /* Produce debugging information  */
            cb_add(cb_CXFLAGS, "-p");    /* Profile compilation (in case of performance analysis)  */
            cb_add(cb_CXFLAGS, "-O0");   /* Disable optimization */
            cb_add(cb_DEFINES, "DEBUG"); /* Add DEBUG constant define */
            
        }
        else
        {
            cb_add(cb_CXFLAGS, "-O1");   /* Optimization level 1 */
        }
    }
}

static const char* build_with(const char* config)
{
    const char* toolchain_name = cb_toolchain_default().name;

    my_project("samply", toolchain_name, config);

    cb_set(cb_BINARY_TYPE, cb_EXE);

    cb_add_files_recursive("./src/", "*.c");
    cb_add_files_recursive("./src/", "*.cpp");

    cb_add_many_vnull(cb_INCLUDE_DIRECTORIES,
        "./src/",
        "./src/gui",
        "./src/3rdparty",
        "./src/3rdparty/imgui",
        "./src/3rdparty/imgui/backends",
        "./src/3rdparty/thread",
        NULL
    );

    cb_add_many_vnull(cb_LIBRARIES,
        "comdlg32",
        "Dbghelp",
        "gdi32",
        "kernel32",
        "opengl32",
        "shell32",
        "user32",
        "winspool",
        NULL
    );

    const char* exe = cb_bake();
    if (!exe)
    {
        exit(1);
    }

    return exe;
}