#include "wet.h"
#include "wet/graphics.h"
#include "wet/log.h"

// ----------------------------------------------------------------------
//  Declarando as funções específicas de plataforma
// ----------------------------------------------------------------------

//  OPEN GL
    bool opengl_init(void);
    void opengl_shut(void);

    void opengl_clear_screen(Color color);

//  VULKAN

//  DIRECTX

// ----------------------------------------------------------------------
//  Implementando as funções gerais de ponteiro
// ----------------------------------------------------------------------

// Funções do ciclo de vida
bool graphics_init(GraphicsAPI api)
{
    if (api == WET_GRAPHICS_API_OPENGL) return opengl_init();
    //if (api == WET_GRAPHICS_API_VULKAN) return false;
    //if (api == WET_GRAPHICS_API_DIRECTX) return false;

    return false;
}

void graphics_shut(void)
{
    //if (api == WET_GRAPHICS_API_OPENGL) return opengl_shut();
    //if (api == WET_GRAPHICS_API_VULKAN) {};
    //if (api == WET_GRAPHICS_API_DIRECTX) {};
};

bool graphics_change_api(GraphicsAPI api) { return false; } // A ser implementado

void graphics_clear_screen(Color color)
{
    opengl_clear_screen(color);
    //if (api == WET_GRAPHICS_API_OPENGL) opengl_clear_screen();
    //if (api == WET_GRAPHICS_API_VULKAN) {};
    //if (api == WET_GRAPHICS_API_DIRECTX) {};
}