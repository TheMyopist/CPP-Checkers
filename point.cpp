#include <point.h>

Point::Point(const int x , const int y) : x{x} , y{y} {}

Point::Point(const Point & p) : x{p.getX()}, y{p.getY()} {}

void Point::move(const int dx, const int dy)
{
    x += dx;
    y += dy;
}

