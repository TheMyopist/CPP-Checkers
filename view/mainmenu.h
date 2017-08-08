#ifndef MENU_H
#define MENU_H

#define GAMETITLE "Checkers"

#include <QApplication>
#include <QWidget>
#include <QtWidgets>

class MainMenu : public QFrame
{
    Q_OBJECT

private:
    QPushButton *soloButton;
    QPushButton *multiplayerButton;
    QPushButton * quitButton;
    QLabel * MainMenu::setLogo();

public:
    /*!
         * \brief Permet de créer un menu du jeu.
         */
        explicit MainMenu(QWidget * = 0);
        ~MainMenu();

signals:

    void newMultiplayerGameSelected();
    void newVersusAIGameSelected();

private slots:
    void startMultiplayerGame();
};

#endif // MENU_H
