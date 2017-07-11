#ifndef BOARD_H
#define BOARD_H

#include "cell.h"
#include "point.h"

class board
{

private:

    unsigned int height;
    unsigned int width;
    std::vector <std::vector<Cell>> grid;


public:

    Board(unsigned int,unsigned int):
    Board();

    unsigned int getHeight() const;
    unsigned int getWidth() const;
    Cell getCellAt(const Point &);
    bool isCellEmpty(Cell) const; //avec getCellAt (ou bien aussi donner pos)



};

inline unsigned int getHeight() const
{
    return height;
}

inline unsigned int getWidth() const
{
    return width;
}

inline Cell & Board::getCellAt(const Point & position)
{
    return grid.at(position.getX()).at(position.getY());
}

#endif // BOARD_H
