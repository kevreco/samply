#ifndef SAMPLY_GUI_BACKEND_HPP
#define SAMPLY_GUI_BACKEND_HPP

#include "samply.h"

struct gui_backend
{
	int initial_x = 100;
	int initial_y = 100;
	int initial_width = 720;
	int initial_height = 540;

	// String to identify which backend is being used.
	strv identifier();

	void set_initial_position(int x, int y);
	void set_initial_size(int width, int height);

	// Return exit code
	int show();

	// Return exit code
	virtual int show_core() = 0;
};

#endif // SAMPLY_GUI_BACKEND_HPP
