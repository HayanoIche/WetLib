
#include "wet/render.h"
#include "./graphics.h"

GraphicsFunctionAddresser graphics_fa = { 0 };

static GraphicsAPI graphics_api;

// Funções do ciclo das APIs específicas
    // OpenGL
    bool opengl_init(void);
    void opengl_shut(void);
    bool opengl_functions_load(void);



// Implementação das funções do renderer
bool renderer_init(GraphicsAPI api)
{
    graphics_api = api;

    if (graphics_api == WET_GRAPHICS_API_OPENGL)
    {
        opengl_init();
        opengl_functions_load();

        return true;
    }

    return false;
}

void renderer_shut(void)
{
    if (graphics_api == WET_GRAPHICS_API_OPENGL)
    {
        opengl_shut();
    }
}


bool renderer_change_api(GraphicsAPI api)
{
    
}


void renderer_on_resize(uint32 w, uint32 h)
{

}
