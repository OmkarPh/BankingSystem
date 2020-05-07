#include "withdraw.h"
#include "ui_withdraw.h"

withdraw::withdraw(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::withdraw)
{
    ui->setupUi(this);
}

withdraw::~withdraw()
{
    delete ui;
}

void withdraw::on_pushButton_3_clicked()
{
    qApp->exit();
}
