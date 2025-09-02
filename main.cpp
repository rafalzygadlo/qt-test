#include <QApplication>
#include "view/main/mainView.h"
#include "../view/login/loginView.h"
#include "db.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setStyle("windows");

    //qDebug() << QSqlDatabase::drivers();

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

    loginView m_loginView;

    if (m_loginView.exec() == QDialog::Accepted) 
    {
        mainView m_window;
        m_window.show();
        return a.exec();
    }

    return 1;
}
