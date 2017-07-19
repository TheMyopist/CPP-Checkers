#ifndef PLAYER_H
#define PLAYER_H

class Player
{

private:

    const unsigned color;
    unsigned numberOfMen;


public:
    Player(const unsigned);

    const unsigned getColor() const;
    unsigned getNumberOfMen() const;

    unsigned removeMen(const unsigned);
};

#endif // PLAYER_H
