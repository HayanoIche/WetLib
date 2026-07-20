//
//  Arquivo pertencente de um sub-header da WetLib
//  feito por Hayano
//

#ifndef WET_RENDER_H
#define WET_RENDER_H

#include "wet.h"

// ----------------------------------------------------------------------
//  Funções pro sistema de gráficos
// ----------------------------------------------------------------------

// Funções do ciclo de vida
bool renderer_init(GraphicsAPI api);
void renderer_shut(void);

bool renderer_change_api(GraphicsAPI api);

void renderer_on_resize(uint32 w, uint32 h);

#endif
