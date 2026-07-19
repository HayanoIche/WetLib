//
//  Arquivo pertencente de um sub-header da WetLib
//  feito por Hayano
//

#ifndef WET_GRAPHICS_H
#define WET_GRAPHICS_H

#include "wet.h"



// ----------------------------------------------------------------------
//  Funções pro gráfico
// ----------------------------------------------------------------------

// Funções do ciclo de vida
bool graphics_init(GraphicsAPI api);
void graphics_shut(void);

bool graphics_change_api(GraphicsAPI api);
void graphics_clear_screen(Color color);

void graphics_on_resize(uint32 w, uint32 h);

#endif