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
    std::vector<Point>  getEmptyCorners(const Point &);
    std::vector<Point>  getFilledCorners(const Point &);
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
    std::vector<Point> corners;
    
    corners.at(0) = position.getLowerLeft();
    corners.at(1) = position.getLowerRight();
    corners.at(2) = position.getUpperLeft();
    corners.at(3) = position.getUpperRight();
    
    return corners;
}

inline std::vector<Point> Board::getEmptyCorners(const Point & position)
{
    std::vector<Point> freeCorners;
    
    for(Point & corner : position.getCorners())
    {
        if (getCellAt(corner).isEmpty())
            freeCorners.push_back(corner);
    }
    
    return freeCorners;
}

inline std::vector<Point> Board::getFilledCorners(const Point & position)
{
    std::vector<Point> filledCorners;
    
    for(Point & corner : position.getCorners())
    {
        if (!getCellAt(corner).isEmpty())
            filledCorners.push_back(corner);
    }
    
    return filledCorners;
}

inline Cell & Board::getCellAt(const Point & position) //const //const impossible de convertir de const Cell en Cell &
{
    return grid.at(position.getX()).at(position.getY());
}
#endif // BOARD_H
