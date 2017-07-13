#include "cell.h"

Cell::Cell(const unsigned color, const bool empty) : color{color},
    empty{empty}{}

Cell::Cell(const Cell &cell) : color{cell.getColor()}  //ou cell.color?
  , empty{cell.isEmpty()}{}

void Cell::clear()
{
    empty = true;
}

void Cell::colorize(const unsigned newColor)
{
    color = newColor;
}

void Cell::fill()
{
    empty = false;
}
