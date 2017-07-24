#ifndef MAN_H
#define MAN_H

#include "point.h"


class Man
{

private:

    unsigned color;
    bool isKing;
    bool isAlive;

public:

    Man(const unsigned);

    const unsigned getColor() const;
    const bool getIsAlive() const;
    bool getIsKing() const;

    void move(Point newPosition);
    //void fly(Point newPosition); if isKing

    void crown();
    void remove();



};

inline const unsigned Man::getColor() const
{
    return color;
}

inline const bool Man::getIsAlive() const
{
    return isAlive;
}

inline bool Man::getIsKing() const
{
    return isKing;
}

#endif // MAN_H
