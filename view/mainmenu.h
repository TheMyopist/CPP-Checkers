#ifndef MENU_H
#define MENU_H

#define GAMETITLE "Checkers"

#include <QApplication>
#include <QWidget>
#include <QtWidgets>

class MainMenu : public QWidget
{
    Q_OBJECT

private:
    QLabel *title = new QLabel(GAMETITLE,this);
    QPushButton *solo = new QPushButton("Solo", this);
    QPushButton *multiplayer = new QPushButton("Multiplayer", this);

public:
    MainMenu();
};

#endif // MENU_H
