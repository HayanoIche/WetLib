#include "wet.h"
#include "wet/graphics.h"
#include "wet/log.h"

// ----------------------------------------------------------------------
//  Declarando as funções específicas de plataforma
// ----------------------------------------------------------------------

static GraphicsAPI graphics_api;

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
    graphics_api = api;
    if (graphics_api == WET_GRAPHICS_API_OPENGL)
    {
        return opengl_init();
    }
    //if (graphics_api == WET_GRAPHICS_API_VULKAN) return false;
    //if (graphics_api == WET_GRAPHICS_API_DIRECTX) return false;

    return false;
}

void graphics_shut(void)
{
    if (graphics_api == WET_GRAPHICS_API_OPENGL) { return opengl_shut(); }
    //if (graphics_api == WET_GRAPHICS_API_VULKAN) {};
    //if (graphics_api == WET_GRAPHICS_API_DIRECTX) {};
};

// A ser implementado
bool graphics_change_api(GraphicsAPI api)
{
    return false;
}

void graphics_clear_screen(Color color)
{
    if (graphics_api == WET_GRAPHICS_API_OPENGL)
    {
        opengl_clear_screen(color);
    }
}