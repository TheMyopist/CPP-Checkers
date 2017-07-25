
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

}
