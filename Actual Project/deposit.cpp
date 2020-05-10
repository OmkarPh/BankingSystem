#include "deposit.h"
#include "ui_deposit.h"
#include<QMessageBox>
Deposit::Deposit(QWidget *parent, transaction *currentCust) :
    QDialog(parent),
    ui(new Ui::Deposit)
{
    ui->setupUi(this);
    customer = currentCust;
}

Deposit::~Deposit()
{
    delete ui;
}

void Deposit::on_pushButton_3_clicked()
{

    qApp->exit();
}

void Deposit::on_pushButton_clicked()
{
        int amountStr = ui->amountToDeposit->value();

        customer->deposit(amountStr);
        QMessageBox::about(this,"Successfully deposited", "Collect receipt for transaction");
        this->close();
        return;



}

void Deposit::on_pushButton_2_clicked()
{
    this->close();
}
