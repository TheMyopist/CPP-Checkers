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
        }
    }
}

void CheckersView::updateDisplay(std::pair<Point, std::vector<Point> >
                              & positionsToUpdate, const Point & positionToClear)
{
//    for(CellView & cell : this->grid)


//    for(ManView & man : this->men)
//        if(man.getPosition == positionToClear)
//            man.close();
//            delete man;
}

// faire destructeur qui free les cellViews
CheckersView::~CheckersView()
{
    free(this->checkers);
}
