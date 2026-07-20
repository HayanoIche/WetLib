
#ifndef WET_GRAPHICS_H
#define WET_GRAPHICS_H

#include "wet.h"

// Struct com os ponteiros de função
typedef struct
{
    // Renderer
    bool (*renderer_init) (GraphicsAPI api);
    void (*renderer_shut) (void);
    bool (*renderer_change_api) (GraphicsAPI api);
    void (*renderer_on_resize) (uint32 w, uint32 h);

    // Draw
    void (*draw_clear) (Color color);

    // Surfaces
    bool (*surface_create) (const char* surface_name, uint32 width, uint32 height);
    void (*surface_destroy) (const char* surface_name);
    void (*surface_destroy_all) (void);
    void (*surface_set_target) (const char* surface_name);

} GraphicsFunctionAddresser;

extern GraphicsFunctionAddresser graphics_fa;

#endif
