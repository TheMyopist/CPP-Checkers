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

std::pair<Point,std::vector<Point>> Checkers::playablePositions(const Point & position,
                                                 const Man & man)
{
    std::pair<Point,std::vector<Point>> playablePositions;

    //positions capturables(pour capture)
    playablePositions
            .second = getAttackablePositions(position,man.getColor());

    //positions vides (pour move)
    playablePositions.second.insert(playablePositions.second.end(),
                                    getMovableCorners(position).begin(),
                                    getMovableCorners(position).end());

    return playablePositions;
}

std::vector<Point>  Checkers::getEnnemiesCorners(const Point & position, const unsigned color)
{

    std::vector<Point> ennemies;

    for(Point & corner : getBoard().getFilledCorners(position))
    {
        if (getBoard().getCellAt(corner).getColor() != color)
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
    return getBoard().getEmptyCorners(position);
}
