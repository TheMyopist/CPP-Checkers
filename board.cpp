#include "board.h"


board::board(const unsigned int height, const unsigned int width)
    : height{height}, width{width},
      grid(height,
            std::vector<Cell>(width,{BLACK,true})) {}//ajouter les noires ici? //[row][column]{}

bool board::isCellEmpty(Cell &cell) const
{
    return cell.isEmpty();
}

void board::colorizeBoard() //améliorer coding style et supprimer warnings
{
    bool black = false;

    for (int i = 0; i < height*width; i++)
            grid.at(i/width).at(i%width) = (black = !black);
}

void board::colorizeCell(const Point & position, const unsigned color)
{
    getCellAt(position).colorize(color);
}

void board::colorizeLine(const unsigned row)
{
    std::vector<Cell> & lineToColor = getLine(row);

    if(row%2 == 0 || row == 0)
        for(auto j = 0; j < lineToColor.size(); j++)
            if(j%2 != 0)



}
