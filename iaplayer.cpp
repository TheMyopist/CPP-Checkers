#include "iaplayer.h"

IAplayer::IAplayer(Checkers *checkers, const unsigned color,
                   const unsigned intelligence) : Player{color, 20, true},
    checkers{checkers},
    intelligence{intelligence} {}

void IAplayer::play()
{
    checkers->setCurrentPiecePosition(priorityToMovement().first); //position du pion à jouer
    checkers->makeMove(priorityToMovement().second);
}

//move as soon as possible
std::pair<Point,Point>  IAplayer::priorityToMovement()
{
    std::pair<Point,Point> movement;
    std::vector< std::pair<Point, std::vector<Point>> > movablesPositions;

    for (int i = 0; i < (int)checkers->getBoard().getHeight(); i++ )
    {
        for (int j = 0; j < (int)checkers->getBoard().getWidth(); j++ )
        {
            if((!checkers->getBoard().getCellAt(Point{j,i}).isEmpty())
                    && (checkers->getBoard().getCellAt(Point{j,i}).getMan().getColor() ==
                        checkers->getCurrentPlayer()->getColor()))
            {
                movablesPositions = checkers->getMovablePositionsFrom(Point{j,i});

                //si il y a moyen de bouger avec ce pion
                if(movablesPositions.size() > 0)
                {
                    //le point de départ est set
                    movement.first = Point{j,i};
                    //calcul de la destination
                    movement.second
                            = trimDestinationWithPriorityToMovement
                            (movablesPositions);
                }
            }
        }
    }
    return movement;
}

Point  IAplayer::trimDestinationWithPriorityToMovement
(std::vector< std::pair<Point, std::vector<Point>> > movablesPositions)
{
    Point destination;

    for(auto & movable : movablesPositions)
    {
        if(movable.second.size() == 0)
           return destination = movable.first;
    }

    destination = movablesPositions[0].first;

    return destination;
}
