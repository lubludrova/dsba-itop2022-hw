#include "mymodel.h"

MyModel::MyModel(QObject *parent, QList<House> *houses)
    : QAbstractTableModel(parent)
{
    houses = new QList<House>;
}

void MyModel::insert_data(const QList<House> &_houses)
{
    houses->clear();
    houses = new QList<House>;
    return;
}

int MyModel::rowCount(const QModelIndex &parent) const
{
    return houses->size();
}

int MyModel::columnCount(const QModelIndex &parent) const
{
    return 11;  // do not know how to count actually
}

// bool MyModel::setData(const QModelIndex &index, const QVariant &value, int
// role)
//{
//    if (role == Qt::EditRole)
//    {
//        houses[index.row] =  value;
//        return true;
//    }
//    return false;
//}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
    {
        return QVariant();
    }
    if (index.column() == 0) return (*houses)[index.row()].address;
    if (index.column() == 1) return (*houses)[index.row()].city;
    if (index.column() == 2) return (*houses)[index.row()].floor;
    if (index.column() == 3) return (*houses)[index.row()].id;
    if (index.column() == 4) return (*houses)[index.row()].latitude;
    if (index.column() == 5) return (*houses)[index.row()].longitude;
    if (index.column() == 6) return (*houses)[index.row()].price;
    if (index.column() == 7) return (*houses)[index.row()].rooms;
    if (index.column() == 8) return (*houses)[index.row()].sq;
    if (index.column() == 9) return (*houses)[index.row()].year;
    return QVariant();
}

// QVariant MyModel::headerData(int section, Qt::Orientation orientation, int
// role) const
//{

//    if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
//    {
//        gameFeatures field = (gameFeatures) section;
//        return enum_to_string(field);
//    }
//    return {};
//}
