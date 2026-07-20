
// Implementação das funções de surface

#include "wet/draw.h"
#include "graphics.h"

bool surface_create(const char* surface_name, uint32 width, uint32 height)
{
    return graphics_fa.surface_create(surface_name, width, height);
}


void surface_destroy(const char* surface_name)
{
    return graphics_fa.surface_destroy(surface_name);
}


void surface_destroy_all(void)
{
    return graphics_fa.surface_destroy_all();
}


void surface_set_target(const char* surface_name)
{
    return graphics_fa.surface_set_target(surface_name);
}
