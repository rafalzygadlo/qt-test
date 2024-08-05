#include "mainwindow.h"
#include "model/model.h"
#include <QTableView>

mainWindow::mainWindow()
{
    QTableView *tableView = new QTableView;
    tableView->setModel(new Model);

    setCentralWidget(tableView);



}
