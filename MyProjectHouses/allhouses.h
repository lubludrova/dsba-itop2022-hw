#ifndef ALLHOUSES_H
#define ALLHOUSES_H

#include <QMainWindow>
#include <QObject>
#include <QStandardItemModel>

struct House
{
    double number;  // no float only double
    QString address;
    QString city;
    double floor;
    double id;
    double latitude;
    double longitude;
    double price;
    double rooms;
    double sq;
    double year;

    void fill(const QStringList& attrrs);
};

class AllHouses : public QObject
{
    Q_OBJECT
   public:
    explicit AllHouses(QObject* parent = nullptr);

    QList<House> openFile(const QString& fileName);

   signals:
};

#endif  // ALLHOUSES_H
