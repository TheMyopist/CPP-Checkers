#include <point.h>

Point::Point(const int x , const int y) : x{x} , y{y} {}

void Point::move(const int dx, const int dy)
{
    x += dx;
    y += dy;
}

