#include "manview.h"

#include <iostream>

ManView::ManView(Man & man, const Point & position, CheckersView *checkersView)
    : QGraphicsEllipseItem(viewUtilities::toQRect(position)),
      man{man},
      position{position},
      pen{viewUtilities::toQColor(man.getColor() == BLACK ? BLUE: RED), 2,Qt::SolidLine},
      brush{man.getColor()},
      isClickable{false}, checkersView{checkersView}
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
    if (isClickable)
        this->checkersView->selectPieceToPlay(this->position);
}
