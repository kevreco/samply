#ifndef SAMPLY_GUI_H
#define SAMPLY_GUI_H

#include "utils/file_mapper.h"

struct sampler;
struct report;

struct gui {

	sampler* sampler = 0;
	report* report = 0;

	// Context to open and close (mmapped) readonly files
	file_mapper file_mapper;
	// Reference to the current opened filepath
	strv current_opened_filepath;
	// Current opened file
	readonly_file current_file;

	struct {
		size_t line_to_go;
	} commands;

	gui(struct sampler* s, struct report* r);
	~gui();

	// Return exit code
	int show();

	// Display our application
	int main();

	void open_file(strv filepath);
	void goto_line(strv filepath, size_t line);
};

#endif // SAMPLY_GUI_H
