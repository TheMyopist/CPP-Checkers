#include "cell.h"

Cell::Cell(const unsigned color) : color{color},
    empty{true}, man{Man{}} {}

Cell::Cell(const Cell &cell) : color{cell.getColor()}  //ou cell.color?
  , empty{cell.isEmpty()}, man{cell.man}{}

void Cell::clear()
{
    empty = true;
}

void Cell::colorize(const unsigned newColor)
{
    color = newColor;
}

void Cell::addMan(const Man &newMan)
{
    empty = false;
    man = newMan;
}
