#ifndef SAMPLY_GUI_H
#define SAMPLY_GUI_H

#include "utils/file_mapper.h"
#include "report.h" // record_range

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

	record_range records_of_current_file;

	gui(struct sampler* s, struct report* r);
	~gui();

	static strv backend_identifier();

	// Return exit code
	int show();

	// Display our application
	int main();

	bool open_file(strv filepath);
	
	// Open the specified file if it's not already opened and jump to the specified line.
	void jump_to_file(strv filepath, size_t line);

private:

	void show_main_menu_bar();
	void show_about_window(bool* p_open);
};

#endif // SAMPLY_GUI_H
