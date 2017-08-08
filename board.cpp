#include "board.h"

//colorie les cell et place les joueurs en position de départ
Board::Board(const unsigned int height, const unsigned int width)
    : height{height}, width{width},
      grid(height, std::vector<Cell>(width,{GREY}))
{
    colorize();
    initMen();
}

bool Board::isCellEmpty(const Point & position)
{
    return getCellAt(position).isEmpty() && isOnBoard(position);
}

bool Board::isOnBoard(const Point & position) const
{
    return (position.getY() < (int)height && position.getY() >= 0)
            && (position.getX() < (int)width && position.getX() >= 0);
}

void Board::colorize()
{
    for (int i = 0; i < (int)height; i++ )
    {
        unsigned color = (i % 2 == 0) ? WHITE : BLACK;

        for (int j = 0; j < (int)width; j++ )
        {
            colorizeCell(Point{j,i}, color);
            color = (color == WHITE) ? BLACK : WHITE;
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
    getCellAt(Point{1,0}).addMan(BLACK);
    getCellAt(Point{6,7}).addMan(WHITE);
//    for (int i = 0; i < 4; i++ )
//    {
//        for (int j = 0; j < (int)width; j++ )
//        {
//            Point positionDown{(int)(width -1)-j,(int)(height-1)-i};
//            Point positionTop{j,i};

//            if(getCellAt(positionTop).getColor() == BLACK)
//            {
//                getCellAt(positionTop).addMan(BLACK); //BLACK
//                getCellAt(positionDown).addMan(WHITE); //WHITE
//            }
//        }
//    }
}

Cell & Board::getCellAt(const Point & position)
{
    return grid.at(position.getX()).at(position.getY());
}
