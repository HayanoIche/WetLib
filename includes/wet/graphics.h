//
//  Arquivo pertencente de um sub-header da WetLib
//  feito por Hayano
//

#ifndef WET_GRAPHICS_H
#define WET_GRAPHICS_H

#include "wet.h"

// ENUM com as API's
enum GraphicsAPI {
    WET_GRAPHICS_API_OPENGL,
    WET_GRAPHICS_API_VULKAN,
    WET_GRAPHICS_API_DIRECTX
};

// ----------------------------------------------------------------------
//  Funções pro gráfico
// ----------------------------------------------------------------------

// Funções do ciclo de vida
bool graphics_init(GraphicsAPI api);
bool graphics_shut();

bool graphics_change_api(GraphicsAPI api);
