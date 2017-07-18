
#include "catch.h"
#include "point.h"

TEST_CASE("Construction de points")
{
    Point p{2, 2};
    REQUIRE(p.getX() == 2);
    REQUIRE(p.getY() == 2);

    Point pp{p};
    REQUIRE(pp.getX() == 2);
    REQUIRE(pp.getY() == 2);

    Point ppp{45,99};
    REQUIRE(ppp.getX() == 45);
    REQUIRE(ppp.getY() == 99);
}

TEST_CASE("Déplacement d'un point")
{
    Point a{0,0};
    Point b{3,3};
    Point c{23,4};


    a.move(2,2);
    b.move(-3,3);
    c.move(-23,-4);

    REQUIRE(a.getX() == 2);
    REQUIRE(a.getY() == 2);

    REQUIRE(b.getX() == 0);
    REQUIRE(b.getY() == 6);

    REQUIRE(c.getX() == 0);
    REQUIRE(c.getY() == 0);
}
