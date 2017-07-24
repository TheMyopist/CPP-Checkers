#include "board.h"


Board::Board(const unsigned int height, const unsigned int width)
    : height{height}, width{width},
      grid(height,
            std::vector<Cell>(width,{GREY})) {} //[row][column]{}

bool Board::isCellEmpty(Cell &cell) const
{
    return cell.isEmpty();
}

void Board::colorize()
{
    for (int i = 0; i < (int)height; i++ )
    {
        unsigned color = (i % 2 == 0) ? BLACK : WHITE;

        for (int j = 0; j < (int)width; j++ )
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

void Board::initWhiteMen()
{
    for (int i = 0; i < 4; i++ )
    {
        for (int j = 0; j < (int)width; j++ )
        {
            Point position{i,j};
            if(getCellAt(position).getColor() == BLACK)
            getCellAt(position).addMan(WHITE);
        }
    }
}

//cast to int for suppressing const/unsigned incompatibility warnings
void Board::initBlackMen()
{
    for (int i = 9; i > 5; i++ )
    {
        for (int j = 0; j < (int)width; j++ )
        {
            Point position{i,j};
            if(getCellAt(position).getColor() == BLACK)
            getCellAt(position).addMan(BLACK);
        }
    }
}

void Board::initMen()
{
    initBlackMen();
    initWhiteMen();
}

