//
//  Arquivo principal da WetLib
//

#ifndef WET_H
#define WET_H

// Pegando a plataforma alvo e definindo as macros de plataforma
#if defined(_WIN32) || defined(_WIN64)          // Windows
    #define WET_PLATFORM_WINDOWS            
#elif defined(__APPLE__) || defined(__MACH__)   // MacOs
    #define WET_PLATFORM_MACOS
#elif defined(__linux__)                        // Linux
    #define WET_PLATFORM_LINUX 
#else
    // Plataforma não suportada
#endif



#endif
