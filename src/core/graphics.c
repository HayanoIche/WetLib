
#include "wet.h"

#include "wet/log.h"
#include "wet/draw.h"
#include "wet/graphics.h"

#include "./internal-headers/graphics-internal.h"
#include "./internal-headers/window-internal.h"

GraphicsFunctionAddresser graphics_fa = { 0 };
static GraphicsAPI graphics_api;

// Função que inicia tudo relacionado a gráficos da engine

bool graphics_init(void) {

    // -------------- JANELA --------------
    if (!window_create())
    {
        LOG_FATAL("WINDOW FAILED TO LOAD!");
        return false;
    }

    // -------------- TEMPO --------------
    if (!time_init())
    {
        LOG_FATAL("TIME SYSTEM FAILED TO LOAD!");
        return false;
    }

    // -------------- GRÁFICOS --------------
    if (graphics_api == GRAPHICS_API_OPENGL)
    {
        if (!opengl_init()) { return false; }
        opengl_functions_load();
        return true;
    }

    return false;
}

void graphics_update(void)
{
    time_update();
    window_update();
}

bool graphics_is_running(void)
{
    return true;
}


void graphics_shut(void)
{

}




















/*

// Funções do ciclo das APIs específicas


// Implementação das funções do renderer
bool renderer_init(GraphicsAPI api)
{
    graphics_api = api;

    if (graphics_api == WET_GRAPHICS_API_OPENGL)
    {
        if (!opengl_init()) { return false; }
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

    return true;
}

void renderer_on_resize(uint32 w, uint32 h) {}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Implementação das funções básicas das surfaces
bool surface_create(const char* surface_name, Vec2 size) { return graphics_fa.surface_create(surface_name, width, height); }
void surface_destroy(const char* surface_name) { return graphics_fa.surface_destroy(surface_name); }
void surface_destroy_all(void) { return graphics_fa.surface_destroy_all(); }
void surface_set_target(const char* surface_name) { return graphics_fa.surface_set_target(surface_name); }



void draw_clear(Color color) { return graphics_fa.draw_clear(color); }
*/