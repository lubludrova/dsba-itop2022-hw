#include "addwindow.h"

#include "ui_addwindow.h"

AddWindow::AddWindow(QWidget *parent) : QDialog(parent), ui(new Ui::AddWindow)
{
    ui->setupUi(this);
}

AddWindow::~AddWindow() { delete ui; }

void AddWindow::setModelPointer(QStandardItemModel *model)
{
    this->model = model;
}

void AddWindow::on_addButton_clicked()
{
    int row = model->rowCount();

    // Inserting a new row in the table
    model->insertRows(row, 1);

    // adding new data
    QModelIndex index = model->index(row, 0, QModelIndex());
    model->setData(index, ui->adressEdit->text());

    index = model->index(row, 1, QModelIndex());
    model->setData(index, ui->cityEdit->text());

    index = model->index(row, 2, QModelIndex());
    model->setData(index, ui->floorEdit->text());

    index = model->index(row, 3, QModelIndex());
    model->setData(index, ui->idEdit->text());

    index = model->index(row, 4, QModelIndex());
    model->setData(index, ui->latEdit->text());

    index = model->index(row, 5, QModelIndex());
    model->setData(index, ui->longEdit->text());

    index = model->index(row, 6, QModelIndex());
    model->setData(index, ui->priceEdit->text());

    index = model->index(row, 7, QModelIndex());
    model->setData(index, ui->roomsEdit->text());

    index = model->index(row, 8, QModelIndex());
    model->setData(index, ui->squareEdit->text());

    index = model->index(row, 9, QModelIndex());
    model->setData(index, ui->yearEdit->text());

    this->close();
}
