#ifndef MANVIEW_H
#define MANVIEW_H

#include <QWidget>
#include <QGraphicsItem>
#include <QPen>
#include <QRect>
#include <view/viewutilities.h>
#include <man.h>

class manView : public QGraphicsEllipseItem
{

private:
    Man  man;

    QPen pen;

    QBrush brush;
public:
    manView(Man &man, const Point &, const unsigned, const unsigned);

    ~manView();

    void crown();
protected:
    void highlightMan(QMouseEvent *);
};

#endif // MANVIEW_H
