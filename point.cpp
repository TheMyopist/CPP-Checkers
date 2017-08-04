#include <point.h>

Point::Point(const int x , const int y) : x{x} , y{y} {}

Point::Point(const Point & p) : x{p.getX()}, y{p.getY()} {}

void Point::moveToDirection(int direction)
{
    switch(direction)
    {
        case SOUTH: y++;
        break;
        case SOUTH_EAST: x++; y++;
        break;
        case SOUTH_WEST: x--; y++;
        break;
        case NORTH: y--;
        break;
        case NORTH_EAST: x++; y--;
        break;
        case NORTH_WEST: x--; y--;
        break;
        case WEST: x--;
        break;
        case EAST: x++;
        break;
    }
}

int Point::getRelativeDirection(const Point & from)
{
    int relativeDirection;

    if (x == from.x)
    {
        if (y == from.y) {relativeDirection = CENTER;}
        else {relativeDirection = y > from.y ? SOUTH : NORTH;}
    }
    else if (x > from.x)
    {
        if (y == from.y) {relativeDirection = EAST;}
        else {relativeDirection = y > from.y ? NORTH_EAST : NORTH_WEST;}
    }
    else if (x < from.x)
    {
        if (y == from.y) {relativeDirection = WEST;}
        else {relativeDirection = y > from.y ? NORTH_WEST : NORTH_EAST;}
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

std::vector<Point> Point::getRelativePositions(std::vector<int> & directions) const
{
    std::vector<Point> positions;

    for(int direction : directions)
        positions.push_back(newRelativePoint(direction));

    return positions;
}

Point Point::newRelativePoint(const int direction) const
{
    Point thisCpy{*this};

    thisCpy.moveToDirection(direction);

    return thisCpy;
}

bool Point::operator==(const Point & point) const
{
    return (this->x == point.x)
            && (this->y == point.y);
}
