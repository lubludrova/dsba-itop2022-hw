#ifndef MYLOGO_H
#define MYLOGO_H

#include <QPainter>
#include <QWidget>

class MyLogo : public QWidget
{
    Q_OBJECT
   public:
    MyLogo(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event) override;

   signals:
};

#endif  // MYLOGO_H
