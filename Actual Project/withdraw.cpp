#include "withdraw.h"
#include "ui_withdraw.h"
#include<QMessageBox>
withdraw::withdraw(QWidget *parent, transaction *currentCust) :
    QDialog(parent),
    ui(new Ui::withdraw)
{
    ui->setupUi(this);
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
    QString amountStr = ui->amountToWithdraw->text();
    QString pinStr = ui->pinEntered->text();

    if(pinStr == customer->pinString){
        customer->withdraw(amountStr.toInt());
        ui->warning->setVisible(false);
        QMessageBox::about(this,"Withdrawal successful", "Please collect the cash.");
        this->close();
        return;
    }
    ui->warning->setVisible(true);

}
