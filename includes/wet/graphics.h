////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//
//  Arquivo pertencente de um sub-header da WetLib
//  feito por Hayano
//

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef WET_GRAPHICS_H
#define WET_GRAPHICS_H

#include "wet.h"

// ----------------------------------------------------------------------
//                             GRÁFICOS
// ----------------------------------------------------------------------

bool graphics_init(void);
void graphics_update(void);
void graphics_shut(void);
bool graphics_is_running(void);

bool graphics_change_api(GraphicsAPI api);


#endif
