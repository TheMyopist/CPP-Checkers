#include "checkers.h"

Checkers::Checkers(const bool isMultiplayer) : turn{0},
    gameOver{false}, board{Board()}
{
    initPlayers(isMultiplayer);
}

void Checkers::initPlayers(const bool isMultiplayer)
{
    if(isMultiplayer)
        players = {Player{BLACK},Player{WHITE}};
    else players = {Player{BLACK},IAplayer{WHITE}};
}

void Checkers::nextTurn()
{
    turn++;
}

void Checkers::removeMan(const Point position)
{
    board.getCellAt(position).clear();
}

std::pair<Point,std::vector<Point>> Checkers::getMovablePositions(const Point & position, const unsigned color)
{
    std::pair<Point,std::vector<Point>> movablePositions;
    movablePositions.first = position;
    std::vector<Point> corners = board.getCorners(position);

    for(Point & corner : corners)
        addMovablePositions(movablePositions,corner,color);

    return movablePositions;
}

std::vector<Point> Checkers::addMovablePositions(std::pair<Point, std::vector<Point> > & movablePositions
                                                 , const Point &corner
                                                 , const unsigned color)
{
    std::vector<Point> newMovablePositions{movablePositions.second};
    Cell positionToCheck{board.getCellAt(corner)};

    if(positionToCheck.isEmpty()) //move possible
        newMovablePositions.push_back(corner);
    else if(isEnnemyPosition(corner,color)) //capture
    {
        Point positionToCapture{corner};
        positionToCapture.moveToDirection(positionToCapture.getRelativeDirection(movablePositions.first));
        newMovablePositions.push_back(positionToCapture);
    }

    return newMovablePositions;
}

bool Checkers::isEnnemyPosition(const Point & position
                                ,const unsigned color)
{
    return board.getCellAt(position).getColor() != color;
}

