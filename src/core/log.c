#include "wet.h"
#include "wet/log.h"

#include <stdio.h>
#include <stdarg.h>

// Variável que dita quais mensagens o programa vai mostrar
static WetLogLevel minimum_log_level = WET_LOG_LEVEL_INFO;

// Cores ANSI para o terminal
static const char* log_level_colors[] = {
    "\033[32m", // Verde
    "\033[33m", // Amarelo
    "\033[31m", // Vermelho
    "\033[1;41;37m" // Fundo Vermelho, Texto Branco
};

// Textos para colocar antes da mensagem
static const char* log_level_texts[] = {
    "[INFO] ",
    "[WARN] ",
    "[ERROR] ",
    "[FATAL ERROR] "
};


// ----------------------------------------------------------------------
//  Implementação das Funções
// ----------------------------------------------------------------------

// Função pra definir quais avisos vai receber (todos, até só fatais, ou nenhum)
void log_set_level(WetLogLevel level)
{
    minimum_log_level = level;
}

// Função que printa a mensagem
void log_print(WetLogLevel level, const char* message, ...)
{
    if (level < minimum_log_level || level == WET_LOG_LEVEL_NONE) {
        return;
    }

    // Imprimindo no terminal o texto pré mensagem e a cor
    printf("%s%s", log_level_colors[level], log_level_texts[level]);
    
    // Nota: Nessa parte é criada uma lista de argumentos e é passado pro printf diferenciado (vprintf)
    va_list args;               // Aqui é criado a lista
    va_start(args, message);    // Aqui ela pega tudo depois da variável message e enfia na lista
    vprintf(message, args);     // Printa no terminal PORÉM essa função aceita a lista de argumentos
    va_end(args);               // Aqui tudo é limpo

    // Resetando a cor
    printf("\033[0m\n");
}


