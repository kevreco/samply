#pragma once

#include <string>
#include <vector>

#define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui.h"

// Types 
namespace tv
{

// Helpers to print string view like:
//     fprintf(TV_SV_FMT, TV_SV_ARG(my_string_view))
#define TV_SV_FMT "%.*s"
#define TV_SV_ARG(sv) (int)(sv).size , (sv).data

	struct string_view
	{
		const char* data;
		size_t size;

		string_view()
		{
			data = 0;
			size = 0;
		}

		string_view(const char* d, size_t s)
		{
			data = d;
			size = s;
		}

		const char* begin()  const { return data; }
		const char* end()    const { return data + size; }
	};

	// Represents a character coordinate from the user's point of view,
	// i. e. consider an uniform grid (assuming fixed-width font) on the
	// screen as it is rendered, and each cell has its own coordinate, starting from 0.
	struct coord
	{
		int line;
		int column;

		coord() : line(0), column(0) {}
		coord(int l, int col) : line(l), column(col)
		{
			assert(l >= 0);
			assert(col >= 0);
		}

		bool equals(coord o) const
		{
			return line == o.line && column == o.column;
		}

		bool operator ==(coord o) const { return equals(o); }
		bool operator !=(coord o) const { return !equals(o); }

		bool operator <(coord o) const
		{
			if (line != o.line)
				return line < o.line;
			return column < o.column;
		}

		bool operator >(coord o) const
		{
			if (line != o.line)
				return line > o.line;
			return column > o.column;
		}

		bool operator <=(coord o) const
		{
			if (line != o.line)
				return line < o.line;
			return column <= o.column;
		}

		bool operator >=(coord o) const
		{
			if (line != o.line)
				return line > o.line;
			return column >= o.column;
		}
	};

	struct coord_range
	{
		coord start;
		coord end;

		coord_range()
		{
		}

		coord_range(coord left, coord right)
		{
			start = left;
			end = right;
		}
	};

	typedef void (*line_prelude_renderer)(struct options* options, int line_number, bool line_is_selected);

	void default_line_prelude_renderer(struct options* options, int line_number, bool line_is_selected);

	struct options {
		// Allow some operation like text copy.
		bool allow_keyboard_inputs = true;

		// Allow text selection.
		bool allow_mouse_inputs = true;

		// Call 'line_prelude' right before rendering a line.
		bool display_line_prelude = true;

		// Highlight selected text.
		bool display_text_selection = true;

		// Display rectangle over the selected line.
		bool display_line_selection = true;

		bool display_line_number = true;

		// Render something before displaying the line text.
		line_prelude_renderer line_prelude = default_line_prelude_renderer;
		// User data to use in the line_prelude_renderer.
		void* line_prelude_user_data = 0;
	};
}

// text_viewer
namespace tv
{

struct text_viewer
{
	text_viewer();
	~text_viewer() {}

	void render();
	void set_text(string_view text);
	string_view get_text() const;
	std::string get_text(coord start, coord end) const;
	std::string get_selected_text() const;
	std::string get_selected_line_text() const;

	coord get_cursor_position() const;
	void set_cursor_position(coord pos);

	coord_range get_selection_range() const;

	void set_selection_start(coord pos);
	void set_selection_end(coord pos);
	void set_selection(coord start, coord end);
	void select_all();
	bool has_selection() const;

	void copy_selection() const;

	size_t get_selected_line_number() const;
	size_t line_number_to_line_index(size_t line_number) const;
	size_t line_index_to_line_number(size_t line_index) const;

	// Next time the viewer is rendered, scroll to line number displayed in the viewer.
	void scroll_to_line_number(size_t line_number);
	// Next time the viewer is rendered, scroll to the 0-based index.
	void scroll_to_line_index(size_t line_index);

private:

	struct line {
		string_view text;
		mutable size_t cached_ut8_char_count = 0;

		const char* line_ending = 0;

		line(string_view txt, const char* line_ending)
		{
			this->text = txt;
			this->line_ending = line_ending;
		}

		size_t get_utf8_char_count() const;
	};

	bool need_to_split_text() const;
	void split_text();

	void render_core();

	// Get distance from line start to character at pos. Stop at the last text char.
	float text_distance_from_line_start(coord pos) const;
	// Get column index from distance
	int text_distance_to_column_index(string_view view, float distance) const;

	coord get_actual_cursor_coord() const;
	coord sanitize_coord(coord value) const;

	coord screen_pos_to_coord(const ImVec2& pos) const;
	
	string_view get_substring(int line_index, int column_index_first, int column_index_last) const;
	string_view get_text_of_line_after(coord pos) const;
	string_view get_text_of_line_before(coord pos) const;
	
	// This work like "select word on char" but with different categories (alnum, separators, space, others), not just alnum.
	// @FIXME: Multi-byte char (UTF-8) are considered "others" but it should be properly handled.
	coord_range get_range_of_same_char_at(coord value) const;

	const char* get_byte_ptr_at(coord value) const;

	int get_character_index(coord value) const;
	int get_line_character_count(int index) const;
	int get_line_column_length(int index) const;

	void handle_keyboard_inputs();
	void handle_mouse_inputs();

	string_view current_text;

	std::vector<line> lines;

	struct editor_state {
		coord_range selection;
		coord cursor_position;
	} state;

	bool text_changed;

	// Position (in pixels) where a code line starts relative
	// to the left of window containingthe text viewer.
	float text_margin;

	ImVec2 window_pos;
	ImVec2 window_scroll;
	ImVec2 graphical_char_size;

	// To keep track of mouse selection gesture.
	coord mouse_start_pos;

	float last_click_time;
	
	bool need_to_scroll = false;
	size_t line_to_scroll_to = 0;

public:

	options options;
};

void show_demo_window(bool* p_open);

}