#include "db.h"

const char *SQL[] =
    {
        "create table books(id integer primary key, title varchar, author integer,genre integer, year integer, rating integer)",
        "create table users(id integer primary key, name varchar)"
};

QSqlError db::init()
{
    bool exists = QFile::exists(DATABASE_NAME);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DATABASE_NAME);
    db.open();

    if(!exists)
        return alter();


    return db.lastError();

}

QSqlError db::alter()
{
    QSqlQuery q;
    int len = sizeof(SQL)/sizeof(SQL[0]);
    for (int i = 0; i < len; i++)
    {
        if (!q.exec(SQL[i]))
            return q.lastError();
    }

    return q.lastError();
}
