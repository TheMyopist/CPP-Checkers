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

    QPen pen;

    QBrush brush;

    QGraphicsEllipseItem crown;
public:
    ManView(Man &man, const Point &, const unsigned, const unsigned);

    ~ManView();

    //void crown();
protected:
    void highlightMan(QMouseEvent *);
};

#endif // MANVIEW_H
