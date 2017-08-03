#ifndef VIEWUTILITIES_HPP
#define VIEWUTILITIES_HPP

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>
#include <QColor>
#include <QPoint>
#include <QRect>
#include <QString>
#include <point.h>
#include "view/config.h"

/*!
 * Divers fonctions utilitaires nécessaires aux vues.
 */
namespace viewUtilities
{

/*!
 * \brief Permet de transformer un point en QPoint.
 *
 * \return La représentation QPoint du Point passé en paramètre.
 * \see Point
 */
QPoint toQPoint(const Point &);

QPoint toRelativeQPoint(Point & point);

QRect toQRect(const Point & upLeftCorner, const unsigned width = CELL_SIZE,
                             const unsigned height = CELL_SIZE);

QColor toQColor(const unsigned);


}

#endif // VIEWUTILITIES_HPP
