#ifndef MYMODEL_H
#define MYMODEL_H

#include <allhouses.h>

#include <QAbstractTableModel>
#include <QMainWindow>
#include <QObject>

#include "help.h"

class MyModel : public QAbstractTableModel
{
    Q_OBJECT
   public:
    MyModel(QObject *parent, QList<House> *houses);  /// houses добавить

    void insert_data(const QList<House> &_houses);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    //    bool setData(const QModelIndex& index, const QVariant &value, int role
    //    = Qt::EditRole) override;
    QVariant data(const QModelIndex &index,
                  int role = Qt::DisplayRole) const override;
    //    QVariant headerData(int section, Qt::Orientation orientation, int role
    //    = Qt::DisplayRole ) const override;

   private:
    QList<House> *houses;
};

#endif  // MYMODEL_H
