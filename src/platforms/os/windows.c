#include "wet.h"

#ifdef WET_PLATFORM_WINDOWS

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include <windows.h>
#include "wet/log.h"
#include "wet/window.h"

static bool window_running = true;
HWND window;

// Callback do windows
LRESULT CALLBACK win32_process_message(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    switch (msg)
    {
        case WM_CLOSE:
            window_running = false;
            DestroyWindow(hwnd);
            return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    
    // Qualquer mensagem que a gente não tratar, deixa o Windows resolver do jeito padrão
    return DefWindowProcA(hwnd, msg, wparam, lparam);
}

// Função que cria a janela no windows com o win32
bool win32_window_create(WindowConfig config)
{
    HINSTANCE instance = GetModuleHandleA(0);

    WNDCLASS wc = {0};
    wc.hInstance = instance;
    wc.hIcon = LoadIcon(instance, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = config.title;
    wc.lpfnWndProc = win32_process_message; // Callback pros inputs

    if (!RegisterClassA(&wc))
    {
        LOG_FATAL("FALHA AO REGISTRAR A CLASSE DO WIN32! código: %lu\n", GetLastError());
        return false;
    }

    int dwStyle = WS_OVERLAPPEDWINDOW;

    window = CreateWindowExA(
                    0,
                    config.title,
                    config.title,
                    dwStyle,
                    CW_USEDEFAULT, CW_USEDEFAULT,
                    config.width,
                    config.height,
                    NULL,
                    NULL,
                    instance,
                    NULL
                );
    if (window == NULL)
    {
        LOG_FATAL("FALHA AO CRIAR A JANELA DO WIN32! código: %lu\n", GetLastError());
        return false;
    }

    ShowWindow(window, SW_SHOW);
    
    return true;
}

void win32_window_update(void)
{
    MSG msg;

    while(PeekMessageA(&msg, window, 0, 0, PM_REMOVE))
    {
        TranslateMessage(&msg);
        DispatchMessageA(&msg); //Chama o callback que foi especificado quando criamos a janela
    }
};

void win32_window_destroy(void) {};

bool win32_window_should_close(void)
{
    return !window_running;
}

#endif