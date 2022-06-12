#include "help.h"

#include "mylogo.h"
#include "ui_help.h"

Help::Help(QWidget *parent) : QDialog(parent), ui(new Ui::Help)
{
    ui->setupUi(this);
    setLogo();
}

Help::~Help() { delete ui; }

void Help::setLogo()
{
    MyLogo *myLogo = new MyLogo(this);
    ui->verticalLayout->addWidget(myLogo);
}
