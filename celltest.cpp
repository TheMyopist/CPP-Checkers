#include "catch.h"
#include "cell.h"

TEST_CASE("Construction de Cellules")
{
    Cell emptyPinkCell{PINK,true};
    Cell notEmptyBluecell{BLUE,false};
    Cell blackCell{BLACK,true};
    Cell copyOfBlackCell{blackCell};

    REQUIRE(emptyPinkCell.getColor() == PINK);
    REQUIRE(emptyPinkCell.isEmpty() == true);

    REQUIRE(notEmptyBluecell.getColor() == BLUE);
    REQUIRE(notEmptyBluecell.isEmpty() == false);

    REQUIRE(copyOfBlackCell.getColor() == BLACK);
    REQUIRE(copyOfBlackCell.isEmpty() == true);

}

TEST_CASE("Coloriage d'une cellule")
{
    Cell michaelJackson{BLACK,false};

    michaelJackson.colorize(WHITE);

    REQUIRE(michaelJackson.getColor() == WHITE);

}

TEST_CASE("Remplissage et nettoyage d'une cellule","[widget]")
{
    Cell emptyCell{GREEN,true};

    emptyCell.fill();

    REQUIRE(emptyCell.isEmpty() == false);

    emptyCell.clear();

    REQUIRE(emptyCell.isEmpty() == true);
}
