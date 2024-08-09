#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>

class mainWindow : public QMainWindow
{
    Q_OBJECT

public:
    mainWindow();
    int initdb();

private:
    void createMenuBar();
    QTableView *createTableView();

};

#endif // MAINWINDOW_H
