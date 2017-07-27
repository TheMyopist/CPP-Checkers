#ifndef MAN_H
#define MAN_H

#include "color.h"
#include "point.h"

/**
 * @brief Cette classe Man définit une dame (Man en anglais) pour le
 * jeu de dames (Checkers). La dame est l'élement central d'une partie
 * du jeu de dames. Elle possède une couleur (noire ou blanche dans
 * une partie classique) et peut devenir une reine (King en anglais),
 * ce qui lui confère des capacités supplémentaires.
 */
class Man
{

private:

    /**
    * \brief color La couleur (valeur héxadécimale) de la dame.
    * Classiquement, elle sera noire ou blanche.
    */
    unsigned color;

    /**
    * \brief isKing, booléen déterminant si la dame a été promue reine
    * durant la partie. Si false, simple dame. Si true, reine.
    */
    bool isKing;

public:

    /**
    * \brief Constructeur d'une dame, instanciant celle-ci avec la
    * couleur noire par défaut.
    */
    Man(const unsigned = BLACK);

    Man(const Man &);

    /**
    * \brief Retourne la couleur de la dame
    * \return La valeur hexadécimale convertie en valeur décimale
    * de la couleur de la dame.
    */
    const unsigned getColor() const;

    /**
    * \brief Retourne le statut de la dame (dame ou reine).
    * \return True si la dame a été promue reine (crowned), false
    * dans le cas contraire.
    */
    bool getIsKing() const;

    /**
    * \brief Promu une dame au statut de reine.
    */
    void crown();
};

inline const unsigned Man::getColor() const
{
    return color;
}


inline bool Man::getIsKing() const
{
    return isKing;
}

#endif // MAN_H
