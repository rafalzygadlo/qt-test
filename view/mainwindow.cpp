#include "mainwindow.h"
#include "model/basemodel.h"
#include <QTableView>

mainWindow::mainWindow()
{


    QWidget *window = new QWidget(this);
    QVBoxLayout *vBox = new QVBoxLayout(window);


    //top buttons
    QHBoxLayout *hTop = new QHBoxLayout;
    QPushButton *bNew = new QPushButton(tr("New") );
    hTop->addWidget(bNew,0, Qt::AlignLeft);


    //table view
    QTableView *tableView = new QTableView(window);
    tableView->setModel(new baseModel);


    //buttons
    QHBoxLayout *hBox = new QHBoxLayout;
    hBox->addStretch(1);

    QPushButton *b1 = new QPushButton(tr("Ok") );
    hBox->addWidget(b1,0, Qt::AlignRight);

    QPushButton *b2 = new QPushButton(tr("Cancel"));
    hBox->addWidget(b2, 0, Qt::AlignRight);


    //buttons1

    vBox->addLayout(hTop);
    vBox->addWidget(tableView, Qt::AlignCenter);
    vBox->addLayout(hBox);


    createMenuBar();


    setCentralWidget(window); // create the central widget for the window

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
