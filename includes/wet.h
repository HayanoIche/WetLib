//
//  Arquivo principal da WetLib
//

#ifndef WET_H
#define WET_H

#include <stdint.h>


//
//  Pegando a plataforma alvo e definindo as macros de plataforma
//

#if defined(_WIN32) || defined(_WIN64)          // Windows
    #define WET_PLATFORM_WINDOWS            
#elif defined(__APPLE__) || defined(__MACH__)   // MacOs
    #define WET_PLATFORM_MACOS
#elif defined(__linux__)                        // Linux
    #define WET_PLATFORM_LINUX 
#else
    // Plataforma não suportada
#endif


//
//  Renomeando tipos específicos para algo mais simples e utilizável
//
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


#endif
