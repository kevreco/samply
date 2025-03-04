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
				*line = string_view(start, cursor);

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
				*line = string_view(start, cursor);
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
			*line = string_view(start, cursor);
			return line_ending_NONE;
		}

		return NULL;
	}
};

template<typename T> static inline T min(T left, T right) { return left < right ? left : right; }
template<typename T> static inline T max(T left, T right) { return left >= right ? left : right; }
template<typename T> static inline T clamp(T value, T min, T max) { return (value < min) ? min : (value > max) ? max : value; }

static int utf8_char_count(const char* str, int n);
static const char* utf8_goto_previous_codepoint(const char* const begin, const char* cursor);
static const char* utf8_goto_next_codepoint(const char* const cursor, const char* const end);

void default_line_prelude_renderer(struct options* options, int line_number, int visible_line_max, bool line_is_selected)
{
	if (options->display_line_number)
	{
		char buf[64];
		char line_format[16];
		// Format the line number format
		{
			int char_count = snprintf(buf, 64, "%d", visible_line_max);

			// Create a string like "%99d" which would display a number + leading padding equal to 99
			// Add 2 leading space padding by default and add a trailing space
			static const int leading_padding = 2;
			const char* trailing_space = " ";
			snprintf(line_format, 16, "%%" "%d" "d" "%s", char_count + leading_padding, trailing_space);
		}

		int size = snprintf(buf, 64, line_format, line_number);
		
		int background_color = line_is_selected ? ImGuiCol_ScrollbarGrab : ImGuiCol_WindowBg ;
		render_text_line(buf, buf + size, NULL, 0, ImGui::GetColorU32(background_color));
		ImGui::SameLine();
	}
}

// This item has been shaped like ImGui::Selectable.
// It allows to have an item with a bounding box than can expand to the available width.
// The text is vertically centered, and it correctly takes the item spacing into account.
// The default ImGui::Selectable could create an item which is position *before* the 
// CursorPosition, which made various computing close to impossible to perform.
// 
// Here are the possible flags:
//     - ImGuiSelectableFlags_Highlight :
//         This behavior changed compared to the original ImGui::Selectable,
//         Allow frame highligthing depending on wether the item is hovered, or "pushed" (mouse hover + mouse pressed).
//     - ImGuiSelectableFlags_Disabled : See ImGui documentation.
//     - ImGuiSelectableFlags_NoAutoClosePopups : See ImGui documentation.
// 
// Returns local window coordinate of the beginning of the text (top left)
void render_text_line(const char* begin, const char* end, const char* label, ImU32 foreground_color, ImU32 background_color, int flags)
{
	using namespace ImGui;

	ImGuiWindow* window = GetCurrentWindow();
	if (window->SkipItems)
	{
		return;
	}

	ImGuiContext& g = *GImGui;
	const ImGuiStyle& style = g.Style;

	// Submit label or explicit size to ItemSize(), whereas ItemAdd() will submit a larger/spanning rectangle.
	ImGuiID id = 0;
	if (label)
	{
		id = window->GetID(label);
	}

	ImVec2 text_size = CalcTextSize(begin, end, true);
	ImVec2 size_arg;
	ImVec2 size(size_arg.x != 0.0f ? size_arg.x : text_size.x, size_arg.y != 0.0f ? size_arg.y : text_size.y);
	ImVec2 pos = window->DC.CursorPos;

	ImRect bb(pos.x, pos.y, pos.x + size.x, pos.y + size.y);
	
	// Add the item spacing and center the text horizontally.
	{
		bb.Max.y += style.ItemSpacing.y;
		pos.y += style.ItemSpacing.y * 0.5f;
	}

	// Set spacing to zero temporarily to avoid extra spacing for the last item.
	auto saved = g.Style.ItemSpacing.y;
	g.Style.ItemSpacing.y = 0;
	ItemSize(bb.GetSize(), 0.0f);
	g.Style.ItemSpacing.y = saved;

	const bool disabled_item = (flags & ImGuiSelectableFlags_Disabled) != 0;
	const ImGuiItemFlags extra_item_flags = disabled_item ? (ImGuiItemFlags)ImGuiItemFlags_Disabled : ImGuiItemFlags_None;
	
	bool is_visible = ItemAdd(bb, id, NULL, extra_item_flags);

	if (!is_visible)
	{
		return;
	}

	const bool disabled_global = (g.CurrentItemFlags & ImGuiItemFlags_Disabled) != 0;
	if (disabled_item && !disabled_global) // Only testing this as an optimization
		BeginDisabled();

	bool hovered = false;
	bool pushed = false;

	if (IsItemHovered())
	{
		hovered = true;
		if (IsMouseDown(ImGuiMouseButton_Left, id))
		{
			pushed = true;
		}
	}

	// Render
	if (is_visible)
	{
		if (background_color > 0)
		{
			RenderFrame(bb.Min, bb.Max, background_color, false, 0.0f);
		}

		const bool can_highlight = (flags & ImGuiSelectableFlags_Highlight);
		if (can_highlight && (hovered || pushed))
		{
			ImU32 col = GetColorU32(pushed ? ImGuiCol_HeaderActive : (hovered ? ImGuiCol_HeaderHovered : ImGuiCol_Header));
			RenderFrame(bb.Min, bb.Max, col, false, 0.0f);
		}
	}

	if (is_visible)
	{
		ImU32 color = foreground_color ? foreground_color : GetColorU32(ImGuiCol_Text);
		window->DrawList->AddText(g.Font, g.FontSize, pos, color, begin, end);
	}

	// Automatically close popups
	if (pushed && (window->Flags & ImGuiWindowFlags_Popup) && !(flags & ImGuiSelectableFlags_NoAutoClosePopups) && (g.LastItemData.ItemFlags & ImGuiItemFlags_AutoClosePopups))
		CloseCurrentPopup();

	if (disabled_item && !disabled_global)
		EndDisabled();
}

int text_viewer::line::get_utf8_char_count() const
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
	, last_click_time(-1.0f)
{
}

void text_viewer::render()
{
	text_changed = false;

	ImGuiWindow* window = ImGui::GetCurrentWindow();
	window_pos = window->Pos;
	window_scroll = window->Scroll;
	window_padding = window->WindowPadding;

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
			for (int i = start.line + 1; i < end.line; i += 1)
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
	coord_range range = get_selection_range();
	return get_text(range.start, range.end);
}

int text_viewer::get_text_line_count() const
{
	return lines.size();
}

string_view text_viewer::get_selected_line_text() const
{
	coord pos = get_cursor_position();
	return lines[pos.line].text;
}

coord text_viewer::get_cursor_position() const
{
	return selection.end;
}

void text_viewer::set_cursor_position(coord pos)
{
	set_selection_end(pos);
}

coord_range text_viewer::get_selection_range() const
{
	if (selection.start <= selection.end)
	{
		return selection;
	}
	return coord_range(selection.end, selection.start);
}

void text_viewer::set_selection_start(coord pos, bool update_anchor_column)
{
	if (update_anchor_column)
	{
		anchor_column = pos.column;
	}

	selection.start = sanitize_coord(pos);
}

void text_viewer::set_selection_end(coord pos)
{
	selection.end = sanitize_coord(pos);
}

void text_viewer::set_selection(coord start, coord end, bool update_anchor_column)
{
	set_selection_start(start, update_anchor_column);
	set_selection_end(end);
}

void text_viewer::select_all()
{
	set_selection(coord(0, 0), coord((int)lines.size(), 0));
}

bool text_viewer::has_selection() const
{
	coord_range range = get_selection_range();
	return range.start < range.end;
}

void text_viewer::copy_selection() const
{
	// Copy selected text
	if (has_selection())
	{
		ImGui::SetClipboardText(get_selected_text().c_str());
	}
	// Otherwise copy the selected line
	else
	{
		string_view line = get_selected_line_text();
		std::string str(line.data, line.size);

		ImGui::SetClipboardText(str.c_str());
	}
}

int text_viewer::get_selected_line_number() const
{
	return line_index_to_line_number(get_cursor_position().line);
}

int text_viewer::line_number_to_line_index(int line_number) const
{
	return line_number > 0 ? line_number - 1 : 0;
}

int text_viewer::line_index_to_line_number(int line_index) const
{
	return line_index + 1;
}

void text_viewer::scroll_to_line_number(int line_number)
{
	line_to_scroll_to = line_number < 1
		? 1
		: line_number_to_line_index(line_number);
}

void text_viewer::scroll_to_line_index(int line_index)
{
	line_to_scroll_to = line_index < 0
		? 0
		: line_index;
}

coord text_viewer::cursor_translated_x(int delta)
{
	coord pos = get_cursor_position();
	pos.column += delta;
	
	// While there is a negative column number move one line up and adjust column coordinate.
	while (pos.column < 0 && pos.line > 0)
	{
		// Move line up.
		pos.line -= 1;
		// Column is now equal to the last position character of the line +1
		// because the cursor can be right after the last char of the line.
		pos.column += lines[pos.line].get_utf8_char_count();
	}
	
	while (pos.line + 1 < lines.size() && pos.column > lines[pos.line].get_utf8_char_count())
	{
		// Remove char count to the column number
		pos.column -= lines[pos.line].get_utf8_char_count();
		// Since the column can be within [0 ; line.char_count] (inclusive range).
		// We need to substract the line.char_count and one extra character to make it 0-based.
		pos.column -= 1;
		// Move line down.
		pos.line += 1;
	}

	return sanitize_coord(pos);
}

coord text_viewer::cursor_translated_y(int delta)
{
	coord position_to_translate = get_anchor_cursor();

	position_to_translate.line += delta;

	// If the resulting line is smaller than the first line index,
	// we want the coordinate to be on the first char (0,0).
	if (position_to_translate.line < 0)
	{
		return coord(0, 0);
	}

	// If the resulting line greated than the last line index,
	// we set the coordinate to (last, infinite+) to set it to the maximum posible location
	// The coordinate will get sanitize and it prevents us to count the number of character
	// in a UTF-8 line.
	if (position_to_translate.line >= lines.size())
	{
		return coord(lines.size(), coord::column_int_max);
	}

	return position_to_translate;
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
	graphical_char_size.x = font_size;

	// Flag cursor change
	bool cursor_changed = false;
	{
		if (previous_cursor_position != get_cursor_position())
		{
			cursor_changed = true;
		}
		previous_cursor_position = get_cursor_position();
	}

	auto draw_list = ImGui::GetWindowDrawList();

	ImGuiListClipper clipper;

	clipper.Begin(lines.size());

	int scroll_at = 0;
	if (cursor_changed)
	{
		scroll_at = get_cursor_position().line;
		clipper.IncludeItemByIndex(scroll_at);
	}

	bool scroll_requested = line_to_scroll_to >= 0;

	// Scroll if requested.
	// This override the "IncludeItemByIndex" from the cursor change above.
	if (scroll_requested)
	{
		scroll_at = line_to_scroll_to;
		line_to_scroll_to = -1;

		// Force display of specified line.
		clipper.IncludeItemByIndex(scroll_at);
	}

	bool is_first_iteration = true;
	while (clipper.Step())
	{
		// line_index: 0-based index
		for (int line_index = clipper.DisplayStart; line_index < clipper.DisplayEnd; line_index += 1)
		{
			auto& line = lines[line_index];
			// Display line_number = number displayed to the user.
			auto line_number = line_index_to_line_number(line_index);

			bool line_is_selected = line_index == get_cursor_position().line;

			if (options.display_line_prelude)
			{
				int line_number = line_index_to_line_number(line_index);
				coord last_coord = screen_pos_to_coord(window->Rect().Max);
				int last_visible_line_number = line_index_to_line_number(last_coord.line);
				options.line_prelude(&options, line_number, last_visible_line_number, line_is_selected);
			}

			{
				float selection_start = -1.0f;
				float selection_end = -1.0f;
				
				// Current line bounding box.
				ImRect line_bb;

				// Display text line
				{
					// Display a space in case the text is empty because we still need a bounding box to scroll to.
					static string_view text_with_single_space(" ", 1);
					string_view text_to_display = line.text.size ? line.text : text_with_single_space;

					char line_label[64];
					snprintf(line_label, 64, "##%d", line_index);

					int text_line_flags = ImGuiSelectableFlags_SpanAvailWidth;
					render_text_line(text_to_display.data, text_to_display.data + text_to_display.size, line_label, 0, 0, text_line_flags);

					line_bb = ImRect(ImGui::GetItemRectMin(), ImGui::GetItemRectMax());

					if (is_first_iteration)
					{
						is_first_iteration = false;

						// Update the text according to the size of everything before that.
						// The line number is displayed by default but there might be user items.
						text_margin_x = line_bb.Min.x;

						graphical_char_size.y = line_bb.GetHeight();
					}
				}

				if (options.display_text_selection)
				{
					coord line_start_coord(line_index, 0);
					coord line_end_coord(line_index, get_line_column_length(line_index));

					coord_range selection = get_selection_range();

					assert(selection.start <= selection.end);
					if (line_end_coord >= selection.start)
					{
						selection_start = line_start_coord < selection.start
							? text_distance_from_line_start(selection.start)
							: 0.0f;
					}

					if (line_start_coord < selection.end)
					{
						coord coord = line_end_coord > selection.end ? selection.end : line_end_coord;
						selection_end = text_distance_from_line_start(coord);
					}

					if (line_index < selection.end.line)
					{
						selection_end += graphical_char_size.x;
					}
				}

				// Scroll if needed
				{
					if (scroll_requested && scroll_at == line_index)
					{
						// Scroll right at the previous item.
						ImGui::SetScrollHereY(0.1f);
					}

					// Scroll to cursor if it changed.
					if (cursor_changed && scroll_at == line_index)
					{
						float dist = text_distance_from_line_start(get_cursor_position());
						ImVec2 min(line_bb.Min.x + dist, line_bb.Min.y);
						ImVec2 max(line_bb.Min.x + dist + 2.f, line_bb.Max.y);
						ImGui::ScrollToRect(ImGui::GetCurrentWindow(), ImRect(min, max));
					}
				}

				if (options.display_text_selection)
				{
					if (selection_start != -1 && selection_end != -1 && selection_start < selection_end)
					{
						ImVec2 selection_rect_min(line_bb.Min.x + selection_start, line_bb.Min.y);
						ImVec2 selection_rect_max(line_bb.Min.x + selection_end, line_bb.Max.y);
						draw_list->AddRectFilled(selection_rect_min, selection_rect_max, ImGui::GetColorU32(style.Colors[ImGuiCol_TextSelectedBg]));
					}
				}

				// Display input cursor
				if (options.display_cursor && line_is_selected)
				{
					// Render two straight lines to avoid anti aliasing of rectangles.
					float dist = (float)floor(text_distance_from_line_start(get_cursor_position()));
					ImVec2 min(line_bb.Min.x + dist, line_bb.Min.y);
					ImVec2 max(line_bb.Min.x + dist, line_bb.Max.y);
					ImU32 color = ImGui::GetColorU32(style.Colors[ImGuiCol_PlotHistogram]);
					draw_list->AddLine(min, max, color);
					min.x += 1.0f;
					max.x += 1.0f;
					draw_list->AddLine(min, max, color);
				}

				if (options.debug_mode)
				{
					// Display selection start
					if (selection.start.line == line_index)
					{
						float dist = selection.start.column * font_size;
						ImVec2 min(line_bb.Min.x + dist, line_bb.Min.y);
						ImVec2 max(line_bb.Min.x + dist + 3.f, line_bb.Max.y);
						draw_list->AddRect(min, max, ImGui::GetColorU32(style.Colors[ImGuiCol_PlotLines]));
					}

					// Display selection end
					if (selection.end.line == line_index)
					{
						float dist = selection.end.column * font_size;
						ImVec2 min(line_bb.Min.x + dist, line_bb.Min.y);
						ImVec2 max(line_bb.Min.x + dist + 3.f, line_bb.Max.y);
						draw_list->AddRect(min, max, ImGui::GetColorU32(style.Colors[ImGuiCol_PlotHistogram]));
					}

					// Display the anchor cursor.
					if (get_anchor_cursor().line == line_index)
					{
						float dist = get_anchor_cursor().column * font_size;
						ImVec2 min(line_bb.Min.x + dist, line_bb.Min.y);
						ImVec2 max(line_bb.Min.x + dist + 3.f, line_bb.Max.y);
						draw_list->AddRect(min, max, ImGui::GetColorU32(style.Colors[ImGuiCol_PlotLinesHovered]));
					}
				}
			}
		}
	}

	// Add this dummy to fix a scroll issue where last spacing is not taken into account by the scroll bar.
	ImGui::Dummy(style.ItemSpacing);
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
	const char* cursor = view.data;
	const char* end = view.data + view.size;

	ImGuiContext* ctx = ImGui::GetCurrentContext();

	int char_count = 0;
	float current_x = 0.0f;
	while (cursor < end)
	{
		unsigned int c;
		cursor += ImTextCharFromUtf8(&c, cursor, end);

		float advance = ctx->Font->GetCharAdvance((ImWchar)c) * ctx->FontScale;

		if (current_x + (advance * 0.5f) > distance)
			return char_count;
		current_x += advance;
		char_count += 1;
	}
	return char_count;
};

coord text_viewer::sanitize_coord(coord pos) const
{
	if (lines.empty())
	{
		return coord(0, 0);
	}

	int line = tv::clamp(pos.line, 0, (int)lines.size() - 1);
	int column = tv::clamp(pos.column, 0, get_line_column_length(line));

	return coord(line, column);
}

coord text_viewer::get_anchor_cursor() const
{
	// Get the line where the mouse cursor is, but get the column wheren the selection started.
	// This allow use to better position the resulting cursor.
	// Example:
	// 
	//    Hello,
	//    I'm a human
	// 
	// If my cursor is inside 'human', when moving up the cursor should stick to the comma after "Hello".
	// If a moving back the cursor I should be where I started inside 'human'
	//
	return coord(get_cursor_position().line, anchor_column);
}

coord text_viewer::screen_pos_to_coord(const ImVec2& screen_pos) const
{
	if (lines.empty())
	{
		return coord(0, 0);
	}

	// Local pos relative to the parent window or child window.
	ImVec2 local_pos(screen_pos - window_pos + window_scroll);
	// Local margin
	float local_margin(text_margin_x - window_pos.x + window_scroll.x);

	int line_index = (int)floor((local_pos.y - window_padding.y) / graphical_char_size.y);

	if (line_index < 0) {
		line_index = 0;
	}

	if (line_index >= lines.size())
	{
		return sanitize_coord(coord(lines.size() - 1, coord::column_int_max));
	}

	int column_index = 0;

	if (line_index >= 0 && line_index < (int)lines.size())
	{
		auto& line = lines[line_index];

		column_index = text_distance_to_column_index(line.text, local_pos.x - local_margin);
	}

	return coord(line_index, column_index);
}

int text_viewer::max_visible_line_per_page() const
{
	auto height = ImGui::GetWindowHeight();
	return (int)floor(height / graphical_char_size.y);
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

	return string_view(lower, cursor);
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

	return string_view(cursor, end);
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

	return string_view(text.data, cursor);
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

	return tv::min(line.get_utf8_char_count(), pos.column);
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
		else if (ctrl && !shift && !alt && ImGui::IsKeyPressed(ImGuiKey_X))
			copy_selection();
		else if (ctrl && !shift && !alt && ImGui::IsKeyPressed(ImGuiKey_A))
			select_all();
		else if (!ctrl && !alt && ImGui::IsKeyPressed(ImGuiKey_UpArrow))
		{
			coord new_pos = cursor_translated_y( -1 );
			if (shift)
				set_selection(selection.start, new_pos);
			else
				set_selection(new_pos, new_pos);
		}
		else if (!ctrl && !alt && ImGui::IsKeyPressed(ImGuiKey_DownArrow))
		{
			coord new_pos = cursor_translated_y( +1 );
			if (shift)
				set_selection(selection.start, new_pos);
			else
				set_selection(new_pos, new_pos);
		}
		else if (!alt && ImGui::IsKeyPressed(ImGuiKey_PageUp))
		{
			coord new_pos = cursor_translated_y( - max_visible_line_per_page());
			if (shift)
				set_selection(selection.start, new_pos);
			else
				set_selection(new_pos, new_pos);
		}
		else if (!alt && ImGui::IsKeyPressed(ImGuiKey_PageDown))
		{
			coord new_pos = cursor_translated_y( + max_visible_line_per_page());
			if (shift)
				set_selection(selection.start, new_pos);
			else
				set_selection(new_pos, new_pos);
		}
		else if (!ctrl && !alt && ImGui::IsKeyPressed(ImGuiKey_LeftArrow))
		{
			coord new_pos = cursor_translated_x( -1 );
			if (shift)
				set_selection(selection.start, new_pos);
			else
				set_selection(new_pos, new_pos, true);
		}
		else if (!ctrl && !alt && ImGui::IsKeyPressed(ImGuiKey_RightArrow))
		{
			coord new_pos = cursor_translated_x( +1 );
			if (shift)
				set_selection(selection.start, new_pos);
			else
				set_selection(new_pos, new_pos, true);
		}
		else if (!alt && ImGui::IsKeyPressed(ImGuiKey_Home))
		{
			coord current = get_cursor_position();
			coord new_pos(current.line, 0);
			if (shift)
				set_selection(selection.start, new_pos);
			else
				set_selection(new_pos, new_pos, true);
		}
		else if (!alt && ImGui::IsKeyPressed(ImGuiKey_End))
		{
			coord current = get_cursor_position();
			coord new_pos(current.line, lines[current.line].get_utf8_char_count());
			if (shift)
				set_selection(selection.start, new_pos);
			else
				set_selection(new_pos, new_pos, true);
		}
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

					coord line_start(pos.line, 0);
					coord line_end(pos.line, get_line_column_length(pos.line));

					set_selection(line_start, line_end, true);
				}

				last_click_time = -1.0f;
			}
			// Left mouse button double click
			else if (left_double_click)
			{
				if (!ctrl)
				{
					coord pos = screen_pos_to_coord(ImGui::GetMousePos());
					coord_range r = get_range_of_same_char_at(pos);

					set_selection(r.start, r.end, true);
				}

				last_click_time = (float)ImGui::GetTime();
			}
			// Left mouse button click
			else if (left_click)
			{
				coord pos = screen_pos_to_coord(ImGui::GetMousePos());

				coord_range r(pos, pos);
				if (ctrl)
				{
					r = get_range_of_same_char_at(pos);
				}

				set_selection(r.start, r.end, true);

				last_click_time = (float)ImGui::GetTime();
			}
			// Update selection on mouse dragging.
			else if (ImGui::IsMouseDragging(ImGuiMouseButton_Left) && ImGui::IsMouseDown(ImGuiMouseButton_Left))
			{
				io.WantCaptureMouse = true;
				coord pos = screen_pos_to_coord(ImGui::GetMousePos());
				set_selection_end(pos);
			}
		}
	}
}

static int utf8_char_count(const char* str, int n)
{
	const char* t = str;
	int length = 0;

	while ((str - t) < n && '\0' != *str) {
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

	if ((str - t) > n) {
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