#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui
{
class AddWindow;
}

class AddWindow : public QDialog
{
    Q_OBJECT

   public:
    explicit AddWindow(QWidget* parent = nullptr);
    ~AddWindow();
    void setModelPointer(QStandardItemModel* model);

   private slots:
    void on_addButton_clicked();

   private:
    Ui::AddWindow* ui;

    QStandardItemModel* model;
};

#endif  // ADDWINDOW_H
