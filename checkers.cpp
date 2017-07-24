#include "checkers.h"

Checkers::Checkers(const bool isMultiplayer) : turn{0}, board{Board()}
{
    initPlayers(isMultiplayer);
}

void Checkers::nextTurn()
{
    turn++;
}

void Checkers::initPlayers(const bool isMultiplayer)
{
    if(isMultiplayer)
        players = {Player{BLACK},Player{WHITE}};
    else players = {Player{BLACK},IAplayer{WHITE}};
}
