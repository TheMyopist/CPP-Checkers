#include "checkers.h"
#include <algorithm>
#include <iostream>

Checkers::Checkers(const bool isMultiplayer) : turn{0},
    gameOver{false}, board{Board()}, currentPlayer{(unsigned)rand() % 1}
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

void Checkers::addMan(const Point & position,const Man & man)
{
    board.getCellAt(position).addMan(man);
}

void Checkers::makeMove(std::pair<Point, std::vector<Point> > & pairToPlay)
{
    removeMan(currentPiecePosition);

    if((isOnCrownLine(pairToPlay.first)) && (!currentPiece.isKing()))
        currentPiece.crown();

    addMan(pairToPlay.first,currentPiece);

    for (Point & capturedEnemyPosition : pairToPlay.second)
        removeMan(capturedEnemyPosition);

    chosenMove = pairToPlay;

    notifyViews(MOVE_MADE);
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
        if (board.isCellEmpty(corner) && ((capturedOnPath.empty() && isInTheRightDirection(corner))
                                          || currentPiece.isKing()))
        {
            movablePositions.push_back(
                        std::pair<Point, std::vector<Point>>(corner, capturedOnPath));
            /*
            if (currentPiece.isKing())
            {
                int nbOfFreePos = addFreePositionsFromDiagonal(corner,
                                             corner.getRelativeDirection(position),
                                             movablePositions);

                if ((nbOfFreePos != 0) && )
                { // check not in vector
                    capturedOnPath.push_back(corner);
                    movablePositions.push_back(
                          std::pair<Point, std::vector<Point>>(destination, capturedOnPath));

                    getMovablePositionsFrom(destination, movablePositions, capturedOnPath);
                }
            }*/
        }
        else if (isEnnemyPosition(corner, currentPiece.getColor()))
        {
            Point destination{corner.newRelativePoint
                        (corner.getRelativeDirection(position))};

            if (isEnnemyPosition(corner,currentPiece.getColor())
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

bool Checkers::isEnnemyPosition(const Point & position,
                                const unsigned color)
{
    return board.getCellAt(position).getMan().getColor() != color;
}

bool Checkers::isOnCrownLine(const Point & position) const
{
    return ((currentPiece.getColor()) == (WHITE && position.getX() == 0))
            || ((currentPiece.getColor() == BLACK) && (position.getX() == board.getHeight() - 1));
}

bool Checkers::isInTheRightDirection(const Point & position) const
{
    int color = currentPiece.getColor();

    return ((color == WHITE) && (position.getX() < currentPiecePosition.getX()))
            || ((color == BLACK) && (position.getX() > currentPiecePosition.getX()));
}

std::vector<std::pair<Point, std::vector<Point>>> trimBiggestPaths
(std::vector<std::pair<Point, std::vector<Point>>> capturedPositions)
{
    std::vector<std::pair<Point, std::vector<Point>>> biggestPaths;
    size_t biggestSize = 0;
    size_t vectorSize = 0;


    for(std::pair<Point, std::vector<Point>> capturedPosition : capturedPositions )
    {
        vectorSize = capturedPosition.second.size();

        if(vectorSize > biggestSize)
            biggestSize = vectorSize;
    }

    for(std::pair<Point, std::vector<Point>> capturedPosition : capturedPositions )
    {
        vectorSize = capturedPosition.second.size();
        if(vectorSize == biggestSize)
            biggestPaths.push_back(capturedPosition);
    }

    return biggestPaths;
}

void Checkers::addView(CheckersView * newView)
{
    this->views.push_back(newView);
}

void::Checkers::notifyViews(unsigned checkersEvent)
{
    for(CheckersView view : this->views)
        view.update(checkersEvent);
}

Checkers::~Checkers(){}


void Checkers::switchCurrentPlayer()
{
    currentPlayer = ++currentPlayer % 2;

    notifyViews(PLAYER_SWITCHED);
}

void Checkers::setCurrentPosition(const Point & position)
{
    currentPiecePosition = position;
}
