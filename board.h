#ifndef BOARD_H
#define BOARD_H

#define DEFAULTHEIGHT 10
#define DEFAULTWIDTH 10

#include "cell.h"
#include "point.h"
#include <vector>

class Board
{
    
private:
    
    unsigned int height;
    unsigned int width;
    std::vector <std::vector<Cell>> grid;
    
    void colorizeCell(const Point &, const unsigned);

public:
    
    Board(const unsigned = DEFAULTHEIGHT, const unsigned = DEFAULTWIDTH);
    unsigned int getHeight() const;
    unsigned int getWidth() const;
    Cell & getCellAt(const Point &);
    bool isCellEmpty(const Point & position);
    bool isOnBoard(const Point & position) const;
    void clearCell(const Point &);
    void colorize();
    void initMen();
};

inline unsigned int Board::getHeight() const
{
    return height;
}

inline unsigned int Board::getWidth() const
{
    return width;
}

#endif // BOARD_H
