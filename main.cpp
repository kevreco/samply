#include "gui/gui.hpp"

#include "string.h"

#define LITERAL_STREQUAL(str, literal_str) (strncmp(str, literal_str, sizeof(literal_str) - 1) == 0)

int main(int argc, char** argv)
{
    (void)argc;
    bool show_gui = false;

    // Parse arguments.
    while (argv && *argv)
    {
        if (LITERAL_STREQUAL(*argv, "--gui"))
        {
            show_gui = true;
        }
        argv += 1;
    }

    gui g;
    
    return g.show();
}