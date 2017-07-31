#include "catch.h"
#include "checkers.h"

TEST_CASE("Calcul des positions jouables pour un pion")
{
  Board board{};
  Checkers checkers{};
  Man currentPiece{};
  Point currentPiecePosition{3,3};

  checkers.addMan(Point{4,8},Man{WHITE});
  checkers.addMan(Point{6,6},Man{WHITE});
  checkers.addMan(Point{4,4},Man{WHITE});
  checkers.addMan(Point{2,4},Man{BLACK});
  checkers.addMan(Point{2,2},Man{WHITE});

  std::vector<std::pair<Point, std::vector<Point>>> movablePositions =  checkers.getMovablePositionsFrom(currentPiecePosition);
  REQUIRE(movablePositions.at(0).first == Point{});

}

