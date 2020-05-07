#include "deposit.h"
#include "ui_deposit.h"

Deposit::Deposit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Deposit)
{
    ui->setupUi(this);
}

Deposit::~Deposit()
{
    delete ui;
}
