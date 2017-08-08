#include "mainmenu.h"

MainMenu::MainMenu(QWidget *parent) : QFrame(parent),
    soloButton{new QPushButton("Solo", this)},
    multiplayerButton{new QPushButton("Multiplayer", this)},
    quitButton{new QPushButton("Quit", this)}
{ 
   QVBoxLayout * lay{new QVBoxLayout};

   QObject::connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
   QObject::connect(multiplayerButton, SIGNAL(clicked()), this, SLOT(startMultiplayerGame()));
   //QObject::connect(soloButton, SIGNAL(clicked()), qApp, SLOT(quit()));


   lay->addWidget(this->setLogo());
   lay->addWidget(soloButton);
   lay->addWidget(multiplayerButton);
   lay->addWidget(quitButton);

   this->setLayout(lay);
}

MainMenu::~MainMenu(){}

QLabel * MainMenu::setLogo()
{
    QLabel * title = new QLabel("<h1><b>CHECKERS</b></h1>");

    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("font-size: 50px");

    return title;
}

void MainMenu::startMultiplayerGame()
{
    emit newMultiplayerGameSelected();
}
