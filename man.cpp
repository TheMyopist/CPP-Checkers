#include "man.h"

Man::Man(const unsigned color) :
    color{color}, isKing{false}, isAlive{true}{}

void Man::crown()
{
    isKing = true;
}

void Man::remove()
{
    isAlive = false;
}
