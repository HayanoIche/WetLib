//
//  Arquivo pertencente de um sub-header da WetLib
//  feito por Hayano
//

#ifndef WET_WINDOW_H
#define WET_WINDOW_H

#include "wet.h"

// Estrutura básica de configuração da janela
typedef struct {
    uint16 width;
    uint16 height;
    const char* title;
    bool fullscreen;
} WindowConfig;


// ----------------------------------------------------------------------
//  Funções publicas pro uso da janela
// ----------------------------------------------------------------------

// Ciclo de vida da janela
bool window_create(WindowConfig config);
void window_update(void);
void window_destroy(void);

// Outros
bool window_should_close(void);

// Posição e tamanho
void window_set_x(uint16 x);
void window_set_y(uint16 y);
void window_set_width(uint16 width);
void window_set_height(uint16 height);

uint16 window_get_x();
uint16 window_get_y();
uint16 window_get_width();
uint16 window_get_height();


//
//      A implementar no futuro:
//
//  void window_set_fullscreen(bool mode);
//  void window_set_borderless(bool mode);
//  void window_set_resizeable(bool mode);
//  void window_set_caption(const char* title);
//
//  também os getters desses setters
//

#endif
