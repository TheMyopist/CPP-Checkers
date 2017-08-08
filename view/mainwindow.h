#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>

#include "checkersview.h"
#include "mainmenu.h"

class MainWindow : public QMainWindow
{

    Q_OBJECT

private:
    /*!
         * \brief Le menu de sélection de niveau du jeu.
         */
    MainMenu * mainMenu;


    /*!
         * \brief La bar de menu du jeu.
         */
    QMenuBar * bar;

    /*!
         * \brief Le menu principal du jeu.
         */
    QMenu * menu;

    /*!
         * \brief Configure la bar de menu.
         */
    void setMenuBar();

    /*!
         * \brief Créer toutes les connections SLOT / SIGNAL.
         */
    void connectAll();

    CheckersView  * checkersView;

public:
    MainWindow(QWidget *parent = 0);

    ~MainWindow();

public slots:

    /*!
     * \brief Permet d'afficher le menu principal du jeu.
     */
    void displayMainMenu();

    /*!
     * \brief Permet d'afficher le niveau.
     */
    void displayCheckers();
};

#endif // MAINWINDOW_H
