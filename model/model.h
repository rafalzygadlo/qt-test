#ifndef MODEL_H
#define MODEL_H

// mymodel.h
#include <QAbstractTableModel>

class Model : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
};



#endif // MODEL_H
