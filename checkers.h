#ifndef CHECKERS_H
#define CHECKERS_H

#include "board.h"
#include "player.h"
#include "iaplayer.h"
#include "man.h"



class Checkers
{
private:

    Board board;
    std::vector<Player> players;
    unsigned turn;
    bool gameOver;
    bool multiplayer; //par défaut on joue contre IA


public:
    Checkers(const bool = false); //par défaut on joue contre l'IA, voir si const ici ok

    void initPlayers(const bool);

    Board & getBoard(); //le get modifie pas le board, mais le board peut être modifié par une autre fonction qui appellele get
    std::vector<Player> & getPlayers() const;
    const unsigned getTurn() const; //get turnt lol
    const bool isMultiplayer() const;

    //tours et fin de la partie
    void nextTurn();
    void isTurnOver(); //ptet pas nécéssaire
    void isGameOver(); //si abandon,si fin impossible, si victoire

    //retourne la nouvelle position et les positions éventuelles
    //d'ennemis capturés

   std::vector< std::pair<Point, std::vector<Point>> > Checkers::getMovablePositionsFrom(
           const Point & position,
           const unsigned color);

   void Checkers::addMovablePositions(std::vector< std::pair<Point, std::vector<Point>> > & movablePositions,
           const Point & position,
           Point &corner,
           const unsigned color);

   bool isEnnemyPosition(const Point &, const unsigned);

    //action des joueurs

    void move(const Point &, const Point &); //crown doit se faire auto
    void capture(const Point &, const Point &);
    void walkoff();
    void surrender();

    //conséquence action
    void removeMan(const Point);

};

inline Board & Checkers::getBoard()
{
    return board;
}

#endif // CHECKERS_H
