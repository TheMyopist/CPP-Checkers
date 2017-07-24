#include "cell.h"

Cell::Cell(const unsigned color) : color{color},
    empty{true}, man{Man{}} {}

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

void Cell::addMan(const unsigned color)
{
    empty = false;
    man = Man{color};
}
