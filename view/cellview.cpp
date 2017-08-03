#include "cellview.h"

CellView::CellView(Cell & cell, const Point & position,
                   const unsigned x, const unsigned y)
    :QGraphicsRectItem(viewUtilities::toQRect(position,x,y)),
     cell{cell}, pen{viewUtilities::toQColor(cell.getColor()),1,Qt::SolidLine},
     brush{cell.getColor()}
{
    this->setPen(this->pen);
    this->setBrush(this->brush);
}
