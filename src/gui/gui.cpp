#include "gui.hpp"

#include "imgui.h"

#include "../samply.h"

struct config {

    // Help - Debug
    //
    bool open_main_window_full_screen = true;
    bool open_imgui_demo_window = false;

    // About
    //
    bool open_about_window = false;

};

static config cfg;

// Forward function declarations

namespace ui {

    // Menu
    //
    static void show_main_menu_bar();

    // Menu - Debug
    //
    static void show_full_screen_window_body();

    // Menu - About
    //
    static void show_about(bool* p_open);

    // Main Window
    //
    static void show_main_window();
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
    static void show_main_window()
    {
        
        bool use_work_area = false;
        
        // Main windows always stayed buried behind all other windows.
        ImGuiWindowFlags flags = ImGuiWindowFlags_NoBringToFrontOnFocus;

        if (cfg.open_main_window_full_screen)
        {
            flags |= ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings;

            use_work_area = true;
            // We demonstrate using the full viewport area or the work area (without menu-bars, task-bars etc.)
            // Based on your use case you may want one or the other.
            const ImGuiViewport* viewport = ImGui::GetMainViewport();
            ImGui::SetNextWindowPos(viewport->WorkPos);
            ImGui::SetNextWindowSize(viewport->WorkSize);
        }

        bool always_opened = true;
        if (ImGui::Begin("Example: Fullscreen window", &always_opened, flags))
        {
            
            show_full_screen_window_body();
        }
        ImGui::End();
    }

    static void show_full_screen_window_body()
    {
        ImGuiTabBarFlags tab_bar_flags = ImGuiTabBarFlags_None;
        if (ImGui::BeginTabBar("MyTabBar", tab_bar_flags))
        {
            if (ImGui::BeginTabItem("Reports"))
            {
                ImGui::Text("@TODO: Display summary report.");
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem("Processes"))
            {
                ImGui::Text("@TODO: Display list of running process.");
                ImGui::EndTabItem();
            }
            ImGui::EndTabBar();
        }
    }

};

int gui::main()
{
    using namespace ui;

    show_main_menu_bar();

    show_main_window();

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
