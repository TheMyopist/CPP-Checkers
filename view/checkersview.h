#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include "view/cellview.h"
#include "view/manview.h"
#include "checkers.h"
#include "checkersevent.h"
#include <QGraphicsView>
#include <QGraphicsScene>

class Checkers;
class ManView;
class CellView;

class CheckersView : public QGraphicsView
{
    Q_OBJECT

    Checkers * checkers;

    std::vector<std::vector<CellView*>> grid;
    std::vector<std::vector<ManView*>> men;

    QGraphicsScene * scene;

public:
    CheckersView(QWidget * parent);

    ~CheckersView();

    void update(unsigned);

    void switchPlayer();

    void updatePositions();

    void selectPieceToPlay(Point &);

    void disableAllCells();

    void disableAllMen();

    void highlightMovablepositions(std::vector< std::pair<Point, std::vector<Point>> > &
                                   movablepositions);

    void selectMovePosition(const Point &);

    void displayEndOfGame();

signals:

    /*!
     * \brief Signale que le niveau doit être affiché.
     */
    void displayingStarted();

    /*!
     * \brief Signale que le niveau ne doit plus être affiché.
     */
    void displayingStopped();

public slots:
    /*!
     * \brief démarre une partie humain contre humain
     */
    void startMultiplayerGame();
    /*!
     * \brief démarre une partie humain contre IA
     */
    //TO DO QUAND AI OK
    //void startSoloGame();
};

#endif // BOARDVIEW_H
