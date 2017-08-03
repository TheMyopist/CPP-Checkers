#include <iostream>
#define CATCH_CONFIG_RUNNER
#include <QApplication>
#include <QtGui>

#include "catch.h"
#include <point.h>
#include <cell.h>
#include <board.h>
#include <checkers.h>
#include <view/menu.h>
#include <view/manview.h>
#include <view/cellview.h>
#include <view/Boardview.h>
#include "view/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow view;

    view.show();

    return app.exec();
//      // global setup...

//      int result = Catch::Session().run( argc, argv );

//      // global clean-up...

//      return ( result < 0xff ? result : 0xff );
}
