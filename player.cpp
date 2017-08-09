#include "player.h"

Player::Player(const unsigned color, unsigned numberOfMen, bool isIA) :
    color{color}, numberOfMen{numberOfMen}, isIAPlayer{isIA} {}


void Player::removeMan()
{
    numberOfMen--;
}

const bool Player::getIsIAPlayer() const
{
    return isIAPlayer;
}

void Player::play() {}
