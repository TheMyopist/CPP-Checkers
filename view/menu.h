#ifndef MENU_H
#define MENU_H

#define GAMETITLE "Checkers"

#include <QApplication>
#include <QWidget>
#include <QtWidgets>

class Menu : public QWidget
{
    Q_OBJECT

private:
    QLabel *title = new QLabel(GAMETITLE,this);
    QPushButton *solo = new QPushButton("Solo", this);
    QPushButton *multiplayer = new QPushButton("Multiplayer", this);

public:
    Menu();
};

#endif // MENU_H
