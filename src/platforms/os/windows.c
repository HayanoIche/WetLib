#include "wet.h"

#ifdef WET_PLATFORM_WINDOWS

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include <windows.h>

#include "wet/log.h"
#include "wet/graphics.h"
#include "wet/window.h"

#include "src/core/internal-headers/window-internal.h"


typedef struct {

    HWND hwnd;
    HDC hdc;
    HGLRC hglrc;

    uint16 x;
    uint16 y;
    uint16 width;
    uint16 height;

    char* caption;

    bool fullscreen;
    bool borderless;

    bool running;
    bool started;

} Win32Window;

static Win32Window window = { 0 };

// ----------------------------------------------------------------------
//  Funções pra manejar a janela do win32
// ----------------------------------------------------------------------

// Callback do windows
LRESULT CALLBACK win32_process_message(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    switch (msg)
    {
        case WM_CLOSE:
            window.running = false;
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
                break;
            }
    }
    
    // Qualquer mensagem não tratada retorna o default
    return DefWindowProcA(hwnd, msg, wparam, lparam);
}

// Função que cria a janela no windows com o win32
bool window_create(void) {
    HINSTANCE instance = GetModuleHandleA(0);

    WNDCLASS wc = {0};
    wc.hInstance = instance;
    wc.hIcon = LoadIcon(instance, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = window.caption;
    wc.hbrBackground = NULL;
    wc.lpfnWndProc = win32_process_message; // Callback pros inputs

    if (!RegisterClassA(&wc))
    {
        LOG_FATAL("FALHA AO REGISTRAR A CLASSE DO WIN32! código: %lu\n", GetLastError());
        return false;
    }

    int dwStyle = WS_OVERLAPPEDWINDOW;

    window.hwnd = CreateWindowExA(
                    0,
                    window.caption,
                    window.caption,
                    dwStyle,
                    CW_USEDEFAULT, CW_USEDEFAULT,
                    window.width,
                    window.height,
                    NULL,
                    NULL,
                    instance,
                    NULL
                );
    
    if (window.hwnd == NULL)
    {
        LOG_FATAL("FALHA AO CRIAR A JANELA DO WIN32! código: %lu\n", GetLastError());
        return false;
    }

    ShowWindow(window.hwnd, SW_SHOW);
    LOG_INFO("Janela do win32 inicializada com sucesso!");
    
    window.running = true;
    return true;
};


void window_update(void) {
    
    // Window
    MSG msg;

    while(PeekMessageA(&msg, window.hwnd, 0, 0, PM_REMOVE))
    {
        TranslateMessage(&msg);
        DispatchMessageA(&msg); //Chama o callback que foi especificado quando criamos a janela
    }
    
    SwapBuffers(window.hdc);
};


void window_destroy(void) {
    // Acabando com o contador de tempo
    time_shut();
};


bool window_should_close(void) {
    return !window.running;
};

// ----------------------------------------------------------------------
//  Implementação das funções do OPENGL
// ----------------------------------------------------------------------

bool win32_opengl_graphics_init(void) {
    window.hdc = GetDC(window.hwnd);

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

    int pixelFormat = ChoosePixelFormat(window.hdc, &pfd);
    SetPixelFormat(window.hdc, pixelFormat, &pfd);

    // CRIA O CONTEXTO OPENGL REAL DO WINDOWS
    window.hglrc = wglCreateContext(window.hdc);
    if (!window.hglrc) return false;

    // Faz o contexto ficar ativo na nossa thread atual
    wglMakeCurrent(window.hdc, window.hglrc);

    return true;
}

void* win32_opengl_get_proc_address(const char* procname) {
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


// ----------------------------------------------------------------------
//  Funções de configuração da janela
// ----------------------------------------------------------------------

void window_set_position(Vec2 position) {
    window.x = (uint16) position.x;
    window.y = (uint16) position.y;

    if (window.started)
    {
        // Código que realmente muda a posição
    }
}

void window_set_size(Vec2 size) {
    window.width  = (uint16) size.x;
    window.height = (uint16) size.y;

    if (window.started)
    {
        // Código que realmente faz o resize
    }
}

void window_set_fullscreen(bool mode) {
    window.fullscreen = mode;
}

void window_set_caption(const char* title) {
    window.caption = (char*)title;
}


Vec2 window_get_position(void) {return (Vec2) {0, 0}; }
Vec2 window_get_size(void) {return (Vec2) {0, 0}; }
bool window_get_fullscreen(void) {return false; }
const char* window_get_caption(void) {return ""; }

#endif