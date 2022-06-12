#include "allhouses.h"

#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QVariant>
#include <stdexcept>

AllHouses::AllHouses(QObject *parent) : QObject{parent} {}

// this func opens a file and fills the storage
QList<House> AllHouses::openFile(const QString &fileName)
{
    if (fileName.isEmpty()) throw std::runtime_error("Error");  // checking
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))  // checking
        throw std::runtime_error("Error");

    bool firstline = true;
    QList<House> _houses;

    QTextStream fStream(&file);
    // going through the file
    while (!fStream.atEnd())
    {
        QString line = fStream.readLine();
        if (!line.isNull() && !firstline)
        {
            QStringList paramsOfHouse = line.split(QLatin1Char(','));

            if (paramsOfHouse.size() < 11)
                throw std::runtime_error("Record not valid");

            House currentHotel;
            //            if (!curDish) curDish = new Hotel;
            currentHotel.fill(paramsOfHouse);

            _houses.append(currentHotel);
        }
        else
            firstline = false;
    }

    file.close();
    return _houses;
}

// this function actually fills the data
void House::fill(const QStringList &attrrs)
{
    number = attrrs[0].toDouble();
    address = attrrs[1];
    city = attrrs[2];
    floor = attrrs[3].toDouble();
    id = attrrs[4].toDouble();
    latitude = attrrs[5].toDouble();
    longitude = attrrs[6].toDouble();
    price = attrrs[7].toDouble();
    rooms = attrrs[8].toDouble();
    sq = attrrs[9].toDouble();
    year = attrrs[10].toDouble();
}
