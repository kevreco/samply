#include "gui/gui.hpp"

#include "string.h"

#define LITERAL_STREQUAL(str, literal_str) (strncmp(str, literal_str, sizeof(literal_str) - 1) == 0)

int main(int argc, char** argv)
{
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