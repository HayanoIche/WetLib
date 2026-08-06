//
//  Arquivo pertencente de um sub-header da WetLib
//  feito por Hayano
//

#ifndef WET_SURFACE_H
#define WET_SURFACE_H

#include "wet.h"
#include "wet/log.h"


// ** adicionar aqui no futuro comentários explicando que
// é o conceito das surfaces e cameras e como funcionam e como usar

// Funções públicas

//
//  A forma de gerenciar as surfaces basicamente é:
//  
//      Criar elas com nomes únicos e colocar em um banco
//  de dados, pra quando outras funções forem usar surfaces
//  não precisarem lidar com ponteiros de surface só precisando
//  chamar a função com o nome
//

#define MAX_SURFACES 10

// Cria uma surface
bool surface_create(const char* surface_name, Vec2 size);

// Destroi uma surface específica
void surface_destroy(const char* surface_name);
// Destroi todas as surfaces
void surface_destroy_all(void);

// Seta a surface escolhida pra ser a surface que vai ser desenhada no momento
void surface_set_target(const char* surface_name);

#endif
