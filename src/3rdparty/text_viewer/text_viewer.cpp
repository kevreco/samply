#include <cmath>

#include "text_viewer.hpp"

#include "imgui.h"
#include "imgui_internal.h"

namespace tv {

static const char* line_ending_N = "\n";
static const char* line_ending_R = "\r";
static const char* line_ending_RN = "\r\n";
static const char* line_ending_NONE = "";

struct line_splitter {

	string_view view;
	const char* cursor;
	const char* end;

	line_splitter(string_view v) : view(v)
	{
		cursor = view.data;
		end = view.data + view.size;
	}

	const char* get_next_line(string_view* line)
	{
		const char* start = cursor;

		while (cursor < end)
		{
			switch (*cursor)
			{
			case '\r':
				*line = string_view(start, cursor - start);

				if (cursor + 1 < end && cursor[1] == '\n')
				{
					cursor += 2;
					return line_ending_RN;
				}
				else
				{
					cursor += 1;
					return line_ending_R;
				}
			case '\n':
			{
				*line = string_view(start, cursor - start);
				cursor += 1;
				return line_ending_N;
			}
			default:
				cursor += 1;
				break;
			}
		}

		if (cursor - start > 0)
		{
			*line = string_view(start, cursor - start);
			return line_ending_NONE;
		}

		return NULL;
	}
};

static void render_line_number(const char* label);
static size_t utf8_char_count(const char* str, size_t n);
static const char* utf8_goto_previous_codepoint(const char* const begin, const char* cursor);
static const char* utf8_goto_next_codepoint(const char* const cursor, const char* const end);

void default_line_prelude_renderer(struct options* options, int line_number, bool line_is_selected)
{
	if (options->display_line_number)
	{
		if (!line_is_selected)
		{
			ImGui::BeginDisabled();
		}

		char line_num_buf[64];
		snprintf(line_num_buf, 64, "%05d", line_number);

		render_line_number(line_num_buf);

		ImGui::SameLine();

		if (!line_is_selected)
		{
			ImGui::EndDisabled();
		}
	}
}
size_t text_viewer::line::get_utf8_char_count() const
{
	if (!cached_ut8_char_count && text.size)
	{
		cached_ut8_char_count = utf8_char_count(this->text.data, this->text.size);
	}
	return cached_ut8_char_count;
}

text_viewer::text_viewer()
	: current_text()
	, text_changed(false)
	, text_margin(10.0f)
	, last_click_time(-1.0f)
{
}

void text_viewer::render()
{
	text_changed = false;

	ImGuiWindow* window = ImGui::GetCurrentWindow();
	window_pos = window->Pos;
	window_scroll = window->Scroll;

	if (need_to_split_text())
	{
		split_text();
	}

	if (options.allow_keyboard_inputs)
	{
		handle_keyboard_inputs();
		ImGui::PushAllowKeyboardFocus(true);
	}

	if (options.allow_mouse_inputs)
	{
		handle_mouse_inputs();
	}

	render_core();

	if (options.allow_keyboard_inputs)
	{
		ImGui::PopAllowKeyboardFocus();
	}
}

void text_viewer::set_text(string_view text)
{
	current_text = text;

	text_changed = true;
}

string_view text_viewer::get_text() const
{
	return current_text;
}

std::string text_viewer::get_text(coord start, coord end) const
{
	assert(end >= start);

	std::string result;
	if (start == end)
		return std::string();

	int line_count = (end.line - start.line);

	// Copy content in between on the same line.
	if (line_count == 0)
	{
		string_view sv = get_substring(start.line, start.column, end.column);
		result.insert(result.size(), sv.data, sv.size);
	}
	// Copy first chunk of the first line, then copy second chunk of the last line.
	else if (line_count > 0)
	{
		// Upper end of selection of the first line 
		string_view sv = get_text_of_line_after(start);

		result.insert(result.size(), sv.data, sv.size);
		result += lines[start.line].line_ending;

		if (line_count >= 2)
		{
			// For all line in between the first and the last copy the full line.
			for (size_t i = start.line + 1; i < end.line; i += 1)
			{
				result.insert(result.size(), lines[i].text.data, lines[i].text.size);

				result += lines[i].line_ending;
			}
		}

		// Get Lower end of selection of the last line 
		sv = get_text_of_line_before(end);

		result.insert(result.size(), sv.data, sv.size);
	}

	return result;
}

std::string text_viewer::get_selected_text() const
{
	return get_text(state.selection.start, state.selection.end);
}

std::string text_viewer::get_selected_line_text() const
{
	auto lineLength = get_line_column_length(state.cursor_position.line);
	return get_text(
		coord(state.cursor_position.line, 0),
		coord(state.cursor_position.line, lineLength));
}

coord text_viewer::get_cursor_position() const
{
	return get_actual_cursor_coord();
}

void text_viewer::set_cursor_position(coord pos)
{
	if (state.cursor_position != pos)
	{
		state.cursor_position = pos;
	}
}

coord_range text_viewer::get_selection_range() const
{
	return state.selection;
}

void text_viewer::set_selection_start(coord pos)
{
	state.selection.start = sanitize_coord(pos);

	if (state.selection.start > state.selection.end)
	{
		std::swap(state.selection.start, state.selection.end);
	}
}

void text_viewer::set_selection_end(coord pos)
{
	state.selection.end = sanitize_coord(pos);

	if (state.selection.start > state.selection.end)
	{
		std::swap(state.selection.start, state.selection.end);
	}
}

void text_viewer::set_selection(coord start, coord end)
{
	state.selection.start = sanitize_coord(start);
	state.selection.end = sanitize_coord(end);
	if (state.selection.start > state.selection.end)
		std::swap(state.selection.start, state.selection.end);
}

void text_viewer::select_all()
{
	set_selection(coord(0, 0), coord((int)lines.size(), 0));
}

bool text_viewer::has_selection() const
{
	return state.selection.start < state.selection.end;
}

void text_viewer::copy_selection()
{
	if (has_selection())
	{
		ImGui::SetClipboardText(get_selected_text().c_str());
	}
	else
	{
		if (!lines.empty())
		{
			std::string str;
			auto& line = lines[get_actual_cursor_coord().line];

			str.insert(str.size(), line.text.data, line.text.size);

			ImGui::SetClipboardText(str.c_str());
		}
	}
}


bool text_viewer::need_to_split_text() const
{
	return current_text.size || text_changed;
}

void text_viewer::split_text()
{
	lines.clear();

	line_splitter splitter{ current_text };

	string_view lineText;
	const char* line_ending;
	while ((line_ending = splitter.get_next_line(&lineText)) != NULL)
	{
		lines.push_back(line(lineText, line_ending));
	}
}

void text_viewer::render_core()
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();

	auto& style = ImGui::GetStyle();

	// Compute graphical_char_size regarding to scaled font size (Ctrl + mouse wheel)
	const float font_size = ImGui::GetFont()->CalcTextSizeA(ImGui::GetFontSize(), FLT_MAX, -1.0f, "#", nullptr, nullptr).x;
	graphical_char_size = ImVec2(font_size, ImGui::GetTextLineHeightWithSpacing());

	auto region_avail = ImGui::GetContentRegionAvail();
	auto draw_list = ImGui::GetWindowDrawList();

	ImVec2 cursor_screen_pos = ImGui::GetCursorScreenPos();

	auto scroll_y = ImGui::GetScrollY();

	auto line_number = (int)floor(scroll_y / graphical_char_size.y);

	ImVec2 line_selection_rect_min;
	ImVec2 line_selection_rect_max;

	ImGuiListClipper clipper;

	clipper.Begin(lines.size());

	while (clipper.Step())
	{
		for (int line_number = clipper.DisplayStart; line_number < clipper.DisplayEnd; line_number += 1)
		{
			auto& line = lines[line_number];

			bool line_is_selected = line_number == state.cursor_position.line;

			if (options.display_line_selection && line_is_selected)
			{
				line_selection_rect_min.y = ImGui::GetCursorScreenPos().y;
			}

			if (options.display_line_prelude)
			{
				options.line_prelude(&options, line_number, line_is_selected);
			}

			// Update text_margin according to the size of everything before that.
			// This is currently the line number display but there might be other custom items.
			text_margin = ImGui::GetCursorPos().x;

			{
				cursor_screen_pos.x = ImGui::GetCursorScreenPos().x;
				ImVec2 line_start_screen_pos = ImVec2(cursor_screen_pos.x, cursor_screen_pos.y + line_number * graphical_char_size.y);

				float selection_start = -1.0f;
				float selection_end = -1.0f;

				if (options.display_text_selection)
				{
					coord lineStartCoord(line_number, 0);
					coord lineEndCoord(line_number, get_line_column_length(line_number));

					assert(state.selection.start <= state.selection.end);
					if (state.selection.start <= lineEndCoord)
					{
						selection_start = state.selection.start > lineStartCoord ? text_distance_from_line_start(state.selection.start) : 0.0f;
					}

					if (state.selection.end > lineStartCoord)
					{
						selection_end = text_distance_from_line_start(state.selection.end < lineEndCoord ? state.selection.end : lineEndCoord);
					}

					if (state.selection.end.line > line_number)
					{
						selection_end += graphical_char_size.x;
					}
				}

				ImGui::Text(TV_SV_FMT, TV_SV_ARG(line.text));

				if (options.display_text_selection)
				{
					if (selection_start != -1 && selection_end != -1 && selection_start < selection_end)
					{
						ImVec2 selection_rect_min(line_start_screen_pos.x + selection_start, line_start_screen_pos.y);
						ImVec2 selection_rect_max(line_start_screen_pos.x + selection_end, line_start_screen_pos.y + graphical_char_size.y);
						draw_list->AddRectFilled(selection_rect_min, selection_rect_max, ImGui::GetColorU32(style.Colors[ImGuiCol_TextSelectedBg]));
					}
				}
			}

			// Save line selection rectangle
			if (options.display_line_selection && line_is_selected)
			{
				line_selection_rect_min.x = window->ParentWorkRect.Min.x;
				line_selection_rect_max.x = window->ParentWorkRect.Max.x;
				line_selection_rect_max.y = ImGui::GetCursorScreenPos().y;
			}
		}

		if (options.display_line_selection)
		{
			if (line_selection_rect_max.y - line_selection_rect_min.y > 0.0f)
			{
				// Draw after the loop since we want the selection to be on top of all other drawing
				draw_list->AddRect(line_selection_rect_min, line_selection_rect_max, ImGui::GetColorU32(style.Colors[ImGuiCol_ButtonActive]));
			}
		}
	}
}


float text_viewer::text_distance_from_line_start(coord pos) const
{
	auto& line = lines[pos.line];

	const char* start = line.text.data;
	const char* cursor = line.text.data;
	const char* end = line.text.data + line.text.size;

	ImGuiContext* ctx = ImGui::GetCurrentContext();

	int i = 0;
	int colIndex = get_character_index(pos);
	float distance = 0.0f;

	while (cursor < end && i < colIndex)
	{
		unsigned int c;
		cursor += ImTextCharFromUtf8(&c, cursor, end);

		distance += ctx->Font->GetCharAdvance((ImWchar)c) * ctx->FontScale;

		i++;
	}

	return distance;
}

int text_viewer::text_distance_to_column_index(string_view view, float distance) const
{
	const char* begin = view.data;
	const char* end = view.data + view.size;
	float result = 0;
	bool found = false;
	ImGuiContext* ctx = ImGui::GetCurrentContext();

	int charCount = 0;
	float currentX = 0.0f;
	while (begin < end && !found)
	{
		unsigned int c;
		begin += ImTextCharFromUtf8(&c, begin, end);

		float advance = ctx->Font->GetCharAdvance((ImWchar)c) * ctx->FontScale;

		if (currentX + (advance * 0.5f) > distance)
			return charCount;
		currentX += advance;
		charCount += 1;
	}
	return charCount;
};

coord text_viewer::get_actual_cursor_coord() const
{
	return sanitize_coord(state.cursor_position);
}

coord text_viewer::sanitize_coord(coord value) const
{
	auto line = value.line;
	auto column = value.column;
	if (line >= (int)lines.size())
	{
		if (lines.empty())
		{
			line = 0;
			column = 0;
		}
		else
		{
			line = (int)lines.size() - 1;
			column = get_line_column_length(line);
		}
		return coord(line, column);
	}
	else
	{
		column = lines.empty() ? 0 : std::min(column, get_line_column_length(line));
		return coord(line, column);
	}
}

coord text_viewer::screen_pos_to_coord(const ImVec2& screen_pos) const
{
	// Local pos relative to the parent window or child window.
	ImVec2 local_pos(screen_pos - window_pos + window_scroll);

	int line_index = std::max(0, (int)floor(local_pos.y / graphical_char_size.y));

	int column_index = 0;

	if (line_index >= 0 && line_index < (int)lines.size())
	{
		auto& line = lines.at(line_index);

		column_index = text_distance_to_column_index(line.text, local_pos.x - text_margin);
	}

	return sanitize_coord(coord(line_index, column_index));
}

string_view text_viewer::get_substring(int line_index, int column_index_first, int column_index_last) const
{
	assert(column_index_first <= column_index_last);

	auto& text = lines[line_index].text;

	const char* cursor = text.data;
	const char* end = text.data + text.size;

	/* Skip every until the first index */
	int i = 0;
	while (cursor < end && i < column_index_first)
	{
		unsigned int c;
		cursor += ImTextCharFromUtf8(&c, cursor, end);

		i += 1;
	}

	const char* lower = cursor;

	// Advance until last char
	while (cursor < end && i < column_index_last)
	{
		unsigned int c;
		cursor += ImTextCharFromUtf8(&c, cursor, end);

		i += 1;
	}

	return string_view(lower, cursor - lower);
}

string_view text_viewer::get_text_of_line_after(coord pos) const
{
	auto& text = lines[pos.line].text;
	const char* cursor = text.data;
	const char* end = text.data + text.size;

	int i = 0;
	while (cursor < end && i < pos.column)
	{
		unsigned int c;
		cursor += ImTextCharFromUtf8(&c, cursor, end);

		i += 1;
	}

	return string_view(cursor, end - cursor);
}

string_view text_viewer::get_text_of_line_before(coord pos) const
{
	auto& text = lines[pos.line].text;
	const char* cursor = text.data;
	const char* end = text.data + text.size;

	int i = 0;
	while (cursor < end && i < pos.column)
	{
		unsigned int c;
		cursor += ImTextCharFromUtf8(&c, cursor, end);

		i += 1;
	}

	return string_view(text.data, cursor - text.data);
}

coord_range text_viewer::get_range_of_same_char_at(coord value) const
{
	typedef bool(*predicate)(int c);
	struct local
	{
		static bool is_alnum(int c) { return isalnum(c); };
		static bool is_space(int c) { return isspace(c); };
		static bool is_punct(int c) { return ispunct(c); };
		static bool is_other(int c) { return !isalnum(c) && !isspace(c) && !ispunct(c); };

		static predicate get_type_func(int c)
		{
			if (is_alnum(c))
				return is_alnum;
			if (is_space(c))
				return is_space;
			else if (is_punct(c))
				return is_punct;
			else
				return is_other;
		}
	};

	coord_range range(value, value);

	string_view text = lines[value.line].text;
	const char* begin = text.data;
	const char* end = text.data + text.size;
	
	const char* char_at = get_byte_ptr_at(value);

	if (char_at >= end)
	{
		return range;
	}

	predicate is_type = local::get_type_func(char_at[0]);

	const char* cursor = char_at;
	// Get range on the left
	while (cursor - 1 >= begin && is_type(cursor[-1]) && range.start.column > 0)
	{
		cursor = utf8_goto_previous_codepoint(begin, cursor);
		range.start.column -= 1;
	}

	cursor = char_at;

	// Get range on the right
	while (cursor < end && is_type(cursor[0]))
	{
		cursor = utf8_goto_next_codepoint(cursor, end);
		range.end.column += 1;
	}

	return range;
}

const char* text_viewer::get_byte_ptr_at(coord value) const
{
	auto& text = lines[value.line].text;

	const char* cursor = text.data;
	const char* end = text.data + text.size;

	int i = 0;
	while (cursor < end && i < value.column)
	{
		cursor = utf8_goto_next_codepoint(cursor, end);
		i += 1;
	}

	return cursor;
}

int text_viewer::get_character_index(coord pos) const
{
	if (pos.line >= lines.size())
		return -1;

	auto& line = lines[pos.line];

	return std::min(line.get_utf8_char_count(), (size_t)pos.column);
}

int text_viewer::get_line_character_count(int index) const
{
	if (index >= lines.size())
		return 0;

	return lines[index].get_utf8_char_count();
}

int text_viewer::get_line_column_length(int index) const
{
	if (index >= lines.size())
		return 0;

	return lines[index].get_utf8_char_count();
}

void text_viewer::handle_keyboard_inputs()
{
	ImGuiIO& io = ImGui::GetIO();
	auto shift = io.KeyShift;
	auto ctrl = io.ConfigMacOSXBehaviors ? io.KeySuper : io.KeyCtrl;
	auto alt = io.ConfigMacOSXBehaviors ? io.KeyCtrl : io.KeyAlt;

	if (ImGui::IsWindowFocused())
	{
		if (ImGui::IsWindowHovered())
			ImGui::SetMouseCursor(ImGuiMouseCursor_TextInput);
		//ImGui::CaptureKeyboardFromApp(true);

		io.WantCaptureKeyboard = true;
		io.WantTextInput = true;

		if (ctrl && !shift && !alt && ImGui::IsKeyPressed(ImGuiKey_Insert))
			copy_selection();
		else if (ctrl && !shift && !alt && ImGui::IsKeyPressed(ImGuiKey_C))
			copy_selection();
		else if (ctrl && !shift && !alt && ImGui::IsKeyPressed(ImGuiKey_A))
			select_all();
	}
}

void text_viewer::handle_mouse_inputs()
{
	ImGuiIO& io = ImGui::GetIO();
	auto shift = io.KeyShift;
	auto ctrl = io.ConfigMacOSXBehaviors ? io.KeySuper : io.KeyCtrl;
	auto alt = io.ConfigMacOSXBehaviors ? io.KeyCtrl : io.KeyAlt;

	if (ImGui::IsWindowHovered())
	{
		if (!shift && !alt)
		{
			auto left_click = ImGui::IsMouseClicked(ImGuiMouseButton_Left);
			auto left_double_click = ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left);
			auto t = ImGui::GetTime();
			auto left_triple_click = left_click
				&& !left_double_click
				&& (last_click_time != -1.0f
				&& (t - last_click_time) < io.MouseDoubleClickTime);

			// Left mouse button triple click
			if (left_triple_click)
			{
				if (!ctrl)
				{
					coord pos = screen_pos_to_coord(ImGui::GetMousePos());
					state.cursor_position = pos;
					mouse_start_pos = pos;

					// Select whole line
					coord line_start(mouse_start_pos.line, 0);
					coord line_end(mouse_start_pos.line, get_line_column_length(mouse_start_pos.line));
					
					set_selection(line_start, line_end);
				}

				last_click_time = -1.0f;
			}
			//Left mouse button double click
			else if (left_double_click)
			{
				if (!ctrl)
				{
					coord pos = screen_pos_to_coord(ImGui::GetMousePos());
					state.cursor_position = pos;
					mouse_start_pos = pos;

					coord_range r = get_range_of_same_char_at(pos);

					set_selection(r.start, r.end);
				}

				last_click_time = (float)ImGui::GetTime();
			}
			// Left mouse button click
			else if (left_click)
			{
				coord pos = screen_pos_to_coord(ImGui::GetMousePos());
				state.cursor_position = pos;
				mouse_start_pos = pos;

				coord_range r(mouse_start_pos, mouse_start_pos);
				if (ctrl)
				{
					r = get_range_of_same_char_at(pos);
				}
				set_selection(r.start, r.end);

				last_click_time = (float)ImGui::GetTime();
			}
			// Mouse left button dragging (=> update selection)
			else if (ImGui::IsMouseDragging(0) && ImGui::IsMouseDown(0))
			{
				io.WantCaptureMouse = true;
				coord pos = screen_pos_to_coord(ImGui::GetMousePos());
				state.cursor_position = pos;
				coord_range r(mouse_start_pos, pos);
				set_selection(r.start, r.end);
			}
		}
	}
}

static void render_line_number(const char* label)
{
	auto& style = ImGui::GetStyle();
	ImGuiWindow* window = ImGui::GetCurrentWindow();
	ImVec2 size_arg = ImVec2(0, 0);

	// Submit label or explicit size to ItemSize(), whereas ItemAdd() will submit a larger/spanning rectangle.
	ImGuiID id = window->GetID(label);
	ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);
	ImVec2 size = ImGui::CalcItemSize(size_arg, label_size.x + style.FramePadding.x * 2.0f, label_size.y);
	ImVec2 pos = window->DC.CursorPos;
	pos.y += window->DC.CurrLineTextBaseOffset;

	ImRect bb(pos.x, pos.y, pos.x + size.x, pos.y + size.y);

	const float spacing_L = IM_TRUNC(style.ItemSpacing.x * 0.50f);
	const float spacing_U = IM_TRUNC(style.ItemSpacing.y * 0.50f);

	bb.Translate(ImVec2(-spacing_L, -spacing_U));
	bb.Max += style.ItemSpacing;

	ImGui::ItemSize(size, 0);
	if (!ImGui::ItemAdd(bb, id))
	{
		return;
	}

	ImU32 col = ImGui::GetColorU32(ImGuiCol_WindowBg);
	ImGui::RenderFrame(bb.Min, bb.Max, col, false, 0.0f);

	ImGui::RenderTextClipped(bb.Min + style.FramePadding, bb.Max - style.FramePadding, label, NULL, &label_size, style.ButtonTextAlign, &bb);
}

static size_t utf8_char_count(const char* str, size_t n)
{
	const char* t = str;
	size_t length = 0;

	while ((size_t)(str - t) < n && '\0' != *str) {
		if (0xf0 == (0xf8 & *str)) {
			/* 4-byte utf8 code point (began with 0b11110xxx) */
			str += 4;
		}
		else if (0xe0 == (0xf0 & *str)) {
			/* 3-byte utf8 code point (began with 0b1110xxxx) */
			str += 3;
		}
		else if (0xc0 == (0xe0 & *str)) {
			/* 2-byte utf8 code point (began with 0b110xxxxx) */
			str += 2;
		}
		else { /* if (0x00 == (0x80 & *s)) { */
			/* 1-byte ascii (began with 0b0xxxxxxx) */
			str += 1;
		}

		/* no matter the bytes we marched s forward by, it was
		 * only 1 utf8 codepoint */
		length++;
	}

	if ((size_t)(str - t) > n) {
		length--;
	}
	return length;
}

static const char* utf8_goto_previous_codepoint(const char* const begin, const char* cursor)
{
	while (cursor > begin)
	{
		cursor -= 1;
		if ((*cursor & 0xC0) != 0x80)
			return cursor;
	}
	return cursor;
}

static const char* utf8_goto_next_codepoint(const char* const cursor, const char* const end) {
	if (0xf0 == (0xf8 & cursor[0])) {
		/* 4 byte utf8 codepoint */
		return cursor + 4;
	}
	else if (0xe0 == (0xf0 & cursor[0])) {
		/* 3 byte utf8 codepoint */
		return cursor + 3;
	}
	else if (0xc0 == (0xe0 & cursor[0])) {
		/* 2 byte utf8 codepoint */
		return cursor + 2;
	}

	/* 1 byte utf8 codepoint otherwise */
	return cursor + 1;
}


} // namespace tv