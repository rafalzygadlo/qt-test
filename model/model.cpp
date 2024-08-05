#include "model/model.h"

Model::Model(QObject *parent)
    : QAbstractTableModel(parent)
{




}

int Model::rowCount(const QModelIndex & /*parent*/) const
{
    return 20;
}

int Model::columnCount(const QModelIndex & /*parent*/) const
{
    return 2;
}

QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {

        switch (section) {
        case 0:
            return QString("first");
        case 1:
            return QString("second");
        case 2:
            return QString("third");
        }
    }
    return QVariant();
}


QVariant Model::data(const QModelIndex &index, int role) const
{

    //Qt::displ

    if (role == Qt::DisplayRole)
        return QString("R:%1, C:%2, R:%3")
            .arg(index.row() + 1)
            .arg(index.column() +1)
            .arg(role);

    return QVariant();
}
