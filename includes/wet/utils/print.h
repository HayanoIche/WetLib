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
// *        Esse arquivo contém implementações de funções
// *    para escrita e log.
// *    
// *    *** IMPLEMENTAÇÃO DE FUNÇÕES NO "print.c"
// *    
// *        - GLOSSÁRIO:
// *    
// *    TODO: fazer o glossário
// *    
// *    
// * -----------------------------------------------------------------
// *

///////////////////////////////////////////////////////////////////////////////////////

#ifndef WET_PRINT
#define WET_PRINT

///////////////////////////////////////////////////////////////////////////////////////

// Prints
void print(const char* message, ...);
void println(const char* message, ...);

///////////////////////////////////////////////////////////////////////////////////////

// Log
typedef enum {
    WET_LOG_LEVEL_INFO,
    WET_LOG_LEVEL_WARN,
    WET_LOG_LEVEL_ERROR,
    WET_LOG_LEVEL_FATAL,
    WET_LOG_LEVEL_NONE
} WetLogLevel;

void log_set_level(WetLogLevel level);
void log_print(WetLogLevel level, const char* message, ...);
void log_clear_terminal(void);

#if defined(WET_RELEASE)

    #define LOG_INFO(msg, ...)
    #define LOG_WARN(msg, ...)
    #define LOG_ERROR(msg, ...)
    #define LOG_FATAL(msg, ...)

    #define LOG_CLEAN()

#elif defined(WET_DEBUG)

    #define LOG_INFO(msg, ...)  log_print(WET_LOG_LEVEL_INFO, msg, ##__VA_ARGS__)
    #define LOG_WARN(msg, ...)  log_print(WET_LOG_LEVEL_WARN, msg, ##__VA_ARGS__)
    #define LOG_ERROR(msg, ...) log_print(WET_LOG_LEVEL_ERROR, msg, ##__VA_ARGS__)
    #define LOG_FATAL(msg, ...) log_print(WET_LOG_LEVEL_FATAL, msg, ##__VA_ARGS__)

    #define LOG_CLEAN() log_clear_terminal()

#endif

///////////////////////////////////////////////////////////////////////////////////////

#endif

