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
    bool isClickable;
    Man   man;
    Point position;

    QPen pen;

    QBrush brush;

public:
    ManView(Man &man, const Point &);

    void update(const Point &);
    void updatePosition(const Point &);
    void setClickable(bool);

    Man getMan();

    ~ManView();

protected:

    void mousePressEvent(QGraphicsSceneMouseEvent *);

};

inline Man ManView::getMan()
{
    return man;
}

#endif // MANVIEW_H
