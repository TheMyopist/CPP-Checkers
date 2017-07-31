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
        const Point & position)
{
    std::vector< std::pair<Point, std::vector<Point>> > movablePositions;
    std::vector<Point> capturedOnPath;

    getMovablePositionsFrom(position, movablePositions, capturedOnPath);

    return movablePositions;
}

void Checkers::getMovablePositionsFrom(
        const Point & position,
        std::vector< std::pair<Point, std::vector<Point>> > & movablePositions,
        std::vector<Point> capturedOnPath)
{
    std::vector<Point> corners = position.getCorners();

    if (! capturedOnPath.empty())
        corners.erase(std::remove(corners.begin(), corners.end(), capturedOnPath.back()), corners.end());

    for(Point & corner : corners)
        addMovablePositions(movablePositions, position, corner, capturedOnPath);
}

void Checkers::addMovablePositions(
        std::vector< std::pair<Point, std::vector<Point>> > & movablePositions,
        const Point & position,
        Point & corner,
        std::vector<Point> capturedOnPath)
{
    if (board.isOnBoard(corner))
    {
        if (board.isCellEmpty(corner) && capturedOnPath.empty())
        {
            movablePositions.push_back(
                    std::pair<Point, std::vector<Point>>(corner, capturedOnPath));
        }
        else if (isEnnemyPosition(corner, currentPieceColor))
        {
            Point destination{corner.newRelativePoint
                    (corner.getRelativeDirection(position))};

            if (isEnnemyPosition(corner, this->currentPieceColor)
                    && board.isOnBoard(destination)
                    && board.isCellEmpty(destination))
            {
                capturedOnPath.push_back(corner);
                movablePositions.push_back(
                      std::pair<Point, std::vector<Point>>(destination, capturedOnPath));

                getMovablePositionsFrom(destination, movablePositions, capturedOnPath);
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

