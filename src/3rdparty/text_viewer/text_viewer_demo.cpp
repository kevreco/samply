#include "text_viewer.hpp"

namespace tv {

    static text_viewer viewer;

    static bool first_time = true;

    static bool show_text_viewer_options = true;

    static bool print_selection_coord = true;
    static bool print_cursor_coord = true;
    static bool print_selected_line_number = true;
    static bool print_selected_text = true;
    static bool print_selected_line_text = true;

    static std::string text;

	void show_demo_window(bool* p_open)
	{
    
        if (!ImGui::Begin("Text Viewer Demo", p_open))
        {
            ImGui::End();
            return;
        }

        if (first_time)
        {
            first_time = false;

            static std::string text = std::string(
R"(#include <stdio.h>

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    int number;

    scanf("%d", &number);

    if (number < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("Factorial of %d is %d\n", number, factorial(number));
    }

    return 0;
})");

            viewer.set_text(tv::string_view(text.data(), (int)text.size()));
        }

        {
            if (ImGui::CollapsingHeader("Features List"))
            {
                ImGui::BulletText("Cursor position (can be disabled).");
                ImGui::BulletText("Current line selection (can be disabled).");
                ImGui::BulletText("Current text selection (can be disabled).");
                ImGui::BulletText("Line number (can be disabled).");
                ImGui::BulletText("Custom widgets can be displayed before the line.");
                ImGui::BulletText("Copy selection via CTRL+C and CTRL+X");
                ImGui::BulletText("Move cursor with UP, DOWN, PAGE_UP, PAGE_DOWN, HOME, END.");
                ImGui::BulletText("Move selection holding CTRL.");
                ImGui::BulletText("CTRL+A to select all the text.");
                ImGui::BulletText("Keyboards and mouse inputs can be disabled.");
            }

            if (ImGui::CollapsingHeader("Text Viewer Options"))
            {
                // Options
                float indent_offset = 220.0f;
                ImGui::Text("Options:");
                ImGui::Checkbox("Allow Keyboard Inputs", &viewer.options.allow_keyboard_inputs);
                ImGui::SameLine(indent_offset);
                ImGui::Checkbox("Allow Mouse Inputs", &viewer.options.allow_mouse_inputs);
                
                ImGui::Checkbox("Display Cursor", &viewer.options.display_cursor);
                ImGui::SameLine(indent_offset);
                ImGui::Checkbox("Display Text Selection", &viewer.options.display_text_selection);

                ImGui::Checkbox("Display Line Prelude", &viewer.options.display_line_prelude);
                ImGui::SameLine(indent_offset);
                ImGui::Checkbox("Display Line Number", &viewer.options.display_line_number);

                ImGui::Checkbox("Debug Mode", &viewer.options.debug_mode);
            }

            if (ImGui::CollapsingHeader("API Use"))
            {
                ImGui::Checkbox("Display Selection Coordinates", &print_selection_coord);
                ImGui::Checkbox("Display Cursor Coordinate", &print_cursor_coord);
                ImGui::Checkbox("Display Selected Line Number Coordinate", &print_selected_line_number);
                ImGui::Checkbox("Get Selected Text", &print_selected_text);
                ImGui::Checkbox("Get Selected Line Text", &print_selected_line_text);

                static int line_index_to_scroll_to = 0; ;

                ImGui::SetNextItemWidth(80.0f);
               
                if (ImGui::DragInt("Goto to line", &line_index_to_scroll_to, 0.2f, 0, viewer.get_text_line_count()))
                {
                    viewer.request_scroll_to_line_number(line_index_to_scroll_to);
                }
            }
            float scroll_y = 0;
            float scroll_max_y = 0;
            {
                ImGuiWindowFlags window_flags = ImGuiWindowFlags_AlwaysHorizontalScrollbar;
                // Add No nav to avoid some undesiredeffect when moving up and down with the keyboard.
                // The windows will try to scroll once and immediatly reposition itself
                // due to the changing selection on the text viewer side.
                window_flags |= ImGuiWindowFlags_NoNav;

                ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0.0f, 0.0f));

                ImGui::BeginChild("LeftChild", ImVec2(ImGui::GetContentRegionAvail().x * 0.5f, -ImGui::GetTextLineHeightWithSpacing()), ImGuiChildFlags_Borders  | ImGuiChildFlags_FrameStyle, window_flags);

                viewer.render();

                scroll_y = ImGui::GetScrollY();
                scroll_max_y = ImGui::GetScrollMaxY();

                ImGui::EndChild();

                ImGui::PopStyleVar(1);
            }

            ImGui::SameLine();

            {
                ImGuiWindowFlags window_flags = ImGuiWindowFlags_None;

                ImGui::BeginChild("RightChild", ImVec2(0, -ImGui::GetTextLineHeightWithSpacing()), ImGuiChildFlags_Borders, window_flags);
                if (print_selection_coord)
                {
                    auto range = viewer.get_selection_range();

                    ImGui::BulletText("Selection Range: (%d %d) - (%d %d)",
                        range.start.line, range.start.column,
                        range.end.line, range.end.column);
                }

                if (print_cursor_coord)
                {
                    auto coord = viewer.get_cursor_position();
                    ImGui::BulletText("Cursor Position: (%d %d)", coord.line, coord.column);
                }

                if (print_selected_line_number)
                {
                    auto line_number = viewer.get_selected_line_number();
                    ImGui::BulletText("Selected line number: %zu", line_number);
                }
                
                if (print_selected_text)
                {
                    ImGui::SeparatorText("Selected Text:");

                    tv::coord_range range = viewer.get_selection_range();
                    int line_count = range.end.line - range.start.line;
                    if (line_count > 0)
                    {
                        ImGui::Text("Line count selection: %d", line_count);

                        if (ImGui::BeginChild("Selected Text", ImVec2(-FLT_MIN, 0.0f), ImGuiChildFlags_Borders | ImGuiChildFlags_FrameStyle | ImGuiChildFlags_AutoResizeY))
                            ImGui::Text("%s", viewer.get_selected_text().c_str());
                        ImGui::EndChild();
                    }
                }

                if (print_selected_line_text)
                {
                    ImGui::SeparatorText("Selected Line Text:");
                    
                    if (ImGui::BeginChild("Selected Line Text", ImVec2(-FLT_MIN, 0.0f), ImGuiChildFlags_Borders | ImGuiChildFlags_FrameStyle | ImGuiChildFlags_AutoResizeY))
                        ImGui::Text(TV_SV_FMT, TV_SV_ARG(viewer.get_selected_line_text()));
                    ImGui::EndChild();
                }
                ImGui::EndChild();
            }

            ImGui::Text("Scrolling: %.0f/%.0f", scroll_y, scroll_max_y);
        }

        ImGui::End();
	}

} // namespace tv