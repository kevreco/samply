#include "gui.hpp"

#include <stdlib.h> // qsort

#include "imgui_plus_extensions.h"

#include "samply.h"
#include "report.h"

namespace helpers {

    // To sort tables.
    static const ImGuiTableSortSpecs* current_sort_specs;

    static void report_table_sort_with_sort_specs(ImGuiTableSortSpecs* sort_specs, summed_record* items, size_t items_count);
    static int report_table_sort(const void* left, const void* right);

    static bool is_slash(char c);

    static bool find_last_slash(strv path, size_t* index);

    strv path_get_last_segment(strv path);

    static void render_extra_line_information(tv::options* options, int line_number, int visible_line_max, bool line_is_selected);
}

using namespace helpers;

gui::gui(struct sampler* s, struct report* r)
{
    this->sampler = s;
    this->report = r;

    file_mapper_init(&file_mapper);
    current_opened_filepath = STRV("");
    readonly_file_init(&current_file);

    text_viewer.options.line_prelude = helpers::render_extra_line_information;
    text_viewer.options.line_prelude_user_data = this;

    records_of_current_file = record_range_make();
}

gui::~gui()
{
    file_mapper_destroy(&file_mapper);
}

int gui::main()
{

    show_main_menu_bar();

    show_main_window();

    if (cfg.open_about_window)
    {
        show_about_window(&cfg.open_about_window);
    }

    if (cfg.open_imgui_demo_window)
    {
        ImGui::ShowDemoWindow(&cfg.open_imgui_demo_window);
    }

    if (cfg.open_text_viewer_demo_window)
    {
        tv::show_demo_window(&cfg.open_text_viewer_demo_window);
    }

    return 0;
}

bool gui::open_file(strv filepath)
{
    static strv no_file = STRV("No file displayed");
    static strv could_not_open = STRV("Could not open file.");

    text_viewer.set_text(tv::string_view(no_file.data, no_file.size));

    // Close previous file
    if (readonly_file_is_opened(&current_file))
    {
        file_mapper_close(&file_mapper, &current_file);
        readonly_file_init(&current_file);
    }

    // Open new file
    if (!file_mapper_open(&file_mapper, &current_file, filepath))
    {
        text_viewer.set_text(tv::string_view(could_not_open.data, could_not_open.size));

        return false;
    }

    current_opened_filepath = filepath;

    record* records = report->records.data;
    size_t record_count = report->records.size;
    records_of_current_file = record_range_for_file(records, record_count, filepath);

    tv::string_view content_view = tv::string_view(current_file.view.data, current_file.view.size);
    text_viewer.set_text(content_view);

    return true;
}

void gui::jump_to_file(strv filepath, size_t line)
{
    if (!strv_equals(current_opened_filepath, filepath))
    {
        if (!open_file(filepath))
        {
            return;
        }
    }

    text_viewer.request_scroll_to_line_number(line);
}

//-----------------------------------------------------------------------
// Private
//-----------------------------------------------------------------------

void gui::show_main_menu_bar()
{
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Edit"))
        {
            if (ImGui::MenuItem("Options")) {}
            ImGui::Separator();
            if (ImGui::MenuItem("Preferences")) {}
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Help"))
        {
            if (ImGui::BeginMenu("Debug"))
            {
                ImGui::Checkbox("Show ImGui Demo Window", &cfg.open_imgui_demo_window);
                ImGui::Checkbox("Show Text Viewer Demo Window", &cfg.open_text_viewer_demo_window);

                ImGui::Checkbox("'Fullscreen' Main Window", &cfg.open_main_window_full_screen);
                ImGui::EndMenu();
            }

            ImGui::EndMenu();
        }
        if (ImGui::MenuItem("About", "CTRL+M"))
        {
            cfg.open_about_window = true;
        }

        ImGui::EndMainMenuBar();
    }
}

void gui::show_about_window(bool* p_open)
{
    if (ImGui::Begin("About", p_open, ImGuiWindowFlags_AlwaysAutoResize))
    {
        ImGui::Text("%s %s - (%d)", SMP_APP_NAME, SMP_APP_VERSION_TEXT, SMP_APP_VERSION_NUMBER);
        ImGui::Text("Backend: " STRV_FMT, STRV_ARG(gui::backend_identifier()));

        ImGui::TextLinkOpenURL("Homepage", "https://github.com/kevreco/samply");
        ImGui::SameLine();
        ImGui::TextLinkOpenURL("FAQ", "@TODO");
        ImGui::SameLine();
        ImGui::TextLinkOpenURL("Wiki", "@TODO");
        ImGui::SameLine();
        ImGui::TextLinkOpenURL("Releases", "@TODO");
        ImGui::Separator();
        ImGui::Text("(c) kevreco");
        ImGui::Text("Developed by kevreco.");
        ImGui::Text("%s is licensed under the MIT License", SMP_APP_NAME);
        {
            ImGui::Text("See");
            ImGui::SameLine();
            ImGui::TextLinkOpenURL("LICENSE.md", "https://github.com/kevreco/samply/LICENSE.md");
            ImGui::SameLine();
            ImGui::Text("for more information.");
        }
    }
    ImGui::End();
}

void gui::show_main_window()
{
    // Main windows always stayed buried behind all other windows.
    ImGuiWindowFlags flags = ImGuiWindowFlags_NoBringToFrontOnFocus;

    if (cfg.open_main_window_full_screen)
    {
        flags |= ImGuiWindowFlags_NoDecoration
            | ImGuiWindowFlags_NoMove
            | ImGuiWindowFlags_NoSavedSettings;

        // Remove border
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);

        // We demonstrate using the full viewport area or the work area (without menu-bars, task-bars etc.)
        // Based on your use case you may want one or the other.
        const ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->WorkPos);
        ImGui::SetNextWindowSize(viewport->WorkSize);
    }

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

    bool always_opened = true;
    bool begin = ImGui::Begin("Main Window", &always_opened, flags);

    ImGui::PopStyleVar(); // Restore WindowPadding.

    if (begin)
    {
        show_full_screen_window_body();
    }

    ImGui::End();

    if (cfg.open_main_window_full_screen)
    {
        ImGui::PopStyleVar(1);
    }
}

void gui::show_full_screen_window_body()
{
    ImGuiTabBarFlags tab_bar_flags = ImGuiTabBarFlags_None;
    if (ImGui::BeginTabBar("MainTabBar", tab_bar_flags))
    {
        // Remove spacing under the tab bar
        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0.0f, 0.0f));

        if (ImGui::BeginTabItem("Reports"))
        {
            ImGui::PopStyleVar(1); // Restore item spacing.

            show_report_tab();

            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem("Processes"))
        {
            ImGui::PopStyleVar(1); // Restore item spacing.

            ImGui::Text("@TODO: Display list of running process.");
            ImGui::EndTabItem();
        }
        ImGui::EndTabBar();
    }
}

void gui::show_report_tab()
{
    const ImGuiStyle& style = ImGui::GetStyle();
    float splitter_width = 8.0f;
    auto avail_size = ImGui::GetContentRegionAvail();

    static float horiz_split_pos = avail_size.y / 2.0f; // Position the splitter at the third of the area.

    ImGui::SplitterHorizontal(splitter_width, &horiz_split_pos, 0, avail_size.y, avail_size.x);
    {
        ImGui::BeginChild("Top", ImVec2(avail_size.x, horiz_split_pos));

        // Vertical splitter until the list of report is functional.
#if 0
        avail_size = ImGui::GetContentRegionAvail();

        static float vertical_split_pos = avail_size.x / 3; // Position the splitter at the third of the area.

        ImGui::SplitterVertical(splitter_width, &vertical_split_pos, 0, avail_size.x, avail_size.y);
        // Top Left
        {
            ImGui::BeginChild("TopLeft", ImVec2(vertical_split_pos, avail_size.y));

            ImGui::Text("@TODO list of report file here.");

            ImGui::EndChild();
        }

        ImGui::SameLine();
#endif
        // Top Right
        {
            show_report_grid();
        }

        ImGui::EndChild();
    }
    // Dummy to add some padding and avoid the following window overlapping the splitter.
    // I'm not sure why it's necessary.
    ImGui::Dummy(ImVec2(0, 0));
    {
        // We want the left side to take as much space as possible.
        float expand_y = -FLT_MIN;
        // We want to keep a margin to display the information line the selected line, position, selection etc.
        float expand_x_but_keep_a_margin_of = -ImGui::GetTextLineHeightWithSpacing();
        ImGui::BeginChild("Bottom", ImVec2(expand_y, expand_x_but_keep_a_margin_of), ImGuiChildFlags_Borders | ImGuiChildFlags_FrameStyle, ImGuiWindowFlags_NoNav);

        show_source_file();

        ImGui::EndChild();
    }
}

enum report_table_column {
    report_table_column_PERCENT,
    report_table_column_COUNTER,
    report_table_column_FILE_ICON,
    report_table_column_SYMBOL,
    report_table_column_MODULE,
    report_table_column_FILE,
    report_table_column_COUNT
};

void gui::show_report_grid()
{
    if (!report)
        return;

    size_t sample_count = report->sample_count;
    summed_record* items = report->summary_by_count.data;
    size_t items_count = report->summary_by_count.size;

    static ImGuiTableFlags flags =
        ImGuiTableFlags_ScrollX
        | ImGuiTableFlags_ScrollY
        | ImGuiTableFlags_Borders
        | ImGuiTableFlags_Resizable
        | ImGuiTableFlags_Reorderable
        | ImGuiTableFlags_Sortable
        | ImGuiTableFlags_Hideable;

    struct col_info {
        const char* name;
        int flags;
        float initial_width; // 0.0f means auto
    } columns[report_table_column_COUNT] = {
        { "%",       ImGuiTableColumnFlags_WidthFixed | ImGuiTableColumnFlags_NoHide, 0.0f },
        { "Counter", ImGuiTableColumnFlags_DefaultSort | ImGuiTableColumnFlags_PreferSortDescending, 0.0f},
        { ICON_LC_FILE_CODE,   ImGuiTableColumnFlags_WidthFixed | ImGuiTableColumnFlags_NoSort, 0.0f },
        { "Symbol",  ImGuiTableColumnFlags_WidthFixed, 180.0f },
        { "Module",  0, 0.0f },
        { "File",    0, 0.0f },
    };

    if (ImGui::BeginTable("report_table", report_table_column_COUNT, flags))
    {
        ImGui::TableSetupScrollFreeze(1, 1);
        for (int i = 0; i < report_table_column_COUNT; i += 1)
        {
            if (columns[i].initial_width > 0.0f)
            {
                ImGui::TableSetupColumn(columns[i].name, columns[i].flags, columns[i].initial_width);
            }
            else
            {
                ImGui::TableSetupColumn(columns[i].name, columns[i].flags);
            }
        }
        ImGui::TableHeadersRow();

        // Sort data only if sort specs have been changed!
        if (ImGuiTableSortSpecs* sort_specs = ImGui::TableGetSortSpecs())
        {
            if (sort_specs->SpecsDirty)
            {
                report_table_sort_with_sort_specs(sort_specs, items, items_count);
                sort_specs->SpecsDirty = false;
            }
        }

        double inverse_items_count = 1.0f / (double)sample_count * 100.0f;
        for (int row_index = 0; row_index < items_count; row_index += 1)
        {
            summed_record item = items[row_index];
            ImGui::TableNextRow();
            ImGui::TableSetColumnIndex(0);

            static strv unknown_file_location = STRV("<unknown-file-location>");
            static strv unknown_symbol = STRV("<unknown-symbol>");
            static strv unknown_module = STRV("<unknown-module>");

            bool has_file = item.source_file_name.size > 0;
            strv filepath = item.source_file_name.size ? item.source_file_name : unknown_file_location;
            strv filename = has_file ? path_get_last_segment(item.source_file_name) : filepath;
            strv symbol = item.symbol_name.size ? item.symbol_name : unknown_symbol;
            strv mobule = item.module_name.size ? item.module_name : unknown_module;

            bool jump_to_line = false;
            // Make row selectable
            {
                static void* selected = 0;
                ImGuiSelectableFlags selectable_flags = ImGuiSelectableFlags_SpanAllColumns | ImGuiSelectableFlags_AllowOverlap;
                char buf[128];
                snprintf(buf, 64, "##%p", item.symbol_name.data);

                bool is_selected = item.symbol_name.data == selected;

                if (ImGui::Selectable(buf, is_selected, selectable_flags))
                {
                    selected = (void*)item.symbol_name.data;
                }

                // @FIXME: It does not feel right to display a hoverable tooltip.
                // Insteda display details in a tooltip bar below the grid.
                if (ImGui::IsItemHovered(ImGuiHoveredFlags_DelayNormal) && item.closest_line_number != 0)
                {
                    ImGui::SetTooltip(STRV_FMT " | " STRV_FMT " | line: %zu", STRV_ARG(mobule), STRV_ARG(filename), item.closest_line_number);
                }

                // Jump to file and go to specified line on double click.
                if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
                {
                    jump_to_line = true;
                }

                ImGui::SameLine();
            }

            ImGui::Text("%.2f", (double)item.counter * inverse_items_count);

            // Display counter
            {
                ImGui::TableSetColumnIndex(1);
                ImGui::Text("%zu", item.counter);
            }

            // Display icon.
            {
                ImGui::TableSetColumnIndex(2);

                if (has_file)
                {
                    char buf[32];
                    snprintf(buf, 32, ICON_LC_FILE_CODE "##%p", item.symbol_name.data); // ### operator override ID ignoring the preceding label

                    if (ImGui::IconButton(buf))
                    {
                        jump_to_line = true;
                    }
                    if (ImGui::IsItemHovered(ImGuiHoveredFlags_DelayNone))
                    {
                        ImGui::SetTooltip("Open file: " STRV_FMT, STRV_ARG(filepath));
                    }
                }
            }

            // Display symbol name.
            {
                ImGui::TableSetColumnIndex(3);
                ImGui::Text(STRV_FMT, STRV_ARG(symbol));
            }

            // Display module name.
            {
                ImGui::TableSetColumnIndex(4);
                ImGui::Text(STRV_FMT, STRV_ARG(mobule));
            }

            // Display file name.
            {
                ImGui::TableSetColumnIndex(5);
                ImGui::Text(STRV_FMT, STRV_ARG(filepath));
            }

            if (jump_to_line)
            {
                jump_to_file(item.source_file_name, item.closest_line_number);
            }
        }
        ImGui::EndTable();
    }
}

void gui::show_source_file()
{
    text_viewer.render();
}

namespace helpers {
    
    void report_table_sort_with_sort_specs(ImGuiTableSortSpecs* sort_specs, summed_record* items, size_t items_count)
    {
        if (items_count > 1)
        {
            current_sort_specs = sort_specs; // Store in variable accessible by the process_table_sort function.
            qsort(items, items_count, sizeof(items[0]), report_table_sort);
            current_sort_specs = NULL;
        }
    }

    int report_table_sort(const void* left_ptr, const void* right_ptr)
    {
        const summed_record* left = (const summed_record*)left_ptr;
        const summed_record* right = (const summed_record*)right_ptr;

        for (int n = 0; n < current_sort_specs->SpecsCount; n += 1)
        {
            // Here we identify columns using the ColumnUserID value that we ourselves passed to TableSetupColumn()
            // We could also choose to identify columns based on their index (sort_spec->ColumnIndex), which is simpler!
            const ImGuiTableColumnSortSpecs* sort_spec = &current_sort_specs->Specs[n];
            int delta = 0;
            switch (sort_spec->ColumnIndex)
            {
                // Sort by percentage is equivalent to sort by counter.
            case report_table_column_PERCENT:
                // FALLTRHOUGH
            case report_table_column_COUNTER: {
                delta = (int)(left->counter - right->counter);
                break;
            }
            case report_table_column_SYMBOL: {
                delta = strv_lexicagraphical_compare(left->symbol_name, right->symbol_name);
                break;
            }
            case report_table_column_MODULE: {
                delta = strv_lexicagraphical_compare(left->module_name, right->module_name);
                break;
            }
            case report_table_column_FILE: {
                delta = strv_lexicagraphical_compare(left->source_file_name, right->source_file_name);
                break;
            }
            default: {
                SMP_ASSERT(0);
                break;
            }
            }
            if (delta > 0)
                return (sort_spec->SortDirection == ImGuiSortDirection_Ascending) ? +1 : -1;
            if (delta < 0)
                return (sort_spec->SortDirection == ImGuiSortDirection_Ascending) ? -1 : +1;
        }

        if (left->counter < right->counter)
            return -1;
        if (left->counter > right->counter)
            return 1;
        return 0;
    }

    static void render_extra_line_information(tv::options* options, int line_number, int visible_line_max, bool line_is_selected)
    {
        // Render line number
        tv::default_line_prelude_renderer(options, line_number, visible_line_max, line_is_selected);

        gui* g = (gui*)options->line_prelude_user_data;
        record_range* range = &g->records_of_current_file;

        size_t record_count = range->end - range->begin;

        // Get all records for the line specified.
        record_range lines = record_range_for_line(range->begin, record_count, line_number);

        size_t count = 0;
        // Agreggate all sampling count for this line.
        {
            record* cursor = lines.begin;
            while (cursor < lines.end)
            {
                count += cursor[0].counter;
                cursor += 1;
            }
        }

        // Display percentage of sampling count.
        {
            int color = count ? ImGuiCol_PlotHistogram : ImGuiCol_PlotLines;
            float percent = ((float)count / (float)g->report->sample_count) * 100.0f;

            char buf[16];
            int buf_len = snprintf(buf, 16, "%.2f %%", percent);

            tv::render_text_line(buf, buf + buf_len, ImVec2(), ImGui::GetColorU32(color));
            ImGui::SameLine();
            // Display more accurage percentage and the actual sampling count.
            if (ImGui::IsItemHovered(ImGuiHoveredFlags_DelayNone))
            {
                ImGui::SetTooltip("%.4f - %zu", percent, count);
            }
        }
    }

    // Helpers
    //

    static bool is_slash(char c)
    {
        return	(c == '/' || c == '\\');
    }

    static bool find_last_slash(strv path, size_t* index)
    {
        const char* cursor;
        const char* begin;

        char c;

        cursor = path.data + path.size - 1; // set the cursor to the last char
        begin = path.data;

        while (cursor > begin) {
            c = *cursor;
            if (c == '\\' || c == '/')
            {
                *index = (cursor - begin);
                return true;
            }
            --cursor;
        }

        return false;
    }

    strv path_get_last_segment(strv path)
    {
        if (path.size <= 0)
            return strv_make();

        strv result = path;
        if (is_slash(strv_back(result)))
        {
            result.size -= 1; /* Remove last slash, so that it does not get counted in the next find_last_slash */
        }

        size_t last_separator_start_pos;
        if (!find_last_slash(result, &last_separator_start_pos))
        {
            return result; /* No separator found, return the original path */
        }

        size_t new_size = last_separator_start_pos + 1; /* new_size = index + 1 */
        result.data = result.data + new_size;
        result.size = result.size - new_size;

        return result;
    }

} // namespace ui
