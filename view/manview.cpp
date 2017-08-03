#include "manview.h"

ManView::ManView(Man & man, const Point & position,
                 const unsigned cellHeight, const unsigned cellWidth)
    : QGraphicsEllipseItem(viewUtilities::toQRect(position,cellHeight,cellWidth)),
      man{man},
      pen{viewUtilities::toQColor(man.getColor()),1,Qt::SolidLine},
      brush{man.getColor()}
{
    this->setPen(this->pen);
    this->setBrush(this->brush);
}

ManView::~ManView() {}
