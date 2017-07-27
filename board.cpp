#include "board.h"

//colorie les cell et place les joueurs en position de départ
Board::Board(const unsigned int height, const unsigned int width)
    : height{height}, width{width},
      grid(height, std::vector<Cell>(width,{GREY}))
{
    colorize();
    initMen();
}

bool Board::isCellEmpty(const Point & position) const
{
    return isOnBoard(position) && getCellAt(position).isEmpty();
}

bool isOnBoard(Point & position) const
{
    // to do

    return true;
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

//cast to int for suppressing const/unsigned incompatibility warnings
void Board::initMen()
{
    for (int i = 0; i < 4; i++ )
    {
        for (int j = 0; j < (int)width; j++ )
        {
            Point positionTop{(int)height-i,(int)width-j};
            Point positionDown{i,j};

            if(getCellAt(positionTop).getColor() == BLACK)
            {
                getCellAt(positionTop).addMan(BLACK);
                getCellAt(positionDown).addMan(BLACK);
            }
        }
    }
}

Cell & Board::getCellAt(const Point & position) const //const impossible de convertir de const Cell en Cell &
{
    return grid.at(position.getX()).at(position.getY());
}
