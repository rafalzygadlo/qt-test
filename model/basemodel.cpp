#include "basemodel.h"

baseModel::baseModel()
    : QSqlRelationalTableModel()
{
    setTable("books");
}

