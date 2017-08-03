#ifndef CELLVIEW_H
#define CELLVIEW_H

#include <QGraphicsItem>
#include <cell.h>
#include <view/viewutilities.h>


class CellView : public QGraphicsRectItem
{

private:
    Cell cell;

    QPen pen;

    QBrush brush;
public:
    CellView(Cell & cell, const Point &, const unsigned ,
             const unsigned);
};

#endif // CELLVIEW_H
