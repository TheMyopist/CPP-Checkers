#include "cellview.h"

#include <iostream>

CellView::CellView(Cell & cell, const Point & position)
    : QGraphicsRectItem(viewUtilities::toQRect(position)), position{position},
     cell{cell}, pen{viewUtilities::toQColor(cell.getColor()), 2},
     brush{cell.getColor()}
{
    this->setPen(this->pen);
    this->setBrush(this->brush);
}

void CellView::highLight()
{
    brush.setColor(viewUtilities::toQColor(GREEN));
    this->setBrush(this->brush);
}

void CellView::setDefaultBackground()
{
    brush.setColor(viewUtilities::toQColor(cell.getColor()));
    this->setBrush(this->brush);
}
