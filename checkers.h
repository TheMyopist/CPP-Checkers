#ifndef CHECKERS_H
#define CHECKERS_H

#include "board.h"
#include "player.h"
#include "iaplayer.h"
#include "man.h"
#include "view/checkersview.h"
#include <algorithm>

class CheckersView;
class Player;

class Checkers
{
private:

    Board board;
    std::vector<Player*> players;
    unsigned currentPlayer;
    Man currentPiece;
    Point currentPiecePosition;
    unsigned turn;
    bool gameOver;
    bool multiplayer; //par défaut on joue contre IA
    std::pair<Point, std::vector<Point>> chosenMove;


    std::vector<CheckersView *> views;


public:
    Checkers(const bool = true); //par défaut on joue contre humain voir si const ici ok

    ~Checkers();

    void initPlayers(const bool);
    void switchCurrentPlayer();
    void setCurrentPiecePosition(const Point &);

    std::pair<Point, std::vector<Point>> & getChosenMove();
    Board & getBoard(); //le get modifie pas le board, mais le board peut être modifié par une autre fonction qui appellele get
    std::vector<Player *> getPlayers();
    const unsigned getTurn() const;
    Player *getCurrentPlayer();
    const bool isMultiplayer() const;
    const unsigned getEnnemy() const;

    Point & getCurrentPiecePosition();
    void makeMove(Point dest);
    bool canMakeMove();
    bool isOnCrownLine(const Point &) const;
    bool isInTheRightDirection(const Point & position) const;

    bool isGameOver(); //si abandon,si fin impossible, si victoire


    std::vector< std::pair<Point, std::vector<Point>> > getMovablePositionsFrom(
            const Point &);
    void getMovablePositionsFrom(
            const Point &,
            std::vector< std::pair<Point, std::vector<Point>> > &,
            std::vector<Point>);

    void addMovablePositions(
            std::vector< std::pair<Point, std::vector<Point>> > &,
            const Point &,
            Point &,
            std::vector<Point>);

    std::vector<Point> getCornersFromDestination(Point &, Point &);

    bool isEnnemyPosition(const Point &, const unsigned);

    void surrender();

    //conséquence action
    void addMan(const Point & position, const Man & man);
    void removeMan(const Point);

    /*!
         * \brief Permet d'abonner une nouvelle vue au modèle.
         *
         * \param newView Nouvelle vue abonnée au niveau.
         */
    void addView(CheckersView *);

    /*!
         * \brief Permet de notifier les vues abonnées au Checkers que son état a
         * changé en communiquant la nouvelle position de la position courante
         * ainsi que les éventuelles positions capturées.
         */
    void notifyViews(unsigned);

    std::vector<std::pair<Point, std::vector<Point>>> trimBiggestPaths
    (std::vector<std::pair<Point, std::vector<Point>>> & capturedPositions);
};

inline Board & Checkers::getBoard()
{
    return board;
}

inline Player * Checkers::getCurrentPlayer()
{
    return this->players.at(currentPlayer);
}

inline  std::vector<Player*> Checkers::getPlayers()
{
    return this->players;
}

#endif // CHECKERS_H
