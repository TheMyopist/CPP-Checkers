#ifndef IAPLAYER_H
#define IAPLAYER_H

/**
* \brief Définition des contantes désignant le comportement de l'IA
*/
#define FIRST_POSSIBLE 0
#define RANDOM 1
#define PRIORITY_TO_MOVEMENT 2

#define NUMBER_OF_BEHAVIOURS 3

#include <random>
#include "player.h"
#include "checkers.h"


class Checkers;

class IAplayer : public Player
{

private:
    Checkers * checkers;

    unsigned behaviour;
public:
    IAplayer(Checkers *,const unsigned, const unsigned = rand() % NUMBER_OF_BEHAVIOURS);

    void play(); //makeMove en fonction de la difficulté

    std::pair<Point,Point> priorityToMovement();

    Point trimDestination(std::vector< std::pair<Point, std::vector<Point>> > movablesPositions);

    Point trimFirstPossibleDestination(std::vector< std::pair<Point, std::vector<Point>> > movablesPositions);

    Point trimRandomDestination
    (std::vector< std::pair<Point, std::vector<Point>> > movablesPositions);

    Point trimDestinationWithPriorityToMovement
    (std::vector< std::pair<Point, std::vector<Point>> > movablesPositions);
};

#endif // IAPLAYER_H
