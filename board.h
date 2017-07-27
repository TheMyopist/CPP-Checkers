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
    bool isCellEmpty(Cell &) const;
    void clearCell(const Point &);
    void colorize();
    void initMen();
    
    //calcul des positions adjacentes à une cell (4 coins)
    std::vector<Point> getCorners(const Point &);
};

inline unsigned int Board::getHeight() const
{
    return height;
}

inline unsigned int Board::getWidth() const
{
    return width;
}

inline std::vector<Point> Board::getCorners(const Point & position)
{
    Point corner{position};
    int x; int y;
    std::vector<Point> corners;
    std::vector<int> directions{SOUTH_WEST,SOUTH_EAST,NORTH_EAST,NORTH_WEST};

    for(int direction : directions)
    {
        corner.moveToDirection(direction);
        x = corner.getX();
        y = corner.getY();
        if(((x < (int)height) || (x >= 0) ) || ((y < (int)width) || (y >= 0)))
            corners.push_back(corner);
     }
    return corners;
}

inline Cell & Board::getCellAt(const Point & position) //const //const impossible de convertir de const Cell en Cell &
{
    return grid.at(position.getX()).at(position.getY());
}
#endif // BOARD_H
