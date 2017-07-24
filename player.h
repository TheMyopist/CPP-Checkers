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
    Player(const unsigned, unsigned = 20);

    const unsigned getColor() const;
    unsigned getNumberOfMen() const;

    unsigned removeMen(const unsigned);
};

#endif // PLAYER_H
