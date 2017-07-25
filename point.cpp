#include <point.h>

Point::Point(const int x , const int y) : x{x} , y{y} {}

Point::Point(const Point & p) : x{p.getX()}, y{p.getY()} {}

void Point::move(const int direction)
{
    switch(direction)
    {
        case SOUTH: x++;
        break;
        case SOUTH_EAST: x++; y++;
        break;
        case SOUTH_WEST: x++; y--;
        break;
        case NORTH: x--;
        break;
        case NORTH_EAST: x--; y++;
        break;
        case NORTH_WEST: x--; y--;
        break;
        case WEST: y--;
        break;
        case EAST: y++;
        break;
    }
}

int Point::getRelativeDirection(Point & from)
{
    int relativeDirection;

    if (x == from.x)
    {
     if (y == from.y) {relativeDirection = CENTER;}
     else {relativeDirection = y > from.y ? WEST : EAST;}
    }
    else if (x > from.x)
    {
     if (y == from.y) {relativeDirection = NORTH;}
     else {relativeDirection = y > from.y ? NORTH_WEST : NORTH_EAST;}

    }
    else if (x < from.x)
    {
      if (y == from.y) {relativeDirection = SOUTH;}
      else {relativeDirection = y > from.y ? SOUTH_WEST : SOUTH_EAST;}
    }
    return relativeDirection;
}
