#include "checkersview.h"

#include <iostream>

CheckersView::CheckersView(QWidget * parent)
    : QGraphicsView(parent), scene{new QGraphicsScene}, checkers{new Checkers{}},
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
                manView->setClickable(man.getColor() == checkers->getCurrentPlayer().getColor());
                this->scene->addItem(manView);
            }
            else
                men[j][i] = 0;
        }
    }

    this->checkers->addView(this);
}

void CheckersView::update(unsigned checkersEvent)
{
    switch(checkersEvent)
    {
    case MOVE_MADE : updatePositions();
        break;
    case PLAYER_SWITCHED : switchPlayer();
        break;
    }
}

// faire destructeur qui free les cellViews
CheckersView::~CheckersView()
{
    free(this->checkers);
}

void CheckersView::switchPlayer()
{
    for(int i = 0; i < men.size(); i++ )
        for(int j = 0; j < men.at(i).size(); j++)
            if (men[i][j] != 0)
                men[i][j]->setClickable(men[i][j]->getMan().getColor()
                                        == checkers->getCurrentPlayer().getColor());
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
   }
}

void CheckersView::selectPieceToPlay(Point & selectedPiecePos)
{
    this->checkers->setCurrentPiecePosition(selectedPiecePos);
    std::vector< std::pair<Point, std::vector<Point>> > movablePositions
            = checkers->getMovablePositionsFrom(selectedPiecePos);

    if (! movablePositions.empty())
    {
        //this->checkers->setCurrentPiecePosition(selectedPiecePos);
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

void CheckersView::selectMovePosition(Point & dest)
{
    this->disableAllCells();
    this->checkers->makeMove(dest);
}
