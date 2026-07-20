
#include "wet.h"
#include "wet/log.h"
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
        if (!opengl_init()) return false;
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

    // Zerando a struct de ponteiros
    graphics_fa = (GraphicsFunctionAddresser){ 0 };
}


bool renderer_change_api(GraphicsAPI new_api)
{
    if (new_api == graphics_api) { return true; }

    renderer_shut();

    if (!renderer_init(new_api))
    {
        LOG_ERROR("CHANGE API: NEW API FAILED ON INITIALIZING!");
        return false;
    }

    LOG_INFO("New API successfully initialized");
    LOG_INFO("new api index: %d", graphics_api);
}


void renderer_on_resize(uint32 w, uint32 h)
{

}
