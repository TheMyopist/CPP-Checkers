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
   std::pair<Cell, std::vector<Cell>> getPlayablePositions(Point & position
                                                       , const Man & man);


   std::vector<Point> getEnnemiesCorners(const Point &, const unsigned);
   std::vector<Point> getAttackablePositions(const Point &, const unsigned);
   std::vector<Point> getMovableCorners(const Point &);


    //action des joueurs
    std::pair<Point, std::vector<Point>> playablePositions(const Point &,
              const Man &); //move,capture,walkoff,surrender selon input
    std::pair<Point,Point> move(const Point & position, const Man & man); //crown doit se faire auto
    void capture();
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
