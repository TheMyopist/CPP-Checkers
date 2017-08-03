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

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QGraphicsView view;
    QGraphicsScene *scene = new QGraphicsScene(0,0,300,300,&view);
    QColor color = viewUtilities::toQColor(GREEN);

    scene->setBackgroundBrush(color);

    view.setScene(scene);
    view.show();

    return app.exec();
//      // global setup...

//      int result = Catch::Session().run( argc, argv );

//      // global clean-up...

//      return ( result < 0xff ? result : 0xff );
}
