#include "withdraw.h"
#include "ui_withdraw.h"
#include<QMessageBox>
withdraw::withdraw(QWidget *parent, transaction *currentCust) :
    QDialog(parent),
    ui(new Ui::withdraw)
{
    ui->setupUi(this);
    ui->warning->setVisible(false);
    customer = currentCust;
}

withdraw::~withdraw()
{
    delete ui;
}

void withdraw::on_pushButton_3_clicked()
{
    qApp->exit();
}

void withdraw::on_withdrawButton_clicked()
{
    int amount = ui->amountToWithdraw->value();
    QString pinStr = ui->pinEntered->text();

    if(pinStr == customer->pinString){
        if(customer->withdraw(amount))
                QMessageBox::about(this,"Withdrawal successful", "Please collect the cash.");
        ui->warning->setVisible(false);
        this->close();
        return;
    }
    if(ui->warning->isVisible()){
        QMessageBox::about(this,"Invalid Pin","Try re-entering the pin !");
        return;
    }
    ui->warning->setVisible(true);

}

void withdraw::on_pushButton_2_clicked()
{
    this->close();
}
