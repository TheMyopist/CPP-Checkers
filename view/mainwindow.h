#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>

#include "boardview.h"

class MainWindow : public QMainWindow
{

    Q_OBJECT

    private:
        BoardView boardview;

    public:
        MainWindow(QWidget *parent = 0);
};

#endif // MAINWINDOW_H
