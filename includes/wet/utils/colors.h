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
// *        Esse arquivo contém uma implementação de uma
// *    estrutura de dados para representar cores e funções
// *    relacionadas a isso.
// *    
// *        - GLOSSÁRIO:
// *    
// *    TODO: fazer o glossário das funções e struct
// *    
// *    
// * -----------------------------------------------------------------
// *

///////////////////////////////////////////////////////////////////////////////////////

#ifndef WET_COLORS
#define WET_COLORS

#include "sintax.h"

// Struct da cor
typedef struct {
    uint8 r;
    uint8 g;
    uint8 b;
    uint8 a;
} Color;


// Função pra iniciar uma struct color com R, G e B
static inline Color make_color_rgb(uint8 r, uint8 g, uint8 b)
{
    Color c = {r, g, b, 255};
    return c;
}


// Função pra iniciar uma struct color com R, G, B, A
static inline Color make_color_rgba(uint8 r, uint8 g, uint8 b, uint8 a)
{
    Color c = {r, g, b, a};
    return c;
}


// Função pra iniciar uma struct color com um código HEXA
static inline Color make_color_hex(uint32 hex)
{
    Color c;
    c.r = (hex >> 16) & 0xFF;
    c.g = (hex >> 8)  & 0xFF;
    c.b = hex         & 0xFF;
    c.a = 255;
    return c;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif
