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

    for(Point corner : corners)
        addMovablePositions(movablePositions,corner,color);

    return movablePositions;
}

std::vector<Point> Checkers::addMovablePositions(std::pair<Point, std::vector<Point> > movablePositions
                                                 , const Point & corner
                                                 , const unsigned color)
{
    std::vector<Point> newMovablePositions{movablePositions.second};
    Cell positionToCheck{board.getCellAt(corner)};

    if(positionToCheck.isEmpty()) //move possible
        newMovablePositions.push_back(corner);
    else if(isEnnemyPosition(corner,color))
        //addpositionsuivante

    return newMovablePositions;

}

Point Checkers::getCapturablePosition(const Point & currentPosition
                                      ,const Point & ennemyPosition)
{
    int currentX = currentPosition.getX();
    int currentY = currentPosition.getY();
    int ennemyX  = ennemyPosition.getX();
    int ennemyY  = ennemyPosition.getY();

    Point capturablePosition;

    if(ennemyX == currentX - 1)



}

bool Checkers::isEnnemyPosition(const Point & position
                                ,const unsigned color)
{
    return board.getCellAt(position).getColor() != color;
}

std::vector<Point>  Checkers::getEnnemiesCorners(const Point & position
                                                 , const unsigned color)
{

    std::vector<Point> ennemies;

    for(Point & corner : getBoard().getFilledCorners(position))
    {
        if (board.getCellAt(corner).getColor() != color)
            ennemies.push_back(corner);
    }

    return ennemies;
}

std::vector<Point> Checkers::getAttackablePositions(const Point & position
                                                  , const unsigned color)
{
    std::vector<Point> attackable;

    for(Point & ennemy : getEnnemiesCorners(position,color))
        attackable.push_back(Point{ennemy.getX() + ennemy.getX(),
                                       ennemy.getY()+ennemy.getY()});

    return attackable;
}

std::vector<Point> Checkers::getMovableCorners(const Point & position)
{
    return board.getEmptyCorners(position);
}
