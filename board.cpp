#include "board.h"


board::board(const unsigned int height, const unsigned int width)
    : height{height}, width{width},
      grid(height,
            std::vector<Cell>(width,{BLACK,true})) {}//ajouter les noires ici? //[row][column]{}

bool board::isCellEmpty(Cell &cell) const
{
    return cell.isEmpty();
}

void board::colorizeBoard()
{
    for (int i = 0; i < height; i++ )
    {
        unsigned color = (i % 2 == 0) ? BLACK : WHITE;

        for (int j = 0; j < width; j++ )
        {
            colorizeCell(Point{i,j}, color);
            color = (color == BLACK) ? WHITE : BLACK;
        }
    }
}


void board::colorizeCell(const Point & position, const unsigned color)
{
    getCellAt(position).colorize(color);
}




