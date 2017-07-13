#ifndef BOARD_H
#define BOARD_H

#define DEFAULTHEIGHT 10
#define DEFAULTWIDTH 10

#include "cell.h"
#include "point.h"
#include <vector>

class board
{

private:

    unsigned int height;
    unsigned int width;
    std::vector <std::vector<Cell>> grid;


public:

    board(const unsigned = DEFAULTHEIGHT,const unsigned = DEFAULTWIDTH);
    unsigned int getHeight() const;
    unsigned int getWidth() const;
    Cell & getCellAt(const Point &); //const?
    bool isCellEmpty(Cell &) const; //avec getCellAt (ou bien aussi donner pos)



};

inline unsigned int board::getHeight() const
{
    return height;
}

inline unsigned int board::getWidth() const
{
    return width;
}

inline Cell &board::getCellAt(const Point & position) //const //const impossible de convertir de const Cell en Cell &
{
    return grid.at(position.getX()).at(position.getY());
}

#endif // BOARD_H
