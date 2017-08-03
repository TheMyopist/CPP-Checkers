#ifndef MANVIEW_H
#define MANVIEW_H

#include <QWidget>
#include <QGraphicsItem>
#include <QPen>
#include <QRect>
#include <view/viewutilities.h>
#include <man.h>

class ManView : public QGraphicsEllipseItem
{

private:
    Man  man;
    Point position;

    QPen pen;

    QBrush brush;

public:
    ManView(Man &man, const Point &);

    ~ManView();
};

#endif // MANVIEW_H
