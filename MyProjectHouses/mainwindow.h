#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QMainWindow>
#include <QTextStream>
#include <fstream>
#include <iostream>

#include "allhouses.h"
#include "mymodel.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

   public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

   private:
    Ui::MainWindow *ui;

    //    AllHouses *_allhouses;
    AllHouses _allhouses;

    QList<House> _houses;

   protected:
    QStandardItemModel *_mainModel;

    MyModel *_myModel;

    QString fileName;
    void createTable();
    void saveFile(const QString &path);

   private slots:
    void on_actionOpen_triggered();
    void on_adressCheckBox_stateChanged(int arg1);
    void on_cityCheckBox_stateChanged(int arg1);
    void on_floorCheckBox_stateChanged(int arg1);
    void on_idCheckBox_stateChanged(int arg1);
    void on_latCheckBox_stateChanged(int arg1);
    void on_longCheckBox_stateChanged(int arg1);
    void on_priceCheckBox_stateChanged(int arg1);
    void on_roomsCheckBox_stateChanged(int arg1);
    void on_sqCheckBox_stateChanged(int arg1);
    void on_yearCheckBox_stateChanged(int arg1);
    void on_actionHelp_triggered();
    void on_addbutton_clicked();
    void on_deleteButton_clicked();
    void on_actionSave_as_triggered();
    void on_actionSave_triggered();
};
#endif  // MAINWINDOW_H
