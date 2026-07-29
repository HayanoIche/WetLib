#include <glad/glad.h>

#include "wet.h"
#include "wet/surface.h"
#include "opengl.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


typedef struct {
    char name[32];
    uint32 fbo;
    uint32 texture;
    uint32 rbo;
    uint32 width;
    uint32 height;
    bool active;
} Surface;


static Surface surfaces[MAX_SURFACES] = { 0 };


bool opengl_surface_create(const char* name, uint32 width, uint32 height)
{
    Surface* surface = NULL;

    for(int i = 0; i < MAX_SURFACES; i += 1)
    {
        if (!surfaces[i].active)
        {
            surface = &surfaces[i];
            break;
        }
    }

    if (!surface)
    {
        LOG_ERROR("[OPEN GL] Limite máximo de surfaces (%d) atingido!", MAX_SURFACES);
    }

    // Copiando as informações pra surface real
    strncopy(surface->name, name, sizeof(surface->name) - 1);
    surface->width = width;
    surface->height = height;
}