#ifndef IMGUI_EXTENSIONS_H
#define IMGUI_EXTENSIONS_H

#define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui.h"
#include "imgui_internal.h"

// NOTE: This file is not part of imgui.

namespace ImGui {

    // This SplitterBehavior is an alternative version of the one posted on Dear ImGui github:
    //    https://github.com/ocornut/imgui/issues/319#issuecomment-345795629
    // This new version fits my need more.
    static bool SplitterBehavior(const ImRect& bb, ImGuiID id, ImGuiAxis axis, float* pos, float min_position, float max_position, float hover_extend = 0.0f, float hover_visibility_delay = 0.0f, ImU32 bg_col = 0)
    {
        IM_ASSERT(min_position <= max_position);

        ImGuiContext& g = *GImGui;
        ImGuiWindow* window = g.CurrentWindow;

        if (!ItemAdd(bb, id, NULL, ImGuiItemFlags_NoNav))
            return false;

        // FIXME: AFAIK the only leftover reason for passing ImGuiButtonFlags_AllowOverlap here is
        // to allow caller of SplitterBehavior() to call SetItemAllowOverlap() after the item.
        // Nowadays we would instead want to use SetNextItemAllowOverlap() before the item.
        ImGuiButtonFlags button_flags = ImGuiButtonFlags_FlattenChildren;
#ifndef IMGUI_DISABLE_OBSOLETE_FUNCTIONS
        button_flags |= ImGuiButtonFlags_AllowOverlap;
#endif

        bool hovered, held;
        ImRect bb_interact = bb;
        bb_interact.Expand(axis == ImGuiAxis_Y ? ImVec2(0.0f, hover_extend) : ImVec2(hover_extend, 0.0f));
        ButtonBehavior(bb_interact, id, &hovered, &held, button_flags);
        if (hovered)
            g.LastItemData.StatusFlags |= ImGuiItemStatusFlags_HoveredRect; // for IsItemHovered(), because bb_interact is larger than bb

        if (held || (hovered && g.HoveredIdPreviousFrame == id && g.HoveredIdTimer >= hover_visibility_delay))
            SetMouseCursor(axis == ImGuiAxis_Y ? ImGuiMouseCursor_ResizeNS : ImGuiMouseCursor_ResizeEW);

        ImRect bb_render = bb;
        if (held)
        {
            float mouse_delta = (g.IO.MousePos - g.ActiveIdClickOffset - bb_interact.Min)[axis];

            if (mouse_delta < 0)
            {
                if (*pos + mouse_delta < min_position)
                {
                    mouse_delta = min_position - *pos;
                }
            }
            if (mouse_delta > 0)
            {
                if (*pos + mouse_delta > max_position)
                {
                    mouse_delta = max_position - *pos;
                }
            }

            // Apply resize
            if (mouse_delta != 0.0f)
            {
                *pos += mouse_delta;
                bb_render.Translate((axis == ImGuiAxis_X) ? ImVec2(mouse_delta, 0.0f) : ImVec2(0.0f, mouse_delta));

                MarkItemEdited(id);
            }
        }

        // Render at new position
        if (bg_col & IM_COL32_A_MASK)
            window->DrawList->AddRectFilled(bb_render.Min, bb_render.Max, bg_col, 0.0f);
        const ImU32 col = GetColorU32(held ? ImGuiCol_SeparatorActive : (hovered && g.HoveredIdTimer >= hover_visibility_delay) ? ImGuiCol_SeparatorHovered : ImGuiCol_Separator);
        window->DrawList->AddRectFilled(bb_render.Min, bb_render.Max, col, 0.0f);

        return held;
    }

    static bool SplitterVertical(float thickness, float* pos, float min_pos, float max_pos, float splitter_long_axis_size = -1.0f)
    {
        using namespace ImGui;
        ImGuiContext* g = GetCurrentContext();
        ImGuiWindow* window = g->CurrentWindow;
        ImGuiID id = window->GetID("##SplitterV");
        ImRect bb;
        bb.Min = window->DC.CursorPos + ImVec2(*pos, 0.0f);
        bb.Max = bb.Min + CalcItemSize(ImVec2(thickness, splitter_long_axis_size), 0.0f, 0.0f);
        return SplitterBehavior(bb, id, ImGuiAxis_X, pos, min_pos, max_pos, 0.0f);
    }

    static bool SplitterHorizontal(float thickness, float* pos, float min_pos, float max_pos, float splitter_long_axis_size = -1.0f)
    {
        using namespace ImGui;
        ImGuiContext* g = GetCurrentContext();
        ImGuiWindow* window = g->CurrentWindow;
        ImGuiID id = window->GetID("##SplitterH");
        ImRect bb;
        bb.Min = window->DC.CursorPos + ImVec2(0.0f, *pos);
        bb.Max = bb.Min + CalcItemSize(ImVec2(splitter_long_axis_size, thickness), 0.0f, 0.0f);
        return SplitterBehavior(bb, id, ImGuiAxis_Y, pos, min_pos, max_pos, 0.0f);
    }
}

#endif // IMGUI_EXTENSIONS_H