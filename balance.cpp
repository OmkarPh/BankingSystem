#include "balance.h"
#include "ui_balance.h"

balance::balance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::balance)
{
    ui->setupUi(this);
}

balance::~balance()
{
    delete ui;
}
