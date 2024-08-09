#include <QApplication>
#include "view/mainwindow.h"
#include "db.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qDebug() << QSqlDatabase::drivers();

    if (!QSqlDatabase::drivers().contains("QSQLITE"))
        QMessageBox::critical(nullptr, "Unable to load database", "This demo needs the SQLITE driver");

    db m_db;
    // Initialize the database:
    QSqlError err = m_db.init();
    if (err.type() != QSqlError::NoError)
    {
        QMessageBox::critical(nullptr, "Unable to initialize Database", "Error initializing database: " + err.text());
        return 1;
    }


    mainWindow m_window;
    m_window.show();

    return a.exec();
}
