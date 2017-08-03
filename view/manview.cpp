#include "manview.h"

ManView::ManView(Man & man, const Point & position)
    : QGraphicsEllipseItem(viewUtilities::toQRect(position)),
      man{man},
      position{position},
      pen{viewUtilities::toQColor(man.getColor()),1,Qt::SolidLine},
      brush{man.getColor()}
{
    this->setPen(this->pen);
    this->setBrush(this->brush);
}

ManView::~ManView(){}
