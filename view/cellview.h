#ifndef CELLVIEW_H
#define CELLVIEW_H

#include <QGraphicsItem>
#include <cell.h>
#include <view/viewutilities.h>
#include "view/checkersview.h"

class CheckersView;

class CellView : public QGraphicsRectItem
{

private:
    bool isClickable;

    Cell cell;

    Point position;

    CheckersView * checkersView;

    QPen pen;

    QBrush brush;

public:
    CellView(Cell & cell, const Point & position, CheckersView * checkersView);

    void highlight();

    Cell & getCell();

    void setClickable(bool isClickable);

    void setNormalColor();

protected:

    void mousePressEvent(QGraphicsSceneMouseEvent *);
};

#endif // CELLVIEW_H
