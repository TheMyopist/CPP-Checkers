#include "boardview.h"

#include <iostream>



BoardView::BoardView(QWidget * parent)
    : QGraphicsView(parent), scene{new QGraphicsScene}, board{},
      grid{board.getHeight(), std::vector<CellView*>(board.getWidth())},
      men{board.getHeight(), std::vector<ManView*>(board.getWidth())}
{
    this->setRenderHint(QPainter::Antialiasing);
    this->setScene(this->scene);

    for (int i = 0; i < (int) board.getHeight(); i++ )
    {
        for (int j = 0; j < (int) board.getWidth(); j++)
        {
            Point position{j, i};
            CellView* cellView = new CellView{board.getCellAt(position), position};

            grid[j][i] = cellView;
            this->scene->addItem(cellView);

            if (! board.isCellEmpty(position))
            {
                ManView* man = new ManView{board.getCellAt(position).getMan(),
                                            position};

                men[j][i] = man;
                this->scene->addItem(man);
            }
        }
    }
}

// faire destructeur qui free les cellViews
