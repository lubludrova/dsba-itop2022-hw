#include "mainwindow.h"

#include <QStandardItemModel>

#include "./ui_mainwindow.h"
#include "addwindow.h"
#include "help.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _mainModel = new QStandardItemModel(this);
    //    ui->mainTableview->setModel(_mainModel);
    //    myModel = new MyModel(this, _houses);
}

MainWindow::~MainWindow() { delete ui; }

// opens a file
void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(
        this, tr("Open Data Storage File"), "",
        tr("Text Files (*.csv);;Comma SeparatedValues (*.csv);;AllFiles"
           "(*.*)"));

    //    QString fileName = "E:/se/MyProjectHouses/data/Houses.csv";

    if (fileName.isNull()) return;

    _houses = _allhouses.openFile(fileName);

    createTable();
}

void MainWindow::createTable()
{
    delete _mainModel;
    _mainModel = new QStandardItemModel(_houses.size(), 10, this);
    bool adresscheck;
    _mainModel->setHeaderData(0, Qt::Horizontal, "address");
    _mainModel->setHeaderData(1, Qt::Horizontal, "city");
    _mainModel->setHeaderData(2, Qt::Horizontal, "floor");
    _mainModel->setHeaderData(3, Qt::Horizontal, "ID");
    _mainModel->setHeaderData(4, Qt::Horizontal, "latitude");
    _mainModel->setHeaderData(5, Qt::Horizontal, "longitude");
    _mainModel->setHeaderData(6, Qt::Horizontal, "price");
    _mainModel->setHeaderData(7, Qt::Horizontal, "rooms");
    _mainModel->setHeaderData(8, Qt::Horizontal, "sq");
    _mainModel->setHeaderData(9, Qt::Horizontal, "year");
    ui->mainTableview->setSelectionBehavior(QAbstractItemView::SelectRows);

    QModelIndex index;

    int row;
    row = 0;

    for (auto item : _houses)
    {
        _mainModel->setData(_mainModel->index(row, 0), item.address);
        _mainModel->setData(_mainModel->index(row, 1), item.city);
        _mainModel->setData(_mainModel->index(row, 2), item.floor);
        _mainModel->setData(_mainModel->index(row, 3), item.id);
        _mainModel->setData(_mainModel->index(row, 4), item.latitude);
        _mainModel->setData(_mainModel->index(row, 5), item.longitude);
        _mainModel->setData(_mainModel->index(row, 6), item.price);
        _mainModel->setData(_mainModel->index(row, 7), item.rooms);
        _mainModel->setData(_mainModel->index(row, 8), item.sq);
        _mainModel->setData(_mainModel->index(row, 9), item.year);
        row++;
    }
    ui->mainTableview->setModel(_mainModel);
}

// saving the file
void MainWindow::saveFile(const QString &path)
{
    QFile file(path);

    if (!file.open(QIODevice::WriteOnly))
        throw std::runtime_error("Cannot write to the file");

    //    std::ofstream out(path.toStdString().c_str());
    QTextStream out(&file);

    std::vector<QString> headings = {"Adress",   "City",      "Floor", "ID",
                                     "Latituse", "Longitude", "Price", "Rooms",
                                     "Square",   "Year"};

    for (int ind = 0; ind < headings.size() - 1; ind++)
        out << headings[ind] << ',';
    out << headings[headings.size() - 1] << '\n';

    for (auto &i : _houses)
    {
        out << i.address << ',';
        out << i.city << ',';
        out << i.floor << ',';
        out << i.id << ',';
        out << i.latitude << ',';
        out << i.longitude << ',';
        out << i.price << ',';
        out << i.rooms << ',';
        out << i.sq << ',';
        out << i.year << ',';
        out << '\n';
    }
}
// 2 var

// check wether the CheckBoxes are trigerred and hise the information about smth
void MainWindow::on_adressCheckBox_stateChanged(int arg1)
{
    if (!(arg1 == Qt::Checked))
        ui->mainTableview->setColumnHidden(0, true);
    else
        ui->mainTableview->setColumnHidden(0, false);
}

void MainWindow::on_cityCheckBox_stateChanged(int arg1)
{
    if (!(arg1 == Qt::Checked))
        ui->mainTableview->setColumnHidden(1, true);
    else
        ui->mainTableview->setColumnHidden(1, false);
}

void MainWindow::on_floorCheckBox_stateChanged(int arg1)
{
    if (!(arg1 == Qt::Checked))
        ui->mainTableview->setColumnHidden(2, true);
    else
        ui->mainTableview->setColumnHidden(2, false);
}

void MainWindow::on_idCheckBox_stateChanged(int arg1)
{
    if (!(arg1 == Qt::Checked))
        ui->mainTableview->setColumnHidden(3, true);
    else
        ui->mainTableview->setColumnHidden(3, false);
}

void MainWindow::on_latCheckBox_stateChanged(int arg1)
{
    if (!(arg1 == Qt::Checked))
        ui->mainTableview->setColumnHidden(4, true);
    else
        ui->mainTableview->setColumnHidden(4, false);
}

void MainWindow::on_longCheckBox_stateChanged(int arg1)
{
    if (!(arg1 == Qt::Checked))
        ui->mainTableview->setColumnHidden(5, true);
    else
        ui->mainTableview->setColumnHidden(5, false);
}

void MainWindow::on_priceCheckBox_stateChanged(int arg1)
{
    if (!(arg1 == Qt::Checked))
        ui->mainTableview->setColumnHidden(6, true);
    else
        ui->mainTableview->setColumnHidden(6, false);
}

void MainWindow::on_roomsCheckBox_stateChanged(int arg1)
{
    if (!(arg1 == Qt::Checked))
        ui->mainTableview->setColumnHidden(7, true);
    else
        ui->mainTableview->setColumnHidden(7, false);
}

void MainWindow::on_sqCheckBox_stateChanged(int arg1)
{
    if (!(arg1 == Qt::Checked))
        ui->mainTableview->setColumnHidden(8, true);
    else
        ui->mainTableview->setColumnHidden(8, false);
}

void MainWindow::on_yearCheckBox_stateChanged(int arg1)
{
    if (!(arg1 == Qt::Checked))
        ui->mainTableview->setColumnHidden(9, true);
    else
        ui->mainTableview->setColumnHidden(9, false);
}

// opens the Help window
void MainWindow::on_actionHelp_triggered()
{
    Help window;
    window.setModal(true);
    window.exec();
}

// opens the Add Window
void MainWindow::on_addbutton_clicked()
{
    AddWindow addWindow;

    addWindow.setModelPointer(_mainModel);

    addWindow.setModal(true);
    addWindow.exec();
}

void MainWindow::on_deleteButton_clicked()
{
    // Get the number of the row selected by the user
    int selectedRow = ui->mainTableview->currentIndex().row();

    _mainModel->removeRow(selectedRow);
    _houses.removeAt(selectedRow);
}

// Save as
void MainWindow::on_actionSave_as_triggered()
{
    auto path = QFileDialog::getSaveFileName(
        nullptr, tr("Save file"), "",
        tr("Comma separate values (*.csv);;All Files "
           "(*.*)"));
    saveFile(path);
}

// Save
void MainWindow::on_actionSave_triggered()
{
    if (fileName.size()) saveFile(fileName);
}
