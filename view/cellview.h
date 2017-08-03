#ifndef CELLVIEW_H
#define CELLVIEW_H

#include <QGraphicsItem>
#include <view/viewutilities.h>


class CellView : public QRectItem
{

private:
    Cell cell;
public:
    CellView(Cell & cell, const Point &, const unsigned ,
             const unsigned);
};

#endif // CELLVIEW_H
