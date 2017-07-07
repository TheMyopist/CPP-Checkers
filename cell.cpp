#include "cell.h"

Cell::Cell(const unsigned color, const bool empty) : color{color},
    empty{empty}{}

void Cell::clear()
{
    empty = true;
}

void Cell::colorize(const unsigned newColor)
{
    color = newColor;
}

