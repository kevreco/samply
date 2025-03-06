#ifndef SAMPLY_GUI_H
#define SAMPLY_GUI_H

#include "text_viewer/text_viewer.hpp"

#include "utils/file_mapper.h"
#include "report.h" // record_range

struct sampler;

struct gui {

	static const int max_command_line_char = 8191;
	static const int max_command_line_buffer_char = max_command_line_char + 1;

	char command_line_buffer[max_command_line_buffer_char] = {0};

	sampler* sampler = 0;
	report* report = 0;

	// Context to open and close (mmapped) readonly files
	file_mapper file_mapper;

	// Reference to the current opened filepath
	strv current_opened_filepath;

	// Current opened file
	readonly_file current_file;

	record_range records_of_current_file;

	struct config {

		// Help - Debug
		//
		bool open_main_window_full_screen = true;
		bool open_imgui_demo_window = false;
		bool open_text_viewer_demo_window = false;

		// About
		//
		bool open_about_window = false;

	} cfg;

	tv::text_viewer text_viewer;

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

	void set_command_line_text(strv command_line);
	void set_command_line_from_args(cmd_args args);

private:

	//
	// Main Menu
	//

	void show_main_menu_bar();
	void show_about_window(bool* p_open);

	//
	// Main Window
	//

	void show_main_window();
	void display_main_window_header();
	void display_main_window_body();

	//
	// Main Window - Report Tab
    //

	void show_report_tab();

	void show_report_grid();

	void show_source_file();
};

#endif // SAMPLY_GUI_H
