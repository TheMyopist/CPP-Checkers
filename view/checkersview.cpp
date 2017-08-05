#include "checkersview.h"

#include <iostream>

CheckersView::CheckersView(QWidget * parent)
    : QGraphicsView(parent), scene{new QGraphicsScene}, checkers{},
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
            CellView* cellView = new CellView{checkers->getBoard().getCellAt(position), position};

            grid[j][i] = cellView;
            this->scene->addItem(cellView);

            if (! checkers->getBoard().isCellEmpty(position))
            {
                ManView* man = new ManView{checkers->getBoard().getCellAt(position).getMan(),
                        position};

                men[j][i] = man;
                this->scene->addItem(man);
            }
            else
                men[j][i] = 0;
        }
    }
}

void CheckersView::update(unsigned checkersEvent)
{
    switch(checkersEvent)
    {
    case MOVE_MADE :
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
                                        == checkers->getPlayers()
                                        .at(checkers->getCurrentPlayer()).getColor());
}
