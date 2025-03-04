#pragma once

#include <string>

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
		int size;

		string_view()
		{
			data = 0;
			size = 0;
		}

		string_view(const char* d, int s)
		{
			data = d;
			size = s;
		}

		string_view(const char* start, const char* end)
		{
			data = start;
			size = (int)(end - start);
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

		static const int column_int_max = INT_MAX;
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

	typedef void (*line_prelude_renderer)(struct options* options, int line_number, int visible_line_max, bool line_is_selected);

	void render_text_line(const char* begin, const char* end, const char* label = NULL, ImU32 foreground_color = 0, ImU32 background_color = 0, int flags = 0);
	void default_line_prelude_renderer(struct options* options, int line_number, int visible_line_max, bool line_is_selected);

	struct options {
		// Allow some operation like text copy.
		bool allow_keyboard_inputs = true;

		// Allow text selection.
		bool allow_mouse_inputs = true;

		// Call 'line_prelude' right before rendering a line.
		bool display_line_prelude = true;

		// Highlight selected text.
		bool display_text_selection = true;

		bool display_line_number = true;

		bool display_cursor = true;

		// Display various information useful to debug the selection.
		bool debug_mode = false;

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

	// Get line count of current text.
	// NOTE: this value is updated only when the text is rendered at least once.
	int get_text_line_count() const;

	string_view get_selected_line_text() const;

	coord get_cursor_position() const;
	void set_cursor_position(coord pos);

	// The selection is stored non-normalized, the begining before the end,
	// However. the 'get_selection_range' always returns a normalize range.
	coord_range get_selection_range() const;

	void set_selection_start(coord pos, bool update_anchor_column = false);
	void set_selection_end(coord pos);
	void set_selection(coord start, coord end, bool update_anchor_column = false);

	void select_all();
	bool has_selection() const;

	void copy_selection() const;

	int get_selected_line_number() const;
	int line_number_to_line_index(int line_number) const;
	int line_index_to_line_number(int line_index) const;

	// Next time the viewer is rendered, scroll to line number displayed in the viewer.
	void request_scroll_to_line_number(int line_number);
	// Next time the viewer is rendered, scroll to the 0-based index.
	void request_scroll_to_line_index(int line_index);

	coord cursor_translated_x(int delta);

	// Get coordinate as if the cursor position is moving up or down by 'delta' number of line.
	// 'delta' can be positive or negative.
	coord cursor_translated_y(int delta);

private:

	struct line {
		string_view text;
		mutable int cached_ut8_char_count = 0;

		const char* line_ending = 0;

		line(string_view txt, const char* line_ending)
		{
			this->text = txt;
			this->line_ending = line_ending;
		}

		int get_utf8_char_count() const;
	};

	bool need_to_split_text() const;
	void split_text();

	void render_core();

	// Get distance from line start to character at pos. Stop at the last text char.
	float text_distance_from_line_start(coord pos) const;
	// Get column index from distance
	int text_distance_to_column_index(string_view view, float distance) const;

	coord sanitize_coord(coord value) const;

	coord get_anchor_cursor() const;

	coord screen_pos_to_coord(const ImVec2& pos) const;

	int max_visible_line_per_page() const;

	// Get substring withing a line.
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

	ImVector<line> lines;

	coord_range selection;
	int anchor_column = 0;
	// Only used to know when the current selection changed.
	coord previous_cursor_position; 

	bool text_changed;

	// Screen position of the start of the text.
	float text_margin_x = 0.0f;

	ImVec2 window_pos;
	ImVec2 window_scroll;
	ImVec2 window_padding;
	ImVec2 graphical_char_size;

	float last_click_time;

	// Certain operation can only be done after the first text rendering.
	// Instead of keeping tack of text changes we use a "frame stamp"
	// and execute the request on the following frame;
	unsigned int frame_stamp = 0;

	struct scroll_request {
		int line = -1;
		int frame_stamp = 0;

		void set(int line_index, unsigned int frame) { line = line_index; frame_stamp = frame; }
		void clear() { line = -1; }
		bool should_go_to_line(unsigned int frame) const { return line >= 0 && frame_stamp != frame; }
	} scroll_request;

public:

	options options;
};

void show_demo_window(bool* p_open);

}