#ifndef MAN_H
#define MAN_H

#include "point.h"


class Man
{

private:

    unsigned color;
    bool isKing;

public:

    Man(const unsigned);

    unsigned getColor() const;

    void move(Point newPosition);
    //void fly(Point newPosition); if isKing

    void crown();
    void remove();



};

inline unsigned Man::getColor() const
{
    return color;
}



#endif // MAN_H
