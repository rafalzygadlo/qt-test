#pragma once

#include <QtWidgets>

class mainView : public QMainWindow
{
    Q_OBJECT

public:
    mainView();
    
private:
    void createMenuBar();
    QTableView *createTableView();

};

