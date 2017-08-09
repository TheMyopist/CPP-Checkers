#include "checkersview.h"

#include <QMessageBox>
#include <QPushButton>
#include <QMainWindow>
#include <iostream>

CheckersView::CheckersView(QWidget * parent, bool multiplayer)
    : QGraphicsView(parent), scene{new QGraphicsScene}, checkers{new Checkers{multiplayer}},
      grid{checkers->getBoard().getHeight(), std::vector<CellView*>(checkers->getBoard().getWidth())},
      men{checkers->getBoard().getHeight(), std::vector<ManView*>(checkers->getBoard().getWidth())}
{
    this->setRenderHint(QPainter::Antialiasing);
    this->setScene(this->scene);

    for (int i = 0; i < (int) checkers->getBoard().getHeight(); i++ )
    {
        for (int j = 0; j < (int) checkers->getBoard().getWidth(); j++)
        {
            Point position{j, i};
            CellView* cellView = new CellView{checkers->getBoard().getCellAt(position), position, this};

            grid[j][i] = cellView;
            this->scene->addItem(cellView);

            if (! checkers->getBoard().isCellEmpty(position))
            {
                Man man = checkers->getBoard().getCellAt(position).getMan();
                ManView* manView = new ManView{man, position, this};

                men[j][i] = manView;


                manView->setClickable( !checkers->getCurrentPlayer()->getIsIAPlayer() &&
                                       (man.getColor() == checkers->getCurrentPlayer()->getColor()));

                this->scene->addItem(manView);
            }
            else
                men[j][i] = 0;
        }
    }
    this->checkers->addView(this);

    if (checkers->getCurrentPlayer()->getIsIAPlayer())
        this->checkers->getCurrentPlayer()->play();
}

void CheckersView::update(unsigned checkersEvent)
{
    switch(checkersEvent)
    {
    //    case GAME_STARTED : displayFirstPlayer(); TO DO
    //         break;
    case MOVE_MADE : updatePositions();
        break;
    case PLAYER_SWITCHED : switchPlayer();
        break;
    case END_OF_GAME : displayEndOfGame();
        break;
    }
}

CheckersView::~CheckersView()
{
    free(this->checkers);
}

void CheckersView::switchPlayer()
{
    if (!checkers->getCurrentPlayer()->getIsIAPlayer())
    {
        for(int i = 0; i < men.size(); i++ )
            for(int j = 0; j < men.at(i).size(); j++)
                if (men[i][j] != 0)
                    men[i][j]->setClickable(men[i][j]->getMan().getColor()
                                            == checkers->getCurrentPlayer()->getColor());
    }
    else this->checkers->getCurrentPlayer()->play();
    this->disableAllCells();
}

void CheckersView::updatePositions()
{
    Point manToMoveViewPos  = checkers->getCurrentPiecePosition();
    ManView * manToMoveView = men[manToMoveViewPos.getX()][manToMoveViewPos.getY()];
    Point manToMoveDest = checkers->getChosenMove().first;
    ManView * newMan = new ManView{manToMoveView->getMan(), manToMoveDest, this};

    this->scene->removeItem(manToMoveView);
    delete manToMoveView;

    men[manToMoveViewPos.getX()][manToMoveViewPos.getY()] = 0;
    men[manToMoveDest.getX()][manToMoveDest.getY()] = newMan ;

    this->scene->addItem(newMan);

    for (auto & positionToClear : this->checkers->getChosenMove().second)
    {
        ManView * manToDl = men[positionToClear.getX()][positionToClear.getY()];

        this->scene->removeItem(manToDl);
        delete manToDl;

        men[positionToClear.getX()][positionToClear.getY()] = 0;
    }
}

void CheckersView::selectPieceToPlay(Point & selectedPiecePos)
{
    this->checkers->setCurrentPiecePosition(selectedPiecePos);
    std::vector< std::pair<Point, std::vector<Point>> > movablePositions
            = checkers->getMovablePositionsFrom(selectedPiecePos);

    if (! movablePositions.empty())
    {
        this->highlightMovablepositions(movablePositions);
        this->disableAllMen();
    }
}

void CheckersView::highlightMovablepositions(std::vector< std::pair<Point, std::vector<Point>> > &
                                             movablepositions)
{
    for (auto & movableposition : movablepositions)
    {
        this->grid[movableposition.first.getX()][movableposition.first.getY()]->highlight();
        this->grid[movableposition.first.getX()][movableposition.first.getY()]->setClickable(true);
    }
}

void CheckersView::disableAllMen()
{
    for(int i = 0; i < men.size(); i++ )
        for(int j = 0; j < men.at(i).size(); j++)
            if (men[i][j] != 0)
                men[i][j]->setClickable(false);
}

void CheckersView::disableAllCells()
{
    for(int i = 0; i < men.size(); i++ )
        for(int j = 0; j < men.at(i).size(); j++)
        {
            grid[i][j]->setClickable(false);
            grid[i][j]->setNormalColor();
        }
}

void CheckersView::selectMovePosition(const Point & destination)
{
    this->disableAllCells();
    this->checkers->makeMove(destination);
}

void CheckersView::displayEndOfGame()
{
    QMessageBox msgBox(this);
    QPushButton *backToMenu = msgBox.addButton(tr("Retour au menu principal"),
                                               QMessageBox::YesRole);
    msgBox.setText(tr("<strong>Fin de partie!<strong>"));
    msgBox.setWindowFlags(msgBox.windowFlags() ^ Qt::WindowCloseButtonHint);
    msgBox.exec();

    if(((QPushButton*) msgBox.clickedButton()) == backToMenu)
        emit displayingStopped();
}
