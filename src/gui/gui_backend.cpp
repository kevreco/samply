#include "gui.hpp"

// Dear ImGui: standalone example application for Win32 + OpenGL 3

// Learn about Dear ImGui:
// - FAQ                  https://dearimgui.com/faq
// - Getting Started      https://dearimgui.com/getting-started
// - Documentation        https://dearimgui.com/docs (same as your local docs/ folder).
// - Introduction, links and more at the top of imgui.cpp

// This is provided for completeness, however it is strongly recommended you use OpenGL with SDL or GLFW.

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
//#include <GL/glext.h>
#include <tchar.h>
#include "stdio.h"

#include "samply.h"

#define TO_STR(str) L ## str
#define STR(str) TO_STR(str)

#else

error "@TODO Handle UNIX-like system"

#define STR(str) str

#endif

auto app_name = STR(SMP_APP_NAME);
auto icon_path = STR("./resources/samply.ico");
auto icon_name = "./resources/samply.ico";

struct {
    int x, y, width, height;
} rect = {
    100, 100, 720, 540
};

// To format wchar_t strings with "tmp_fmt".
static const int tmp_buffer_MAX = 1024;
static wchar_t buffer[tmp_buffer_MAX];
static wchar_t buffer_error[] = L"<error>";

// Data stored per platform window
struct WGL_WindowData { HDC hDC; };

// Data
static HGLRC            g_hRC;
static WGL_WindowData   g_MainWindow;
static int              g_Width;
static int              g_Height;

// Forward declarations of helper functions
static wchar_t* tmp_fmt(const wchar_t* fmt, ...);
static bool CreateDeviceWGL(HWND hWnd, WGL_WindowData* data);
static void CleanupDeviceWGL(HWND hWnd, WGL_WindowData* data);
static LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

typedef BOOL(WINAPI* PFNWGLSWAPINTERVALEXTPROC)(int);
PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT;

strv gui::backend_identifier()
{
    static strv id = STRV("Dear ImGui/Win32/OpenGL3");
    return id;
}

int gui::show()
{
    // Create application window
    //ImGui_ImplWin32_EnableDpiAwareness();
    WNDCLASSEXW wc = { sizeof(wc), CS_OWNDC, WndProc, 0L, 0L, GetModuleHandle(nullptr), nullptr, nullptr, nullptr, nullptr, app_name, nullptr };
    
    // Load the icon from a file
    HICON hIcon = (HICON)LoadImage(NULL, icon_path, IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
    if (hIcon == NULL)
    {
        fprintf(stderr, "Could not load icon: %s\n", icon_name);
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

    HWND hwnd = ::CreateWindowW(wc.lpszClassName, title, WS_OVERLAPPEDWINDOW, rect.x, rect.y, rect.width, rect.height, nullptr, nullptr, wc.hInstance, nullptr);

    // Initialize OpenGL
    if (!CreateDeviceWGL(hwnd, &g_MainWindow))
    {
        CleanupDeviceWGL(hwnd, &g_MainWindow);
        ::DestroyWindow(hwnd);
        ::UnregisterClassW(wc.lpszClassName, wc.hInstance);
        return 1;
    }
    wglMakeCurrent(g_MainWindow.hDC, g_hRC);
    // Set V-sync
    wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC)wglGetProcAddress("wglSwapIntervalEXT");
    wglSwapIntervalEXT(1);

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
    ImGui::ApplyCustomTheme();
    ImGui::LoadFonts();

    // Load Fonts
    // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
    // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
    // - If the file cannot be loaded, the function will return a nullptr. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
    // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
    // - Use '#define IMGUI_ENABLE_FREETYPE' in your imconfig file to use Freetype for higher quality font rendering.
    // - Read 'docs/FONTS.md' for more instructions and details.
    // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
    //io.Fonts->AddFontDefault();
    //io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\segoeui.ttf", 18.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
    //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, nullptr, io.Fonts->GetGlyphRangesJapanese());
    //IM_ASSERT(font != nullptr);

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

        exit_code = main();

        // Rendering
        ImGui::Render();
        glViewport(0, 0, g_Width, g_Height);
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Present
        ::SwapBuffers(g_MainWindow.hDC);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    // Clean up and free the icon resource
    if (hIcon)
    {
        DestroyIcon(hIcon);
    }

    CleanupDeviceWGL(hwnd, &g_MainWindow);
    wglDeleteContext(g_hRC);
    ::DestroyWindow(hwnd);
    ::UnregisterClassW(wc.lpszClassName, wc.hInstance);

    return exit_code;
}

//
// Helper functions
// 

// Return buffer_error in case something went wrong.
static wchar_t* tmp_fmt(const wchar_t* fmt, ...)
{
    va_list valist;
    va_start(valist, fmt);

    HRESULT h = StringCchVPrintfW(buffer, tmp_buffer_MAX, fmt, valist);

    va_end(valist);

    return h == S_OK ? buffer : buffer_error;
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
    if (!g_hRC)
        g_hRC = wglCreateContext(data->hDC);
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
            g_Width = LOWORD(lParam);
            g_Height = HIWORD(lParam);
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
