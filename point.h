#ifndef POINT_H
#define POINT_H

#include <ostream>
#include <cmath>
#include <vector>

// DIRECTIONS
#define CENTER     0
#define NORTH      1
#define NORTH_EAST 2
#define NORTH_WEST 3
#define SOUTH      4
#define SOUTH_EAST 5
#define SOUTH_WEST 6
#define EAST       7
#define WEST       8

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

    void moveToDirection(int direction);

    int getRelativeDirection(const Point &);

    std::vector<Point> getRelativePositions(std::vector<int> & directions) const;

    std::vector<Point> getCorners();

    Point newRelativePoint(const int destination) const;


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

    std::vector<Point> getCorners() const;

    void Point::moveFurtherAwayFrom(const Point & from, int times);

    Point Point::newPointFrom(Point & from, int destination);

//    /*!
//     * \brief Permet de copier le contenu d'un point dans un
//     * autre point.
//     * \return Le point courant modifié.
//     */
//    Point& operator=(const Point& other);

//    /*!
//     * \brief Permet de savoir si deux points n'ont pas les
//     * mêmes coordonnées
//     * \return true si les deux points sont localisés
//     * à des endroits différents
//     */
//    bool operator!=(const Point &) const;

//    /*!
//     * \brief Permet de savoir si deux points ont des coordonnées
//     * identiques
//     * \return true si les points partangent les mêmes coordonées
//     */
bool operator==(const Point &) const;


};

inline int Point::getX() const
{
    return x;
}

inline int Point::getY() const
{
    return y;
}

inline std::vector<Point> Point::getCorners() const
{
    std::vector<int> directions{SOUTH_EAST,SOUTH_WEST
                ,NORTH_EAST,NORTH_WEST};

    std::vector<Point> corners =
            getRelativePositions(directions);


    return corners;
}

#endif // POINT_HPP
