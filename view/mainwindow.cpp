#include "mainwindow.h"

MainWindow::MainWindow(QWidget * parent) :
    QMainWindow{parent}, mainMenu{new MainMenu{this}},
    bar{new QMenuBar{this}}, checkersView{0},
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

    if (checkersView != 0)
    {
        this->checkersView->setParent(0);
        this->checkersView->hide();
    }

    this->setCentralWidget(this->mainMenu);
    this->mainMenu->show();
    this->adjustSize();
}

void MainWindow::displayCheckers(bool multiplayer)
{
    this->menuBar()->show();
    this->mainMenu->setParent(0);
    this->mainMenu->hide();
    this->checkersView = new CheckersView{this, multiplayer};
    this->setCentralWidget(this->checkersView);
    this->checkersView->show();
    this->adjustSize();
}

void MainWindow::displayCheckersMulti()
{
    displayCheckers(true);
}

void MainWindow::displayCheckersAI()
{
    displayCheckers(false);
}

void MainWindow::connectAll()
{

    QObject::connect(this->mainMenu, SIGNAL(newMultiplayerGameSelected()),
                     this, SLOT(displayCheckersMulti()));
    QObject::connect(this->mainMenu, SIGNAL(newVersusAIGameSelected()),
                     this, SLOT(displayCheckersAI()));
}

MainWindow::~MainWindow() {}
