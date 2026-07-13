#include "wet.h"

#ifdef WET_PLATFORM_WINDOWS

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include <windows.h>
#include "wet/log.h"
#include "wet/window.h"

// Função que cria a janela no windows com o win32
bool win32_window_create(WindowConfig config)
{
    HINSTANCE instance = GetModuleHandleA(0);

    WNDCLASS wc = {0};
    wc.hInstance = instance;
    wc.hIcon = LoadIcon(instance, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = config.title;
    wc.lpfnWndProc = DefWindowProcA;

    if (!RegisterClassA(&wc))
    {
        LOG_FATAL("FALHA AO REGISTRAR A CLASSE DO WIN32! código: %lu\n", GetLastError());
        return false;
    }

    int dwStyle = WS_OVERLAPPEDWINDOW;

    HWND window = CreateWindowExA(
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

void win32_window_update(void) {};
void win32_window_destroy(void) {};

bool win32_window_should_close(void) {return false;}

#endif