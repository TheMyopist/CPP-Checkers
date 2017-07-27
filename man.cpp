#include "man.h"

Man::Man(const unsigned color) :
    color{color}, isKing{false} {}

Man::Man(const Man &man) : color{man.getColor()}
  , isKing{man.getIsKing()}{}

void Man::crown()
{
    isKing = true;
}
