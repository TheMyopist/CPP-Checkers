#include "catch.h"
#include "board.h"
//#include "cell.h"

TEST_CASE("Construction de boards")
{
    board defaultBoard{};
    board customBoard{44,67};

    REQUIRE(defaultBoard.getHeight() == DEFAULTHEIGHT);
    REQUIRE(defaultBoard.getWidth() == DEFAULTWIDTH);

    REQUIRE(customBoard.getHeight() == 44);
    REQUIRE(customBoard.getWidth() == 67);

    REQUIRE(defaultBoard.getCellAt(Point{2,3}).isEmpty() == true);
    REQUIRE(defaultBoard.getCellAt(Point{2,3}).getColor() == GREY);

}

TEST_CASE("Coloriage d'un board")
{
    board greyBoard{};
    greyBoard.colorize();

    REQUIRE(greyBoard.getCellAt(Point{0,0}).getColor() == BLACK);
    REQUIRE(greyBoard.getCellAt(Point{0,1}).getColor() == WHITE);
    REQUIRE(greyBoard.getCellAt(Point{1,0}).getColor() == WHITE);
    REQUIRE(greyBoard.getCellAt(Point{1,1}).getColor() == BLACK);
    REQUIRE(greyBoard.getCellAt(Point{2,0}).getColor() == BLACK);
    REQUIRE(greyBoard.getCellAt(Point{2,1}).getColor() == WHITE);

}
