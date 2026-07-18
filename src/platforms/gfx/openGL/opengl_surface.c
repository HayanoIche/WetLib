
#include "wet.h"
#include "wet/log.h"
#include "wet/surface.h"
#include "opengl.h"

#include <stdlib.h>

struct Surface {
    uint32 fbo;
    uint32 texture;
    int32 width;
    int32 height;
};

Surface* surface_create(int32 width, int32 height)
{
    return NULL;
}

void surface_destroy(Surface* surface)
{
    return;
}
