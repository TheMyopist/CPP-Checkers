#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include "view/cellview.h"
#include "view/manview.h"
#include "checkers.h"
#include "checkersevent.h"
#include <QGraphicsView>
#include <QGraphicsScene>

class Checkers;
class ManView;
class CellView;

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

    void update(unsigned);

    void switchPlayer();

    void updatePositions();

    void selectPieceToPlay(Point &);

    void disableAllCells();

    void disableAllMen();

    void highlightMovablepositions(std::vector< std::pair<Point, std::vector<Point>> > &
                            movablepositions);

    void selectMovePosition(const Point &);
};

#endif // BOARDVIEW_H
