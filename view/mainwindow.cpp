#include "mainwindow.h"
#include "model/model.h"
#include <QTableView>


mainWindow::mainWindow()
{

    QVBoxLayout *vBoxLayout = new QVBoxLayout(this);

    QWidget *window = new QWidget(this);
    window->setLayout(vBoxLayout);


    vBoxLayout->addWidget(createTableView(), Qt::AlignCenter);

    QHBoxLayout *HBoxLayout = new QHBoxLayout(this);
    HBoxLayout->addStretch(1);

    QPushButton *b1 = new QPushButton(tr("Ok"), this);
    HBoxLayout->addWidget(b1,0, Qt::AlignRight);

    QPushButton *b2 = new QPushButton(tr("Cancel"), this);
    HBoxLayout->addWidget(b2, 0, Qt::AlignRight);



    vBoxLayout->addLayout(HBoxLayout);

    createMenuBar();


    setCentralWidget(window); // create the central widget for the window

}





QTableView *mainWindow::createTableView()
{
    QTableView *tableView = new QTableView(this);
    tableView->setModel(new Model);

    return tableView;
}


void mainWindow::createMenuBar()
{
    QAction *quitAction = new QAction(tr("&Quit"), this);
    QAction *aboutAction = new QAction(tr("&About"), this);
    QAction *aboutQtAction = new QAction(tr("&About Qt"), this);

    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(quitAction);

    QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQtAction);

    connect(quitAction, &QAction::triggered, qApp, &QCoreApplication::quit);
    //connect(aboutAction, &QAction::triggered, this, &BookWindow::about);
    connect(aboutQtAction, &QAction::triggered, qApp, &QApplication::aboutQt);
}
