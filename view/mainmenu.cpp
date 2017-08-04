#include "mainmenu.h"

MainMenu::MainMenu() : QWidget()
{ 
    QHBoxLayout *titleLayout = new QHBoxLayout;
    QVBoxLayout *buttonsLayout  = new QVBoxLayout;
    QVBoxLayout *menuLayout = new QVBoxLayout;

    title->setAlignment(Qt::AlignCenter);
    solo->setMaximumWidth(60);
    multiplayer->setMaximumWidth(60);

    titleLayout->addWidget(title);
    buttonsLayout->addWidget(solo);
    buttonsLayout->addWidget(multiplayer);

    titleLayout->setAlignment(Qt::AlignCenter);
    buttonsLayout->setAlignment(Qt::AlignCenter);

    menuLayout->addLayout(titleLayout);
    menuLayout->addLayout(buttonsLayout);

    this->setLayout(menuLayout);
}
