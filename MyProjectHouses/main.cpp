#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(
        QIcon("E:/se/MyProjectHouses/data/mainicon.png"));  // you should add
                                                            // your path
    MainWindow w;
    w.show();
    return a.exec();
}
