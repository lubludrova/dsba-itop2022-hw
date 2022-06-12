#include "mylogo.h"

#include <cmath>

MyLogo::MyLogo(QWidget *parent) : QWidget{parent} {}

// actually creates the logo
void MyLogo::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing,
                           true);

    QPen customPen;
    customPen.setColor(QColor::fromRgb(200, 200, 100));
    customPen.setWidth(9);
    customPen.setCapStyle(Qt::RoundCap);

    painter.setPen(customPen);

    QPolygon poly;
    poly << QPoint(195 * 2, 195 - 160 / sqrt(2))
         << QPoint(275 * 2, 195 + 80 / sqrt(2))
         << QPoint(115 * 2, 195 + 80 / sqrt(2))
         << QPoint(195 * 2, 195 - 160 / sqrt(2))
         << QPoint(195 * 2, 195 - 80 * sqrt(2))
         << QPoint(155 * 2, 195 - 60 * sqrt(2))
         << QPoint(115 * 2, 195 + 80 / sqrt(2))
         << QPoint(195 * 2, 195 + 160 / sqrt(2))
         << QPoint(275 * 2, 195 + 80 / sqrt(2))
         << QPoint(235 * 2, 195 - 60 * sqrt(2))
         << QPoint(195 * 2, 195 - 80 * sqrt(2))
         << QPoint(235 * 2, 195 - 60 * sqrt(2))
         << QPoint(195 * 2, 195 + 160 / sqrt(2))
         << QPoint(155 * 2, 195 - 60 * sqrt(2))
         << QPoint(195 * 2, 195 - 80 * sqrt(2));
    painter.drawPolygon(poly);
}
