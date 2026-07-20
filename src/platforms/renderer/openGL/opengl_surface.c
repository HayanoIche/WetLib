#include <glad/glad.h>

#include "wet.h"
#include "wet/surface.h"
#include "opengl.h"

#include <stdlib.h>

struct Surface {
    uint32 fbo;
    uint32 texture;
    int32 width;
    int32 height;
};
