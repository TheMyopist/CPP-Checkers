#include "cellview.h"

#include <iostream>

CellView::CellView(Cell & cell, const Point & position, CheckersView *checkersView)
    : QGraphicsRectItem(viewUtilities::toQRect(position)), position{position},
      cell{cell}, pen{viewUtilities::toQColor(cell.getColor()), 2},
      brush{cell.getColor()}, checkersView{checkersView}, isClickable{false}
{
    this->setPen(this->pen);
    this->setBrush(this->brush);
}

void CellView::highlight()
{
    brush.setColor(Qt::green);
    this->setBrush(this->brush);
}

void CellView::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    if (isClickable)
        this->checkersView->selectMovePosition(this->position);
}

Cell & CellView::getCell()
{
    return cell;
}

void CellView::setClickable(bool isClickable)
{
    this->isClickable = isClickable;
}

void CellView::setNormalColor()
{
    brush.setColor(viewUtilities::toQColor(cell.getColor()));
    this->setBrush(this->brush);
}
