#include "board.h"


Board::Board(const unsigned int height, const unsigned int width)
    : height{height}, width{width},
      grid(height,
            std::vector<Cell>(width,{GREY,true})) {} //[row][column]{}

bool Board::isCellEmpty(Cell &cell) const
{
    return cell.isEmpty();
}

void Board::colorize()
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


void Board::colorizeCell(const Point & position, const unsigned color)
{
    getCellAt(position).colorize(color);
}

void Board::clearCell(const Point & position)
{
    getCellAt(position).clear();
}


