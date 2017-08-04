#ifndef CELLVIEW_H
#define CELLVIEW_H

#include <QGraphicsItem>
#include <cell.h>
#include <view/viewutilities.h>


class CellView : public QGraphicsRectItem
{

private:
    Cell cell;
    Point position;

    QPen pen;

    QBrush brush;

public:
    CellView(Cell & cell, const Point & position);

    void highLight();
    void setDefaultBackground();
};

#endif // CELLVIEW_H
