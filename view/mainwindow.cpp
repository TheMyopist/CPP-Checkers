#include "mainwindow.h"

MainWindow::MainWindow(QWidget * parent) :
    QMainWindow{parent}, boardview{this}
{
    this->setWindowTitle("Checkers");
    this->setCentralWidget(&this->boardview);
}
