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

QRect  toQRect(const Point & point, const unsigned x,
                             const unsigned y);

QColor toQColor(const unsigned);


}

#endif // VIEWUTILITIES_HPP
