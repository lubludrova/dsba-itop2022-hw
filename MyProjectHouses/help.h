#ifndef HELP_H
#define HELP_H

#include <QDialog>
#include <QGridLayout>
#include <QMainWindow>

namespace Ui
{
class Help;
}

class Help : public QDialog
{
    Q_OBJECT

   public:
    Help(QWidget *parent = nullptr);
    ~Help();

   private:
    void setLogo();
    Ui::Help *ui;
};

#endif  // HELP_H
