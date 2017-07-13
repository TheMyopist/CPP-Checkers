#include "board.h"


board::board(const unsigned int height, const unsigned int width)
    : height{height}, width{width},
      grid(height,
            std::vector<Cell>(width,{WHITE,true})) {}//ajouter les noires ici? //[row][column]{}

bool board::isCellEmpty(Cell &cell) const
{
    return cell.isEmpty();
}
