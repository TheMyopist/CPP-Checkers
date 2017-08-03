#include "viewutilities.h"

QPoint viewUtilities::toQPoint(const Point & point)
{
    return QPoint{point.getX(), point.getY()};
}

QRect viewUtilities::toQRect(const Point & point, const unsigned x,
                             const unsigned y)
{
    QPoint qPoint = viewUtilities::toQPoint(point);

    return QRect(qPoint.x(),qPoint.y(),x,y);
}

QColor viewUtilities::toQColor(const unsigned color)
{
    int r = color & 0xff;
    int g = (color >> 8) & 0xff;
    int b = (color >> 16) & 0xff;

    return QColor(r, g, b);
}
