#include "options.h"
#include "ui_options.h"
#include<QMessageBox>
#include<QTextStream>
Options::Options(QWidget *parent, int lineNoObtained) :
    QDialog(parent),
    ui(new Ui::Options)
{
    ui->setupUi(this);
    this->lineNo = lineNoObtained;

    userPath = ":/database/DB/userNameNPass.csv";
    accPath = ":/database/DB/accountsDatabase.csv";

   currentCust = new transaction(this, this->lineNo);

    // Exception code
        QFile file(accPath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            QMessageBox::warning(this,"Exception","file could not be opened");
            return;
        }
    // Exception code

       QTextStream in(&file);
       while (lineNoObtained>0)
       {
          lineNoObtained--;
          QString eachLine = in.readLine(); //read one line at a time
          QStringList words = eachLine.split(',');
          accNoString = words.at(0);
          pinString = words.at(1);
          name = words.at(2);
          balanceString = words.at(3);
       }
       accNo = accNoString.toInt();
       pin = accNoString.toInt();
       balance = balanceString.toInt();
       ui->welcomeName->setText(name);
       file.close();
}

Options::~Options()
{
    delete ui;
}

void Options::on_pushButton_8_clicked()
{

    qApp->exit();
}

void Options::on_logout_clicked()
{
    this->close();
}
