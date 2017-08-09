#include "checkers.h"
#include <algorithm>
#include <iostream>

Checkers::Checkers(const bool isMultiplayer) : turn{0},
    gameOver{false}, board{Board()}, currentPlayer{(unsigned)rand() % 2}
{
    initPlayers(isMultiplayer);
}

void Checkers::initPlayers(const bool isMultiplayer)
{
    if(isMultiplayer)
        players = {new Player{WHITE}, new Player{BLACK}};
    else players = {new Player{WHITE}, new IAplayer{this,BLACK}};
}

void Checkers::removeMan(const Point position)
{
    board.getCellAt(position).clear();
}

void Checkers::addMan(const Point & position,const Man & man)
{
    board.getCellAt(position).addMan(man);
}

void Checkers::makeMove(Point dest)
{

    int index = 0; int i = 0;
    std::vector< std::pair<Point, std::vector<Point>> > movablePositions
            = getMovablePositionsFrom(currentPiecePosition);

    for (auto & pos : movablePositions)
    {
        if (pos.first == dest)
            index = i;

        i++;
    }

    chosenMove = movablePositions[index];

    removeMan(currentPiecePosition);
    addMan(chosenMove.first, currentPiece);

    if((isOnCrownLine(chosenMove.first)) && (!currentPiece.isKing()))
        currentPiece.crown();

    for (Point & capturedEnemyPosition : chosenMove.second) {
        removeMan(capturedEnemyPosition);
        players.at(getEnnemy())->removeMan();
    }

    notifyViews(MOVE_MADE);

    if(isGameOver())
    {
        notifyViews(END_OF_GAME);
    }
    else switchCurrentPlayer();
}

std::vector< std::pair<Point, std::vector<Point>> > Checkers::getMovablePositionsFrom(
        const Point & position)
{
    std::vector< std::pair<Point, std::vector<Point>> > movablePositions;
    std::vector<Point> capturedOnPath;

    getMovablePositionsFrom(position, movablePositions, capturedOnPath);

    return trimBiggestPaths(movablePositions);
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
        if (board.isCellEmpty(corner) && capturedOnPath.empty() && isInTheRightDirection(corner))
        {
            movablePositions.push_back(
                        std::pair<Point, std::vector<Point>>(corner, capturedOnPath));
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
    Cell & cellToCheck = board.getCellAt(position);

    return (!cellToCheck.isEmpty()) &&
            (cellToCheck.getMan().getColor() != color);
}

bool Checkers::isOnCrownLine(const Point & position) const
{
    return ((currentPiece.getColor()) == (WHITE && position.getX() == 0))
            || ((currentPiece.getColor() == BLACK) && (position.getX() == board.getHeight() - 1));
}

bool Checkers::isInTheRightDirection(const Point & position) const
{
    int color = currentPiece.getColor();

    return ((color == WHITE) && (position.getY() < currentPiecePosition.getY()))
            || ((color == BLACK) && (position.getY() > currentPiecePosition.getY()));
}

std::vector<std::pair<Point, std::vector<Point>>> Checkers::trimBiggestPaths
(std::vector<std::pair<Point, std::vector<Point>>> & capturedPositions)
{
    std::vector<std::pair<Point, std::vector<Point>>> biggestPaths;
    size_t biggestSize = 0;
    size_t vectorSize = 0;


    for(std::pair<Point, std::vector<Point>> & capturedPosition  : capturedPositions )
    {
        vectorSize = capturedPosition.second.size();

        if(vectorSize > biggestSize)
            biggestSize = vectorSize;
    }

    for(std::pair<Point, std::vector<Point>> & capturedPosition : capturedPositions )
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
    for(CheckersView * view : this->views)
        view->update(checkersEvent);
}

Checkers::~Checkers(){}


void Checkers::switchCurrentPlayer()
{
    currentPlayer = getEnnemy();

    notifyViews(PLAYER_SWITCHED);
}

void Checkers::setCurrentPiecePosition(const Point & position)
{
    currentPiecePosition = position;
    currentPiece = board.getCellAt(position).getMan();
}

std::pair<Point, std::vector<Point>> & Checkers::getChosenMove()
{
    return chosenMove;
}

Point & Checkers::getCurrentPiecePosition()
{
    return this->currentPiecePosition;
}

const unsigned Checkers::getEnnemy() const
{
    return (currentPlayer + 1) % 2;
}

bool Checkers::isGameOver()
{
    return (players.at(getEnnemy())->getNumberOfMen() == 0)
           || !canMakeMove();
}

bool Checkers::canMakeMove()
{
    std::vector<Point> positions;
    bool canMove = false;

    for (int i = 0; i < (int)board.getHeight(); i++ )
    {
        for (int j = 0; j < (int)board.getWidth(); j++ )
        {
            if((!board.getCellAt(Point{j,i}).isEmpty())
                    && (board.getCellAt(Point{j,i}).getMan().getColor() ==
                        players.at(getEnnemy())->getColor()))
            {
                positions.push_back(Point{j,i});
            }
        }
    }

    Point currentPiecePositionCpy = currentPiecePosition;

    for(Point & position : positions)
    {
        this->setCurrentPiecePosition(position);
        auto movablePosition = getMovablePositionsFrom(position);

        canMove = (canMove || (movablePosition.size() > 0));
    }

    this->setCurrentPiecePosition(currentPiecePositionCpy);

    return canMove;
}

