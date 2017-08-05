#include "manview.h"

ManView::ManView(Man & man, const Point & position)
    : QGraphicsEllipseItem(viewUtilities::toQRect(position)),
      man{man},
      position{position},
      pen{viewUtilities::toQColor(man.getColor()),1,Qt::SolidLine},
      brush{man.getColor()},
      isClickable{false}
{
    this->setPen(this->pen);
    this->setBrush(this->brush);
}

void ManView::setClickable(bool isClickable)
{
    this->isClickable = isClickable;
}

ManView::~ManView(){}

void ManView::mousePressEvent(QGraphicsSceneMouseEvent *)
{
//    if (isClickable)
//    {
//    }
}
