////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//  Arquivo header principal da WetLib
//  Feito por Hayano

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef WET_H
#define WET_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// -------------- APIS DE GRÁFICO --------------

typedef enum {
    GRAPHICS_API_OPENGL,
    GRAPHICS_API_VULKAN,    // Futuramente
    GRAPHICS_API_DIRECTX    // Futuramente
} GraphicsAPI;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// -------------- TIPOS RENOMEADOS --------------

typedef int8_t   int8;
typedef int16_t  int16;
typedef int32_t  int32;
typedef int64_t  int64;

typedef uint8_t  uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

typedef float    float32;
typedef double   float64;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// -------------- VECTORS --------------

// Vector 2
typedef struct {
    float32 x;
    float32 y;
} Vec2;

// Vector 3
typedef struct {
    float32 x;
    float32 y;
    float32 z;
} Vec3;

// Vector 4
typedef struct {
    float32 x;
    float32 y;
    float32 z;
    float32 w;
} Vec4;

// Rectangle
typedef struct {
    float32 x;
    float32 y;
    float32 width;
    float32 height;
} Rect;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// -------------- CORES --------------

// Struct da cor
typedef struct {
    uint8 r;
    uint8 g;
    uint8 b;
    uint8 a;
} Color;

// Função pra criar cores
static inline Color make_color_rgb(uint8 r, uint8 g, uint8 b)
{
    Color c = {r, g, b, 255};
    return c;
}

static inline Color make_color_rgba(uint8 r, uint8 g, uint8 b, uint8 a)
{
    Color c = {r, g, b, a};
    return c;
}

static inline Color make_color_hex(uint32 hex)
{
    Color c;
    c.r = (hex >> 16) & 0xFF;
    c.g = (hex >> 8)  & 0xFF;
    c.b = hex         & 0xFF;
    c.a = 255;
    return c;
}

#endif
