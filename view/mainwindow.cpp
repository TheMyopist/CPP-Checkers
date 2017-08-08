#include "mainwindow.h"

MainWindow::MainWindow(QWidget * parent) :
    QMainWindow{parent}, mainMenu{new MainMenu{this}},
    bar{new QMenuBar{this}}, checkersView{new CheckersView{this}},
    menu{new QMenu}
{
    this->setWindowTitle("Checkers");

    this->connectAll();
    this->setMenuBar();

    this->setCentralWidget(new QWidget);
    this->displayMainMenu();
}

void MainWindow::setMenuBar()
{
    this->menu->addAction(tr("Retour au &menu principal"), this, SLOT(displayMainMenu()), QKeySequence("CTRL+M"));
    this->menu->addAction(tr("&Quitter le jeu"), qApp, SLOT(quit()), QKeySequence("CTRL+Q"));

    this->bar->addMenu(this->menu);

    this->setMenuWidget(this->bar);
}

void MainWindow::displayMainMenu()
{
    this->menuBar()->hide();
    this->checkersView->setParent(0);
    this->checkersView->hide();
    this->setCentralWidget(this->mainMenu);
    this->mainMenu->show();
    this->adjustSize();
}

void MainWindow::displayCheckers()
{
    this->menuBar()->show();
    this->mainMenu->setParent(0);
    this->mainMenu->hide();
    this->setCentralWidget(this->checkersView);
    this->checkersView->show();
    this->adjustSize();
}

void MainWindow::connectAll()
{
    QObject::connect(this->mainMenu, SIGNAL(newMultiplayerGameSelected()),
                     this, SLOT(displayCheckers()));
    QObject::connect(this->checkersView, SIGNAL(displayingStarted()), this, SLOT(displayCheckers()));
    QObject::connect(this->checkersView, SIGNAL(displayingStopped()), this, SLOT(displayMainMenu()));
}


MainWindow::~MainWindow() {}
