#include "model/basemodel.h"

baseModel::baseModel()
    : QSqlRelationalTableModel()
{
    setTable("books");
}

