#include "gui.hpp"

#include <stdlib.h> // qsort

#include "imgui_extensions.h"

#include "samply.h"
#include "report.h"

struct config {

    // Help - Debug
    //
    bool open_main_window_full_screen = true;
    bool open_imgui_demo_window = false;

    // About
    //
    bool open_about_window = false;

    // Misc
    //

    // To sort tables.
    const ImGuiTableSortSpecs* current_sort_specs = 0;
};

static config cfg;

// Forward function declarations

namespace ui {

    // Menu
    //
    static void show_main_menu_bar();

    // Menu - About
    //
    static void show_about(bool* p_open);

    // Main Window
    //
    static void show_main_window(report* report);
    static void show_full_screen_window_body(report* report);

    // Main Window - report Tab
    //
    static void show_report_tab(report* report);
    static void show_report_grid(report* report);

    static void report_table_sort_with_sort_specs(ImGuiTableSortSpecs* sort_specs, summed_record* items, int items_count);
    static int report_table_sort(const void* left, const void* right);
}

namespace ui {

    // Menu
    //
    static void show_main_menu_bar()
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

    // Menu - About
    //
    static void show_about(bool* p_open)
    {
        if (ImGui::Begin("About Samply", p_open, ImGuiWindowFlags_AlwaysAutoResize))
        {
            ImGui::Text("Samply %s (%d)", SMP_APP_VERSION_TEXT, SMP_APP_VERSION_NUMBER);

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
            ImGui::Text("Samply is licensed under the MIT License");
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

    // Main Window
    //
    static void show_main_window(report* report)
    {
        bool use_work_area = false;
        
        // Main windows always stayed buried behind all other windows.
        ImGuiWindowFlags flags = ImGuiWindowFlags_NoBringToFrontOnFocus;

        if (cfg.open_main_window_full_screen)
        {
            flags |= ImGuiWindowFlags_NoDecoration
                | ImGuiWindowFlags_NoMove
                | ImGuiWindowFlags_NoSavedSettings;

            // Remove border
            ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);

            use_work_area = true;
            // We demonstrate using the full viewport area or the work area (without menu-bars, task-bars etc.)
            // Based on your use case you may want one or the other.
            const ImGuiViewport* viewport = ImGui::GetMainViewport();
            ImGui::SetNextWindowPos(viewport->WorkPos);
            ImGui::SetNextWindowSize(viewport->WorkSize);
        }

        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

        bool always_opened = true;
        if (ImGui::Begin("Main Window", &always_opened, flags))
        {
            ImGui::PopStyleVar(); // Restore WindowPadding.

            show_full_screen_window_body(report);
        }
        ImGui::End();

        if (cfg.open_main_window_full_screen)
        {
            ImGui::PopStyleVar(1);
        }
    }

    static void show_full_screen_window_body(report* report)
    {
        ImGuiTabBarFlags tab_bar_flags = ImGuiTabBarFlags_None;
        if (ImGui::BeginTabBar("MainTabBar", tab_bar_flags))
        {
            // Remove spacing under the tab bar
            ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0.0f, 0.0f));

            if (ImGui::BeginTabItem("Reports"))
            {
                ImGui::PopStyleVar(1); // Restore item spacing.
                
                show_report_tab(report);

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

    // Main Window - Report Tab
    //

    static void show_report_tab(report* report)
    {
        const ImGuiStyle& style = ImGui::GetStyle();
        auto avail_size = ImGui::GetContentRegionAvail();

        static float horiz_split_pos = avail_size.y / 2.0f; // Position the splitter at the third of the area.

        float min_pos = 0 + style.WindowPadding.y;
        float max_pos = avail_size.y - (style.WindowPadding.y * 2);
        if (max_pos < min_pos)
            max_pos = min_pos;

        ImGui::SplitterHorizontal(8.0f, &horiz_split_pos, min_pos, max_pos, avail_size.x);
        {
            ImGui::BeginChild("Top", ImVec2(avail_size.x, horiz_split_pos));

            avail_size = ImGui::GetContentRegionAvail();

            float min_pos_ = 0 + style.WindowPadding.x;
            float max_pos_ = avail_size.x - (style.WindowPadding.x * 2);
            if (max_pos_ < min_pos_)
                max_pos_ = min_pos;

            static float vertical_split_pos = avail_size.x / 3; // Position the splitter at the third of the area.

            ImGui::SplitterVertical(8.0f, &vertical_split_pos, min_pos_, max_pos_, avail_size.y);
            // Top Left
            {
                ImGui::BeginChild("TopLeft", ImVec2(vertical_split_pos, avail_size.y));
                    
                ImGui::Text("@TODO list of report file here.");

                ImGui::EndChild();
            }
            ImGui::SameLine();
            // Top Right
            {
                show_report_grid(report);
            }
           
            ImGui::EndChild();
        }
            
        {
            ImGui::BeginChild("Bottom", ImVec2(0, 0), ImGuiChildFlags_AlwaysUseWindowPadding);

            ImGui::Text("@TODO Display source code of selected file here.");

            ImGui::EndChild();
        }
    }

    enum report_table_column {
        report_table_column_PERCENT,
        report_table_column_COUNTER,
        report_table_column_SYMBOL,
        report_table_column_MODULE,
        report_table_column_FILE,
        report_table_column_COUNT
    };

    static void show_report_grid(report* report)
    {
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
        } columns[report_table_column_COUNT] = {
            { "%",       ImGuiTableColumnFlags_WidthFixed | ImGuiTableColumnFlags_NoHide },
            { "Counter", ImGuiTableColumnFlags_DefaultSort | ImGuiTableColumnFlags_PreferSortDescending },
            { "Symbol",  0 },
            { "Module",  0 },
            { "File",    0 },
        };

        if (ImGui::BeginTable("report_table", report_table_column_COUNT, flags))
        {
            ImGui::TableSetupScrollFreeze(1, 1);
            for (int i = 0; i < report_table_column_COUNT; i += 1)
            {
                ImGui::TableSetupColumn(columns[i].name, columns[i].flags);
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

            double inverse_items_count = 1.0 / (double)sample_count;
            for (int row_index = 0; row_index < items_count; row_index += 1)
            {
                summed_record item = items[row_index];
                ImGui::TableNextRow();
                ImGui::TableSetColumnIndex(0);

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
                    ImGui::SameLine();
                }
                
                ImGui::Text("%.2f", (double)item.counter * inverse_items_count);
                ImGui::TableSetColumnIndex(1);
                ImGui::Text("%zu", item.counter);
                ImGui::TableSetColumnIndex(2);
                ImGui::Text(STRV_FMT, STRV_ARG(item.symbol_name));
                ImGui::TableSetColumnIndex(3);
                ImGui::Text(STRV_FMT, STRV_ARG(item.module_name));
                ImGui::TableSetColumnIndex(4);
                ImGui::Text(STRV_FMT, STRV_ARG(item.source_file_name));
            }
            ImGui::EndTable();
        }
    }

    static void report_table_sort_with_sort_specs(ImGuiTableSortSpecs* sort_specs, summed_record* items, int items_count)
    {
        if (items_count > 1)
        {
            cfg.current_sort_specs = sort_specs; // Store in variable accessible by the process_table_sort function.
            qsort(items, (size_t)items_count, sizeof(items[0]), report_table_sort);
            cfg.current_sort_specs = NULL;
        }
    }

    static int report_table_sort(const void* left_ptr, const void* right_ptr)
    {
        const summed_record* left = (const summed_record*)left_ptr;
        const summed_record* right = (const summed_record*)right_ptr;
      
        for (int n = 0; n < cfg.current_sort_specs->SpecsCount; n += 1)
        {
            // Here we identify columns using the ColumnUserID value that we ourselves passed to TableSetupColumn()
            // We could also choose to identify columns based on their index (sort_spec->ColumnIndex), which is simpler!
            const ImGuiTableColumnSortSpecs* sort_spec = &cfg.current_sort_specs->Specs[n];
            int delta = 0;
            switch (sort_spec->ColumnUserID)
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
};

int gui::main()
{
    using namespace ui;

    show_main_menu_bar();

    show_main_window(this->report);

    if (cfg.open_about_window)
    {
       show_about(&cfg.open_about_window);
    }

    if (cfg.open_imgui_demo_window)
    {
        ImGui::ShowDemoWindow(&cfg.open_imgui_demo_window);
    }

    return 0;
}
