#ifndef DB_H
#define DB_H

#include <QtSql>

#define DATABASE_NAME "test.sqlite"

class db
{

public:
    QSqlError init();
    QSqlError alter();
};

#endif // DB_H
