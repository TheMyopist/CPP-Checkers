#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include <board.h>
#include "point.h"
#include <view/cellview.h>
#include <view/manview.h>
#include <QGraphicsView>
#include <QGraphicsScene>

class BoardView : public QGraphicsView
{
private:
    Board board;

    std::vector<std::vector<CellView*>> grid;
    std::vector<std::vector<ManView*>> men;

    QGraphicsScene * scene;

public:
    BoardView(QWidget * parent);
};

#endif // BOARDVIEW_H
