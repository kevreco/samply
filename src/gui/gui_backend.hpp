#ifndef SAMPLY_GUI_BACKEND_HPP
#define SAMPLY_GUI_BACKEND_HPP

#include "samply.h"

struct gui_backend
{
	// String to identify which backend is being used.
	strv identifier();

	// Return exit code
	int show();

	// Return exit code
	virtual int show_core() = 0;
};

#endif // SAMPLY_GUI_BACKEND_HPP
