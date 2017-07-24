#ifndef MAN_H
#define MAN_H

#include "color.h"
#include "man.h"
#include "point.h"

class Man
{

private:

    unsigned color;
    bool isKing;

public:

    Man(const unsigned = BLACK);

    const unsigned getColor() const;
    bool getIsKing() const;

    void move(Point newPosition);
    //void fly(Point newPosition); if isKing

    void crown();
};

inline const unsigned Man::getColor() const
{
    return color;
}


inline bool Man::getIsKing() const
{
    return isKing;
}

#endif // MAN_H
