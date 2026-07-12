//
//  Arquivo principal da WetLib
//

#ifndef WET_H
#define WET_H


#include <stdint.h>


// ----------------------------------------------------------------------
//  Pegando a plataforma alvo e definindo as macros de plataforma
// ----------------------------------------------------------------------

#if defined(_WIN32) || defined(_WIN64)          // Windows
    #define WET_PLATFORM_WINDOWS            
#elif defined(__APPLE__) || defined(__MACH__)   // MacOs
    #define WET_PLATFORM_MACOS
#elif defined(__linux__)                        // Linux
    #define WET_PLATFORM_LINUX 
#else
    // Plataforma não suportada
#endif


// ----------------------------------------------------------------------
//  Renomeando tipos específicos para algo mais simples e utilizável
// ----------------------------------------------------------------------

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

// ----------------------------------------------------------------------
//  Structs padrões da biblioteca
// ----------------------------------------------------------------------

// Struct para vetores bidimensionais
typedef struct {
    float32 x;
    float32 y;
} Vec2;

typedef struct {
    int32 x;
    int32 y;
} Vec2i;

// Struct para vetores tridimensional
typedef struct {
    float32 x;
    float32 y;
    float32 z;
} Vec3;

typedef struct {
    float32 x;
    float32 y;
    float32 z;
} Vec3i;

// Struct para retangulos
typedef struct {
    float32 x1;
    float32 y1;
    float32 x2;
    float32 y2;
} Rect;

typedef struct {
    int32 x1;
    int32 y1;
    int32 x2;
    int32 y2;
} Recti;

// Struct para cores
typedef struct {
    uint8 r;
    uint8 g;
    uint8 b;
    uint8 a;
} Color;



#endif
