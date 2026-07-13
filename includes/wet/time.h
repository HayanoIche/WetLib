//
//  Arquivo pertencente de um sub-header da WetLib
//  feito por Hayano
//

#ifndef WET_TIME_H
#define WET_TIME_H

#include "wet.h"

// Ciclo de vida do sistema da contagem do tempo
void time_init(void);
void time_update(void);
void time_shut(void);

// Configurador do FPS
void fps_set_target(uint16 fps);

uint16 fps_get_target(void);
uint16 fps_get(void);
uint16 fps_real_get(void);

float64 delta_time_get(void); // Pra pegar o deltatime

#define DELTA_TIME delta_time_get() // Macro pra pegar o delta_time

#endif
