#ifndef CELL_H
#define CELL_H

#include "color.h"
#include "man.h"

/**
 * @brief Cette classe Cell définit une case d'un plateau deu jeu de
 * Dames standard.
 * Elle définit la couleur ainsi que l'état de cette case (libre ou
 * occupée).
 */
class Cell{

private:

    /**
    * \brief color, la couleur de la case, représentée par l'une
    * des constantes hexadécimales définies. dans ce header.
    */
    unsigned color;

    /**
    * \brief empty, le statut de la case. True exprime une case libre
    * et false une case occupée.
    */
    bool empty;

    Man man;


public:

    /**
    * \brief Instancie une case selon la couleur et l'état spécifiés
    * en paramètres.
    */
    Cell(const unsigned color);

    /**
    * \brief Instancie une case par copie d'une autre case.
    */
    Cell (const Cell & cell);

    /**
    * \brief Retourne la couleur de la case
    * \return La valeur hexadécimale convertie en valeur décimale
    * de la couleur de la case
    */
    unsigned getColor() const;

    Man & getMan();

    /**
    * \brief Nettoie la case en remettant son attribut empty à true
    */
    void clear();

    /**
    * \brief Détermine si la case est libre ou occupée.
    * \return true si la case est libre, false si elle est occupée.
    */
    bool isEmpty() const;

    /**
    * \brief Change la couleur de la case.
    * \param Une des constantes représentant une couleur
    * définie dans ce header
    */
    void colorize(const unsigned);

    /**
    * \brief Défini l'état d'une cellule comme étant occupée.
    */
    void addMan(const unsigned);



};

inline unsigned Cell::getColor() const
{
    return color;
}

inline Man & Cell::getMan()
{
    return man;
}

inline bool Cell::isEmpty() const
{
    return empty;
}

#endif // CELL_H
