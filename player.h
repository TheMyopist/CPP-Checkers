#ifndef PLAYER_H
#define PLAYER_H

/**
 * @brief Cette classe Player définit un joueur pour une partie de
 * jeu de dames.
 */
class Player
{

private:

    /**
    * \brief color La couleur du joueur (noir ou blanc).
    */
    const unsigned color;

    /**
    * \brief numberOfPen le nombre de dames restants au joueur.
    */
    unsigned numberOfMen;


public:
    /**
    * \brief Instancie un joueur de la couleur passée en paramètre
    * et dont le nombre de dames est de 20 par défaut.
    */
    Player(const unsigned, unsigned = 20);

    /**
    * \brief Retourne la couleur du joueur
    * \return Une valeur héxadécimale désignant une couleur.
    */
    const unsigned getColor() const;

    /**
    * \brief Retourne le nombre de dames restants au joueur.
    * \return Une valeur entière nulle ou positive représentant le
    * nombre de joueurs restants au joueur.
    */
    unsigned getNumberOfMen() const;

    /**
    * \brief Supprime une ou plusieurs dames du  joueur.
    */
    void removeMen(const unsigned);
};

inline const unsigned Player::getColor() const
{
    return color;
}

inline unsigned Player::getNumberOfMen() const
{
    return numberOfMen;
}

#endif // PLAYER_H
