#include "mainwindow.h"
#include "model/model.h"
#include <QTableView>


mainWindow::mainWindow()
{


    QWidget *window = new QWidget(this);
    QVBoxLayout *vBox = new QVBoxLayout(window);

    //table view
    QTableView *tableView = new QTableView(window);
    tableView->setModel(new Model);

    vBox->addWidget(tableView, Qt::AlignCenter);

    //buttons
    QHBoxLayout *hBox = new QHBoxLayout;
    hBox->addStretch(1);

    QPushButton *b1 = new QPushButton(tr("Ok") );
    hBox->addWidget(b1,0, Qt::AlignRight);

    QPushButton *b2 = new QPushButton(tr("Cancel"));
    hBox->addWidget(b2, 0, Qt::AlignRight);


    //buttons1
    QHBoxLayout *hBox1 = new QHBoxLayout;

    QPushButton *b11 = new QPushButton(tr("Ok1") );
    hBox1->addWidget(b11,0, Qt::AlignRight);


    QPushButton *b12 = new QPushButton(tr("Cancel1"));
    hBox1->addWidget(b12, 0, Qt::AlignRight);
    hBox1->addStretch(1);


    vBox->addLayout(hBox);
    vBox->addLayout(hBox1);


    createMenuBar();


    setCentralWidget(window); // create the central widget for the window

}

QTableView *mainWindow::createTableView()
{
    return nullptr;
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
