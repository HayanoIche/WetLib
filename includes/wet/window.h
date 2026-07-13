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

//
//      A implementar no futuro:
//
//  void window_set_position(uint8 x, uint8 y);
//  void window_set_size(uint8 width, uint8 height);
//  void window_set_fullscreen(bool mode);
//  void window_set_borderless(bool mode);
//  void window_set_resizeable(bool mode);
//  void window_set_caption(const char* title);
//
//  também os getters desses setters
//

#endif
