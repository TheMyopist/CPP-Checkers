#include <iostream>
#include <point.h>
#include <cell.h>
#include <board.h>

int main(int argc, char *argv[])
{
  board testBoard{10,15};
  const unsigned int testGetHeigt = testBoard.getHeight();
  const unsigned int testGetWidth = testBoard.getWidth();
  const Point p{2,5};
  Cell testGetCellAt = testBoard.getCellAt(p);
}
