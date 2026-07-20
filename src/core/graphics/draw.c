#include "wet.h"
#include "wet/draw.h"
#include "graphics.h"

// ----------------------------------------------------------------------
//  Implementação das funções de desenho
// ----------------------------------------------------------------------

void draw_clear(Color color)
{
    return graphics_fa.draw_clear(color);
}
