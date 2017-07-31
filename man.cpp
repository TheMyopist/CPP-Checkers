#include "man.h"

Man::Man(const unsigned color) :
    color{color}, king{false} {}

Man::Man(const Man &man) : color{man.getColor()}
  , king{man.king}{}

void Man::crown()
{
    king = true;
}
