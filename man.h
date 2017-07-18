#ifndef MAN_H
#define MAN_H

#include "point.h"


class Man
{

private:

    unsigned color;
    Point position;
    bool isAlive; //?
    //bool isKing;

public:

    unsigned getColor() const;
    Point & getPosition() const;

    void move(Point newPosition);
    //void fly(Point newPosition); if isKing

    void crown();
    void remove();



};

#endif // MAN_H
