//
//  Arquivo pertencente de um sub-header da WetLib
//  feitor por Hayano
//

#ifndef WET_LOG
#define WET_LOG

// Leveis de log
typedef enum {
    WET_LOG_LEVEL_INFO,
    WET_LOG_LEVEL_WARN,
    WET_LOG_LEVEL_ERROR,
    WET_LOG_LEVEL_FATAL,
    WET_LOG_LEVEL_NONE
} WetLogLevel;

void log_set_level(WetLogLevel level);
void log_print(WetLogLevel level, const char* message, ...);

// ----------------------------------------------------------------------
//  Definindo as funções macro do log
// ----------------------------------------------------------------------

#if defined(WET_RELEASE)

    #define LOG_INFO(msg, ...)
    #define LOG_WARN(msg, ...)
    #define LOG_ERROR(msg, ...)
    #define LOG_FATAL(msg, ...)

#elif defined(WET_DEBUG)

    #define LOG_INFO(msg, ...)  log_print(WET_LOG_LEVEL_INFO, msg, ##__VA_ARGS__)
    #define LOG_WARN(msg, ...)  log_print(WET_LOG_LEVEL_WARN, msg, ##__VA_ARGS__)
    #define LOG_ERROR(msg, ...) log_print(WET_LOG_LEVEL_ERROR, msg, ##__VA_ARGS__)
    #define LOG_FATAL(msg, ...) log_print(WET_LOG_LEVEL_FATAL, msg, ##__VA_ARGS__)

#endif

#endif

