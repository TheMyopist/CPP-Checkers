#include "cellview.h"

#include <iostream>

CellView::CellView(Cell & cell, const Point & position)
    : QGraphicsRectItem(viewUtilities::toQRect(position)), position{position},
     cell{cell}, pen{viewUtilities::toQColor(cell.getColor()), 1},
     brush{cell.getColor()}
{
    this->setPen(this->pen);
    this->setBrush(this->brush);
}

void CellView::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    std::cout << this->position.getX() << " " << this->position.getY()
              << std::endl;
}
