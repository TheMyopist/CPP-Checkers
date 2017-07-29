#include "checkers.h"
#include <algorithm>

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

std::vector< std::pair<Point, std::vector<Point>> > Checkers::getMovablePositionsFrom(
        const Point & position,
        const unsigned color)
{
    std::vector< std::pair<Point, std::vector<Point>> > movablePositions;
    std::vector<Point> corners = position.getCorners();

    for(Point & corner : corners)
        addMovablePositions(movablePositions, position, corner, color);

    return movablePositions;
}

void Checkers::addMovablePositions(
        std::vector< std::pair<Point, std::vector<Point>> > & movablePositions,
        const Point & position,
        Point & corner,
        const unsigned color)
{
    if (board.isOnBoard(corner))
    {
        std::vector<Point> captured; //les positions capturées à nettoyer

        if (board.isCellEmpty(corner) && captured.empty()) //move possible et autorisé car on a pas encore capturé
            movablePositions.push_back(std::pair<Point, std::vector<Point>>(corner, captured));
        else if (isEnnemyPosition(corner, color)) //capture
        {
            Point destination{corner.newRelativePoint
                    (corner.getRelativeDirection(position))};

            if (isEnnemyPosition(corner, color) //enlever ce test
                    && board.isOnBoard(destination)
                    && board.isCellEmpty(destination))
            {
                captured.push_back(corner);
                movablePositions.push_back(std::pair<Point, std::vector<Point>>(destination, captured));
            }
        }
    }
}

std::vector<Point> Checkers::getCornersFromDestination(Point & from
                                                       ,Point & destination)
{
    std::vector<Point> corners;
    std::vector<int> directions{NORTH_EAST,NORTH_WEST,SOUTH_EAST,SOUTH_WEST};
    int cornerFrom = destination.getRelativeDirection(from);

    directions.erase(std::remove(directions.begin(), directions.end(), cornerFrom), directions.end());

    corners = destination.getRelativePositions(directions);

    return corners;

}

bool Checkers::isEnnemyPosition(const Point & position
                                ,const unsigned color)
{
    return board.getCellAt(position).getColor() != color;
}

