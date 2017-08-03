#include "viewutilities.h"

#include "view/config.h"

QPoint viewUtilities::toQPoint(const Point & point)
{
    return QPoint{point.getX(), point.getY()};
}

QPoint viewUtilities::toRelativeQPoint(Point & point)
{
    return QPoint{point.getX() * CELL_SIZE, point.getY() * CELL_SIZE};
}

QRect viewUtilities::toQRect(const Point & upLeftCorner, const unsigned width,
                             const unsigned height)
{
    return QRect(upLeftCorner.getX() * CELL_SIZE, upLeftCorner.getY() * CELL_SIZE,
                 CELL_SIZE, CELL_SIZE);
}

QColor viewUtilities::toQColor(const unsigned color)
{
    int r = color & 0xff;
    int g = (color >> 8) & 0xff;
    int b = (color >> 16) & 0xff;

    return QColor(r, g, b);
}
