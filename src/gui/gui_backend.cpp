#include "gui.hpp"

// This Dear imagui backend was a revamped of https://github.com/ocornut/imgui/blob/master/examples/example_win32_opengl3/main.cpp
//
// Likely an important comment from the original code:
// 
//    This is provided for completeness, however it is strongly recommended you use OpenGL with SDL or GLFW.
//

#if _WIN32
#include "imgui_plus_extensions.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_win32.h"
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#include <strsafe.h> /* StringCchVPrintfW */
#include <GL/GL.h>
#include <tchar.h>
#include "stdio.h"

#include "samply.h"
#include "utils/log.h"

#define TO_STR(str) L ## str
#define STR(str) TO_STR(str)

#else

error "@TODO Handle UNIX-like system"

#define STR(str) str

#endif

// Data stored per platform window
struct WGL_WindowData { HDC hDC; };

struct global_data {
    HGLRC            hRC = 0;
    WGL_WindowData   MainWindow = {0};
    int              Width = 0;
    int              Height = 0;

    // To format wchar_t strings with "tmp_fmt".
    static const int tmp_buffer_MAX = 1024;
    wchar_t buffer[tmp_buffer_MAX] = {0};
    const wchar_t* buffer_error = L"<error>";

    const wchar_t* app_name = STR(SMP_APP_NAME);
    const wchar_t* icon_wide_path = STR(SMP_ICON_PATH_LITERAL);
    const char* icon_utf8_path = SMP_ICON_PATH_LITERAL;
};

static global_data g;

// Forward declarations of helper functions
static const wchar_t* tmp_fmt(const wchar_t* fmt, ...);
static bool CreateDeviceWGL(HWND hWnd, WGL_WindowData* data);
static void CleanupDeviceWGL(HWND hWnd, WGL_WindowData* data);
static LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

typedef BOOL(WINAPI* PFNWGLSWAPINTERVALEXTPROC)(int);

strv gui_backend::identifier()
{
    static strv id = STRV("Dear ImGui/Win32/OpenGL3");
    return id;
}

void gui_backend::set_initial_position(int x, int y)
{
    initial_x = x;
    initial_y = y;
}

void gui_backend::set_initial_size(int width, int height)
{
    initial_width = width;
    initial_height = height;
}

int gui_backend::show()
{
    // Create application window
    //ImGui_ImplWin32_EnableDpiAwareness();
    WNDCLASSEXW wc = { sizeof(wc), CS_OWNDC, WndProc, 0L, 0L, GetModuleHandle(nullptr), nullptr, nullptr, nullptr, nullptr, g.app_name, nullptr };
    
    // Load the icon from a file
    HICON hIcon = (HICON)LoadImage(NULL, g.icon_wide_path, IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
    if (hIcon == NULL)
    {
        log_error("Could not load icon: %s", g.icon_utf8_path);
    }
    else
    {
        wc.hIcon = hIcon;
    }

    ::RegisterClassExW(&wc);

    const wchar_t* title = tmp_fmt(STR("%s %s (%d)"),
        STR(SMP_APP_NAME),
        STR(SMP_APP_VERSION_TEXT),
        SMP_APP_VERSION_NUMBER);

    HWND hwnd = ::CreateWindowW(
        // LPCWSTR lpClassName, LPCWSTR lpWindowName, DWORD dwStyle
        wc.lpszClassName, title, WS_OVERLAPPEDWINDOW, 
        // int X, int Y, int nWidth, int nHeight
        initial_x, initial_y, initial_width, initial_height,
        // HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam
        nullptr, nullptr, wc.hInstance, nullptr);

    // Initialize OpenGL
    if (!CreateDeviceWGL(hwnd, &g.MainWindow))
    {
        CleanupDeviceWGL(hwnd, &g.MainWindow);
        ::DestroyWindow(hwnd);
        ::UnregisterClassW(wc.lpszClassName, wc.hInstance);
        return 1;
    }
    wglMakeCurrent(g.MainWindow.hDC, g.hRC);

    // Set V-sync
    PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC)wglGetProcAddress("wglSwapIntervalEXT");
    if (wglSwapIntervalEXT)
    {
        wglSwapIntervalEXT(1);
    }

    // Show the window
    ::ShowWindow(hwnd, SW_SHOWDEFAULT);
    ::UpdateWindow(hwnd);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;   // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;    // Enable Gamepad Controls

    // Setup Platform/Renderer backends
    ImGui_ImplWin32_InitForOpenGL(hwnd);
    ImGui_ImplOpenGL3_Init();

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    // Setup custom style
    ImGuiEx::ApplyCustomTheme();
    ImGuiEx::TryLoadCustomFonts();

    // Our state

    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    int exit_code = 0;

    // Main loop
    bool done = false;
    while (!done)
    {
        // Poll and handle messages (inputs, window resize, etc.)
        // See the WndProc() function below for our to dispatch events to the Win32 backend.
        MSG msg;
        while (::PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
            if (msg.message == WM_QUIT)
                done = true;
        }
        if (done)
            break;
        if (::IsIconic(hwnd))
        {
            ::Sleep(10);
            continue;
        }

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        exit_code = show_core();

        // Rendering
        ImGui::Render();
        glViewport(0, 0, g.Width, g.Height);
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Present
        ::SwapBuffers(g.MainWindow.hDC);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    // Clean up and free the icon resource
    if (hIcon)
    {
        DestroyIcon(hIcon);
    }

    CleanupDeviceWGL(hwnd, &g.MainWindow);
    wglDeleteContext(g.hRC);
    ::DestroyWindow(hwnd);
    ::UnregisterClassW(wc.lpszClassName, wc.hInstance);

    return exit_code;
}

//
// Helper functions
// 

// Return buffer_error in case something went wrong.
static const wchar_t* tmp_fmt(const wchar_t* fmt, ...)
{
    va_list valist;
    va_start(valist, fmt);

    HRESULT h = StringCchVPrintfW(g.buffer, g.tmp_buffer_MAX, fmt, valist);

    va_end(valist);

    return h == S_OK ? g.buffer : g.buffer_error;
}

static bool CreateDeviceWGL(HWND hWnd, WGL_WindowData* data)
{
    HDC hDc = ::GetDC(hWnd);
    PIXELFORMATDESCRIPTOR pfd = { 0 };
    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;

    const int pf = ::ChoosePixelFormat(hDc, &pfd);
    if (pf == 0)
        return false;
    if (::SetPixelFormat(hDc, pf, &pfd) == FALSE)
        return false;
    ::ReleaseDC(hWnd, hDc);

    data->hDC = ::GetDC(hWnd);
    if (!g.hRC)
        g.hRC = wglCreateContext(data->hDC);
    return true;
}

static void CleanupDeviceWGL(HWND hWnd, WGL_WindowData* data)
{
    wglMakeCurrent(nullptr, nullptr);
    ::ReleaseDC(hWnd, data->hDC);
}

// Forward declare message handler from imgui_impl_win32.cpp
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Win32 message handler
// You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
// - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
// - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
// Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
static LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (wParam != SIZE_MINIMIZED)
        {
            g.Width = LOWORD(lParam);
            g.Height = HIWORD(lParam);
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:
        ::PostQuitMessage(0);
        return 0;
    }
    return ::DefWindowProcW(hWnd, msg, wParam, lParam);
}
