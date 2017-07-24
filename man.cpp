#include "man.h"

Man::Man(const unsigned color) :
    color{color}, isKing{false} {}

void Man::crown()
{
    isKing = true;
}
