#include "text_viewer.hpp"

namespace tv {

    static text_viewer viewer;

    static bool first_time = true;

    static bool show_text_viewer_options = true;

    static bool print_selection_coord = true;
    static bool print_cursor_coord = true;
    static bool print_selected_text = true;

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

            text = std::string(
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

            viewer.set_text(text);
        }

        {
            if (ImGui::CollapsingHeader("Text Viewer Options"))
            {
                // Options
                ImGui::Text("Options:");
                ImGui::Checkbox("Allow Keyboard Inputs", &viewer.options.allow_keyboard_inputs);
                ImGui::Checkbox("Allow Mouse Inputs", &viewer.options.allow_mouse_inputs);
              
                ImGui::Checkbox("Display Text Selection", &viewer.options.display_text_selection);
                ImGui::Checkbox("Display Line Selection", &viewer.options.display_line_selection);
                ImGui::Checkbox("Display Line Prelude ", &viewer.options.display_line_prelude);
                ImGui::Checkbox("Display Line Number ", &viewer.options.display_line_number);
                // Extra
                ImGui::Text("API use:");
                ImGui::Checkbox("Display Selection Coordinates", &print_selection_coord);
                ImGui::Checkbox("Display Cursor Coordinate", &print_cursor_coord);
                ImGui::Checkbox("Display Selected Text", &print_selected_text);
            }
             
            {
                // We want the left side to take as much space as possible.
                float expand_x = -FLT_MIN;
                // We want to keep a margin to display the information line the selected line, position, selection etc.
                float expand_y_but_keep_a_margin_of = -ImGui::GetTextLineHeightWithSpacing();
                if (print_selection_coord)
                    expand_y_but_keep_a_margin_of -= ImGui::GetTextLineHeightWithSpacing();
                if (print_cursor_coord)
                    expand_y_but_keep_a_margin_of -= ImGui::GetTextLineHeightWithSpacing();
                if (print_selected_text)
                    expand_y_but_keep_a_margin_of -= ImGui::GetTextLineHeightWithSpacing();

                ImGui::BeginChild("Text Viewer", ImVec2(expand_x, expand_y_but_keep_a_margin_of), ImGuiChildFlags_Borders | ImGuiChildFlags_FrameStyle);

                viewer.render();

                ImGui::EndChild();
            }

            if (print_selection_coord)
            {
                auto range = viewer.get_selection_range();
               
                ImGui::Text("Selection Range (%d %d) - (%d %d)",
                    range.start.line, range.start.column,
                    range.end.line, range.end.column);
            }

            if (print_cursor_coord)
            {
                auto coord = viewer.get_cursor_position();
                ImGui::Text("Cursor Position %d %d", coord.line, coord.column);
            }

            if (print_selected_text)
            {
                ImGui::Text("%s", viewer.get_selected_text().c_str());
            }
        }

        ImGui::End();
	}

} // namespace tv