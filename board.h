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
    void initWhiteMen();
    void initBlackMen();
    
    
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
    std::vector<Cell> & getCorners(const Point &);
    std::vector<Cell> & getEmptyCorners(const Point &);
    std::vector<Cell> & getFilledCorners(const Point &);
    Cell & getUpperLeft(const Point &);
    Cell & getUpperRight(const Point &);
    Cell & getLowerLeft(const Point &);
    Cell & getLowerRight(const Point &);
    
    
};

inline unsigned int Board::getHeight() const
{
    return height;
}

inline unsigned int Board::getWidth() const
{
    return width;
}

inline std::vector<Cell> & Board::getCorners(const Point & position)
{
    std::vector<Cell> corners;
    
    corners.at(0) = getUpperLeft(position);
    corners.at(1) = getUpperRight(position);
    corners.at(2) = getLowerLeft(position);
    corners.at(3) = getLowerRight(position);
    
    return corners;
}

inline std::vector<Cell> & Board::getEmptyCorners(const Point & position)
{
    std::vector<Cell> freeCorners;
    
    for(Cell corner : getCorners(position))
    {
        if (corner.isEmpty())
            freeCorners.push_back(corner);
    }
    
    return freeCorners;
}

inline std::vector<Cell> & Board::getFilledCorners(const Point & position)
{
    std::vector<Cell> filledCorners;
    
    for(Cell corner : getCorners(position))
    {
        if (!corner.isEmpty())
            filledCorners.push_back(corner);
    }
    
    return filledCorners;
}

inline Cell & Board::getCellAt(const Point & position) //const //const impossible de convertir de const Cell en Cell &
{
    return grid.at(position.getX()).at(position.getY());
}

inline Cell & Board::getUpperLeft(const Point & position) //const impossible?
{
    return getCellAt(Point{position.getX() + 1,position.getY() - 1});
}

inline Cell & Board::getUpperRight(const Point & position) //const impossible?
{
    return getCellAt(Point{position.getX()+ 1,position.getY() + 1});
}

inline Cell & Board::getLowerLeft(const Point & position) //const impossible?
{
    return getCellAt(Point{position.getX() - 1,position.getY() - 1});
}

inline Cell & Board::getLowerRight(const Point & position) //const impossible?
{
    return getCellAt(Point{position.getX() - 1,position.getY() + 1});
}

#endif // BOARD_H
