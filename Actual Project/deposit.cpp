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
    amountStr = ui->amountToDeposit->text();

        customer->deposit(amountStr.toInt());
        QMessageBox::about(this,"Successfully deposited", "Collect receipt for transaction");
        this->close();
        return;



}
