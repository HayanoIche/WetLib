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
// *        Esse arquivo contém uma implementação de vetores matemáticos
// *    e algumas funções pra manipulação e alterações neles.
// *    
// *        - GLOSSÁRIO:
// *    
// *    TODO: fazer o glossário
// *    
// *    
// * -----------------------------------------------------------------
// *

///////////////////////////////////////////////////////////////////////////////////////

#ifndef WET_VECTORS
#define WET_VECTORS

#include "sintax.h"

///////////////////////////////////////////////////////////////////////////////////////


typedef struct {
    float32 x;
    float32 y;
} Vec2;


typedef struct {
    float32 x;
    float32 y;
    float32 z;
} Vec3;


typedef struct {
    float32 x;
    float32 y;
    float32 z;
    float32 w;
} Vec4;


typedef struct {
    float32 x;
    float32 y;
    float32 width;
    float32 height;
} Rect;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif
