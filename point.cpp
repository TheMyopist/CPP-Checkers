#include <point.h>

Point::Point(const int x , const int y) : x{x} , y{y} {}

Point::Point(const Point & p) : x{p.getX()}, y{p.getY()} {}

void Point::moveToDirection(int direction)
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

int Point::getRelativeDirection(const Point & from) const
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

void Point::moveFurtherAwayFrom(const Point & from, int times)
{
    int direction = getRelativeDirection(from);

    for (int i=0; i<times; i++)
        moveToDirection(direction);
}

std::vector<Point> Point::getCorners()
{
    std::vector<int> directions{SOUTH_WEST,SOUTH_EAST,NORTH_EAST,NORTH_WEST};

    return getRelativePositions(directions);
}

std::vector<Point> Point::getRelativePositions(std::vector<int> & directions)
{
    std::vector<Point> positions;

    for(int direction : directions)
        positions.push_back(newRelativePoint(direction));

    return positions;
}

Point Point::newRelativePoint(int direction)
{
    Point thisCpy{*this};

    thisCpy.moveToDirection(direction);

    return thisCpy;
}
