#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "point.h"

TEST_CASE("Construction de points")
{
    Point p{2, 2};
    REQUIRE(p.getX() == 2);
    REQUIRE(p.getY() == 2);

//    Point pp{p};
//    REQUIRE(utilities::equals(pp.getX(), 2.));
//    REQUIRE(utilities::equals(pp.getY(), 2.));

    Point ppp(2, 99);
    REQUIRE(ppp.getX() == 2);
    REQUIRE(ppp.getY() == 99);

}
