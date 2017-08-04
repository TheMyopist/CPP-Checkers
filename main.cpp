#include <iostream>
#define CATCH_CONFIG_RUNNER
#include <QApplication>
#include <QtGui>

#include "catch.h"
#include <point.h>
#include <cell.h>
#include <board.h>
#include <checkers.h>
#include <view/mainmenu.h>
#include <view/manview.h>
#include <view/cellview.h>
#include <view/Boardview.h>
#include "view/mainwindow.h"

int main(int argc, char *argv[])
{
    Checkers check{};
    check.addMan(Point{3,2},Man{});
    check.addMan(Point{4,3},Man{WHITE});
    check.addMan(Point{2,5},Man{WHITE});
    check.addMan(Point{4,5},Man{WHITE});
    check.addMan(Point{6,5},Man{WHITE});
    std::vector< std::pair<Point, std::vector<Point>> > test = check.getMovablePositionsFrom(Point{3,2});
    int a = 0;
    //        QApplication app(argc, argv);

    //        MainWindow view;

    //        view.show();

    //        return app.exec();
    //      // global setup...

    //      int result = Catch::Session().run( argc, argv );

    //      // global clean-up...

    //      return ( result < 0xff ? result : 0xff );
}
