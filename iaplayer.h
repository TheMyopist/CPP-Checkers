#ifndef IAPLAYER_H
#define IAPLAYER_H

#include "player.h"
#include "checkers.h"

class Checkers;

class IAplayer : public Player
{

private:
    Checkers * checkers;

    unsigned intelligence;
public:
    IAplayer(Checkers *,const unsigned, const unsigned = 0);

    void play(); //makeMove en fonction de la difficulté

    std::pair<Point,Point> priorityToMovement();

    Point trimDestinationWithPriorityToMovement(std::vector< std::pair<Point, std::vector<Point>> > movablesPositions);
};

#endif // IAPLAYER_H
