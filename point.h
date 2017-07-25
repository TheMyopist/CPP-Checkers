#ifndef POINT_H
#define POINT_H

#include <ostream>
#include <cmath>
#include <vector>


/**
 * @brief Cette classe Point définit un Point de coordonnées (x,y)
 * dans le plan cartésien.
 * Elle définit la position de cet objet dans un espace à deux
 * dimensions.
 */
class Point{

private:
    /**
    * \brief x La distance, sur l'axe des abscisses, du point par
    * rapport à l'origine.
    */
    int x;

    /**
     * @brief y La distance, sur l'axe des ordonnées, du point par
     * rapport àl'origine.
     */
    int y;
public:
    /*!
    * \brief Instancie un point de coordonnées(0, 0)
    * Constructeur par défaut.
    */
    Point() = default;

    /*!
    * \brief Instancie le point de coordonnées spécifiées.
    * \param x l'abscisse du point
    * \param y l'ordonnée du point
    */
    Point(const int x, const int y);

    /*!
     * \brief Instancie un point par copie d'un autre point.
     * Constructeur de recopie.
     */
    Point(const Point & point);



    /*!
     * \brief move Déplace le point (modifie ses coordonnées) sur le
     * plan cartésien en fonction des valeurs reçues en paramètres.
     * \param dx Valeur à ajouter à la coordonnée X.
     * \param dy Valeur à ajouter à la coordonnée Y.
     */
    void move(const int dx,const int dy);

    /*!
     * \brief getX Retourne l'abscisse du point
     * \return l'abscisse du point
     */
    int getX() const;

    /*!
     * \brief getY Retourne l'ordonnée du point
     * \return l'ordonnée du point
     */
    int getY() const;

    Point  getUpperRight() const;

    Point getLowerRight() const;

    Point  getUpperLeft() const;

    Point  getLowerLeft() const;

    std::vector<Point> getCorners() const;


    /*!
     * \brief Permet de copier le contenu d'un point dans un
     * autre point.
     * \return Le point courant modifié.
     */
    Point& operator=(const Point& other);

    /*!
     * \brief Permet de savoir si deux points n'ont pas les
     * mêmes coordonnées
     * \return true si les deux points sont localisés
     * à des endroits différents
     */
    bool operator!=(const Point &) const;

    /*!
     * \brief Permet de savoir si deux points ont des coordonnées
     * identiques
     * \return true si les points partangent les mêmes coordonées
     */
    bool operator==(const Point &) const;


};
/*!
 * \brief Redefinition de l'operateur << servant à produire un
 * affichage formaté
 * \return Une chaîne formatée représentant de manière
 * textuelle le point donnée en paramètre
 */
std::ostream & operator<<(std::ostream &, const Point &);

inline int Point::getX() const
{
    return x;
}

inline int Point::getY() const
{
    return y;
}

inline Point Point::getUpperLeft() const
{
    return Point{x+1, y-1};
}

inline Point Point::getUpperRight() const
{
    return Point{x+1,y+1};
}

inline Point  Point::getLowerLeft() const
{
    return Point{x-1,y-1};
}

inline Point  Point::getLowerRight() const
{
    return Point{x-1,y+1};
}

inline std::vector<Point>  Point::getCorners() const
{
    std::vector<Point> corners;
    corners.push_back(getLowerLeft());
    corners.push_back(getLowerRight());
    corners.push_back(getUpperLeft());
    corners.push_back(getUpperRight());

    return corners;
}

#endif // POINT_HPP
