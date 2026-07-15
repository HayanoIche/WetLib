#include "wet.h"

#ifdef WET_PLATFORM_WINDOWS

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include <windows.h>
#include "wet/log.h"
#include "wet/window.h"
#include "wet/graphics.h"
#include "wet/time.h"

static bool window_running = true;

static HWND window = NULL;
static HDC hdc = NULL;
static HGLRC hglrc = NULL;

// ----------------------------------------------------------------------
//  Funções pra manejar a janela do win32
// ----------------------------------------------------------------------

// Callback do windows
LRESULT CALLBACK win32_process_message(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    switch (msg)
    {
        case WM_CLOSE:
            window_running = false;
            DestroyWindow(hwnd);
            return 0;
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
            break;

        case WM_SIZE: {
                uint32 width = LOWORD(lparam);
                uint32 height = HIWORD(lparam);
                
                graphics_on_resize(width, height);
                break;
            }
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
    wc.hbrBackground = NULL;
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
    LOG_INFO("Janela do win32 inicializada com sucesso!");
    
    // Iniciando o contador de tempo
    time_init();

    return true;
}

void win32_window_update(void)
{
    // Updatando o tempo
    time_update();

    // Window
    MSG msg;

    while(PeekMessageA(&msg, window, 0, 0, PM_REMOVE))
    {
        TranslateMessage(&msg);
        DispatchMessageA(&msg); //Chama o callback que foi especificado quando criamos a janela
    }
    
    SwapBuffers(hdc);
};

void win32_window_destroy(void)
{
    // Acabando com o contador de tempo
    time_shut();
};

bool win32_window_should_close(void)
{
    return !window_running;
}

// ----------------------------------------------------------------------
//  Implementação das funções do OPENGL
// ----------------------------------------------------------------------

bool win32_opengl_graphics_init(void) 
{
    hdc = GetDC(window);

    PIXELFORMATDESCRIPTOR pfd = {
        .nSize = sizeof(PIXELFORMATDESCRIPTOR),
        .nVersion = 1,
        .dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
        .iPixelType = PFD_TYPE_RGBA,
        .cColorBits = 32,
        .cDepthBits = 24,
        .cStencilBits = 8,
        .iLayerType = PFD_MAIN_PLANE
    };

    int pixelFormat = ChoosePixelFormat(hdc, &pfd);
    SetPixelFormat(hdc, pixelFormat, &pfd);

    // CRIA O CONTEXTO OPENGL REAL DO WINDOWS
    hglrc = wglCreateContext(hdc);
    if (!hglrc) return false;

    // Faz o contexto ficar ativo na nossa thread atual
    wglMakeCurrent(hdc, hglrc);

    return true;
}

void* win32_opengl_get_proc_address(const char* procname)
{
    void* p = (void*)wglGetProcAddress(procname);
    if (p == 0 || (p == (void*)0x1) || (p == (void*)0x2) || (p == (void*)0x3) || (p == (void*)-1))
    {
        static HMODULE module = NULL;
        if (module == NULL) {
            module = LoadLibraryA("opengl32.dll");
        }
        p = (void*)GetProcAddress(module, procname);
    }
    return p;
}

#endif