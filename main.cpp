#include <iostream>
#define CATCH_CONFIG_RUNNER
#include "catch.h"
#include <point.h>
#include <cell.h>
#include <board.h>
#include <checkers.h>

int main(int argc, char *argv[])
{
    Checkers checkers{};
    Man currentPiece{};
    Point currentPiecePosition{7,5};

    checkers.setCurrentPiece(currentPiece, currentPiecePosition);
    checkers.addMan(currentPiecePosition,currentPiece);
    checkers.addMan(Point{6,6},Man{WHITE});
//    checkers.addMan(Point{6,6},Man{WHITE});
//    checkers.addMan(Point{4,4},Man{WHITE});
//    checkers.addMan(Point{2,4},Man{BLACK});
//    checkers.addMan(Point{2,2},Man{WHITE});

    std::vector<std::pair<Point, std::vector<Point>>> movablePositions =  checkers.getMovablePositionsFrom(currentPiecePosition);
 int a = 1;
//      // global setup...

//      int result = Catch::Session().run( argc, argv );

//      // global clean-up...

//      return ( result < 0xff ? result : 0xff );
}
