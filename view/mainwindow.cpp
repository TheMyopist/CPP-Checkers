#include "mainwindow.h"

MainWindow::MainWindow(QWidget * parent) :
    QMainWindow{parent}, boardView{this}
{
    this->setWindowTitle("Checkers");
    this->setCentralWidget(&this->boardView);
}

void MainWindow::displayMainMenu()
{
    this->menuBar()->hide();
    this->boardView.setParent(0);
    this->boardView.hide();
    this->setCentralWidget(this->mainMenu);
    this->mainMenu->show();
    this->adjustSize();
}

void MainWindow::displayBoard()
{
    this->menuBar()->show();
    this->mainMenu->setParent(0);
    this->mainMenu->hide();
    this->setCentralWidget(&this->boardView);
    this->boardView.show();
}

MainWindow::~MainWindow() {}
