#include "cellview.h"

CellView::CellView(Cell & cell, const Point & position,
                   const unsigned x, const unsigned y)
    :QRect(viewUtilities::toQRect(position,x,y)),
     cell{cell}{}
