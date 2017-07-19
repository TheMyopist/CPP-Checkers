#ifndef CHECKERS_H
#define CHECKERS_H

#include "board.h"
#include "player.h"
#include "man.h"



class Checkers
{
private:

    Board board;
    std::vector<Player> players;
    unsigned turn;
    bool multiplayer; //par défaut on joue contre IA
    Man currentMan; //? ou dans player


public:
    Checkers(bool = false); //par défaut on joue contre l'IA

    Board & getBoard() const; //le get modifie pas le board, mais le board peut être modifié par une autre fonction qui appellele get
    std::vector<Player> & getPlayers() const;
    const unsigned getTurn() const; //get turnt lol
    const bool isMultiplayer() const;

    //tours et fin de la partie
    void nextTurn();
    void isTurnOver(); //ptet pas nécéssaire
    void isGameOver(); //si abandon,si fin impossible, si victoire

    //action des joueurs
    void play(); //move,capture,walkoff,surrender selon input
    void move();
    void capture();
    void walkoff();
    void surrender();


};

#endif // CHECKERS_H
