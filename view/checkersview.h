#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include "view/cellview.h"
#include "view/manview.h"
#include "checkers.h"
#include "checkersevent.h"
#include <QGraphicsView>
#include <QGraphicsScene>

class Checkers;

class CheckersView : public QGraphicsView
{
private:
    Checkers * checkers;

    std::vector<std::vector<CellView*>> grid;
    std::vector<std::vector<ManView*>> men;

    QGraphicsScene * scene;

public:
    CheckersView(QWidget * parent);

    ~CheckersView();

    void showMovablePositionsFrom(const Point &); //avec un putain de clic?

    void update(unsigned);
};

#endif // BOARDVIEW_H
