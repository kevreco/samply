#include "text_viewer.hpp"

namespace tv {

    static text_viewer viewer;

    static bool first_time = true;

    static bool show_text_viewer_options = true;

    static bool print_selection_coord = true;
    static bool print_cursor_coord = true;
    static bool print_selected_line_number = true;
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

            viewer.set_text(tv::string_view(text.data(), text.size()));
        }

        {
            if (ImGui::CollapsingHeader("Text Viewer Options"))
            {
                // Options
                ImGui::Text("Options:");
                ImGui::Checkbox("Allow Keyboard Inputs", &viewer.options.allow_keyboard_inputs);
                ImGui::SameLine();
                ImGui::Checkbox("Allow Mouse Inputs", &viewer.options.allow_mouse_inputs);
                

                ImGui::Checkbox("Display Text Selection", &viewer.options.display_text_selection);
                ImGui::SameLine();
                ImGui::Checkbox("Display Line Selection", &viewer.options.display_line_selection);
               
                ImGui::Checkbox("Display Line Prelude ", &viewer.options.display_line_prelude);
                ImGui::SameLine();
                ImGui::Checkbox("Display Line Number ", &viewer.options.display_line_number);
                // Extra
                ImGui::Text("API use:");
                ImGui::Checkbox("Display Selection Coordinates", &print_selection_coord);
                ImGui::Checkbox("Display Cursor Coordinate", &print_cursor_coord);
                ImGui::Checkbox("Display Selected Line Number Coordinate", &print_selected_line_number);
                ImGui::Checkbox("Get Selected Text", &print_selected_text);
            }


            {
                ImGuiWindowFlags window_flags = ImGuiWindowFlags_HorizontalScrollbar;

                ImGui::BeginChild("ChildL", ImVec2(ImGui::GetContentRegionAvail().x * 0.5f, -FLT_MIN), ImGuiChildFlags_Borders | ImGuiChildFlags_FrameStyle, window_flags);

                viewer.render();

                ImGui::EndChild();
            }

            ImGui::SameLine();

            {
                ImGuiWindowFlags window_flags = ImGuiWindowFlags_None;

                ImGui::BeginChild("ChildR", ImVec2(0, -FLT_MIN), ImGuiChildFlags_Borders, window_flags);
                if (print_selection_coord)
                {
                    auto range = viewer.get_selection_range();

                    ImGui::BulletText("Selection Range (%d %d) - (%d %d)",
                        range.start.line, range.start.column,
                        range.end.line, range.end.column);
                }

                if (print_cursor_coord)
                {
                    auto coord = viewer.get_cursor_position();
                    ImGui::BulletText("Cursor Position %d %d", coord.line, coord.column);
                }

                if (print_selected_line_number)
                {
                    auto line_number = viewer.get_selected_line_number();
                    ImGui::BulletText("Selected line number %zu", line_number);
                }
                
                if (print_selected_text)
                {
                    ImGui::BulletText("Selected Text:");
                    ImGui::Separator();
                    ImGui::Text("%s", viewer.get_selected_text().c_str());
                    ImGui::Separator();
                }

                ImGui::EndChild();
            }
        }

        ImGui::End();
	}

} // namespace tv