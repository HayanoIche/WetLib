// *
// * -----------------------------------------------------------------
// *
// *                        - WET LIB -
// *
// *        Projeto de biblioteca de utilidades gerais em C
// *    feita por Igor Hayano, principalmente de forma recreativa,
// *    mas com o objetivo também de tornar o uso de C mais "fácil"
// *
// * -----------------------------------------------------------------
// *
// *    TODO: adicionar a descrição do arquivo aqui
// *    
// * -----------------------------------------------------------------
// *

///////////////////////////////////////////////////////////////////////////////////////

#ifndef WET_H
#define WET_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

///////////////////////////////////////////////////////////////////////////////////////

// -------------- PLATAFORMAS --------------

#if defined(_WIN32) || defined(_WIN64)          // Windows
    #define WET_PLATFORM_WINDOWS
#elif defined(__linux__)                        // Linux
    #define WET_PLATFORM_LINUX
#elif defined(__APPLE__) || defined(__MACH__)   // MacOs
    #define WET_PLATFORM_MACOS
#else
    // Plataforma não suportada
#endif

// -------------- APIS DE GRÁFICO --------------

typedef enum {
    GRAPHICS_API_OPENGL,
    GRAPHICS_API_VULKAN,    // Futuramente
    GRAPHICS_API_DIRECTX    // Futuramente
} GraphicsAPI;

#endif
