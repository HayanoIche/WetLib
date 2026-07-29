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
    strncpy(surface->name, name, sizeof(surface->name) - 1);
    surface->width = width;
    surface->height = height;

    // Iniciando o FrameBuffer
    glGenFramebuffers(1, &surface->fbo);
    glBindFramebuffer(GL_FRAMEBUFFER, surface->fbo);

    // Criando a textura
    glGenTextures(1, &surface->texture);
    glBindTexture(GL_TEXTURE_2D, surface->texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, surface->texture, 0);

    // Renderbuffer para Depth
    glGenRenderbuffers(1, &surface->rbo);
    glBindRenderbuffer(GL_RENDERBUFFER, surface->rbo);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, surface->rbo);

    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
    {
        LOG_ERROR("[OPEN GL] Falha ao validar o framebuffer da surface '%s'", surface->name);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        return false;
    }

    surface->active = true;
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    return true;
}