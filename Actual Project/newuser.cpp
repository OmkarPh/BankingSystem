#include "newuser.h"
#include "ui_newuser.h"

newUser::newUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newUser)
{
    ui->setupUi(this);
    //ui->pinWarn->setVisible(false);
    //ui->passWarn->setVisible(false);
}

newUser::~newUser()
{
    delete ui;
}

void newUser::on_signUpButton_clicked()
{
    QString emptyField = "";
       if(ui->username->text()==""){
           emptyField = "username";
       }else if(ui->password->text()==""){
           emptyField = "password";
       }else if(ui->confirmPassword->text()==""){
           emptyField = "confirm password";
       }else if(ui->pin->text()==""){
           emptyField = "pin";
       }else if(ui->confirmPin->text()==""){
           emptyField = "confirm pin";
       }

       if(emptyField != ""){
               QMessageBox::warning(this,"Empty field",emptyField + " is empty");
           }

           if(ui->pin->text().length() < 4){
               QMessageBox::warning(this,"Fields do not meet criteria","Pin must be of 4 digits");
           }

           if(ui->password->text() != ui->confirmPassword->text()){
               QMessageBox::about(this,"Passwords don't match","Please enter the same passwords in both fields");
               return;
           }
           if(ui->pin->text() != ui->pin->text()){
               QMessageBox::about(this,"Pins don't match","Please enter the same pins in both fields");
               return;
           }
           this->username = ui->username->text();
           this->password = ui->password->text();
           this->pin = ui->pin->text();
           this->personName = ui->actualName->text();
           QFile userPassFile("userNameNPass.csv");

              // Exception code
                  if (!userPassFile.open(QIODevice::ReadOnly | QIODevice::Text)){
                      QMessageBox::warning(this,"Exception","file could not be opened for signup");
                      return;
                  }
              // Exception code

                  QVector<QString> eachLine;
                 QTextStream in(&userPassFile);
                 while (!in.atEnd())
                 {
                    eachLine.push_back(in.readLine());    //read one line at a time
                 }
                 QString lastLine= eachLine[eachLine.length()-1];
                 QString accStringOld, accStringNew;
                  long accOld, accNew;

                  QString newLine;

                  QStringList words = lastLine.split(',');
                  accStringOld = words.at(2);

                  accOld = accStringOld.toLong();
                  accNew = ++accOld;

                  accStringNew = QString::number(accNew);

                  newLine = this->username + "," + this->password + "," + accStringNew + "\n";


                  userPassFile.close();
                  userPassFile.remove();

                  QFile nfile("userNameNPass.csv");
               if(nfile.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
                          // QMessageBox::about(parent,"Succesful","Opened new try");
                         QTextStream out(&nfile);
                         for(int i=0; i<eachLine.length(); i++){
                             out << eachLine[i] << "\n";
                         }
                         out<<newLine;
                         nfile.close();
                 }
                 else{
                         QMessageBox::warning(this,"Exception","file could not be opened for signup file creation");
                         return;
                  }

               QFile accountFile("accountsDatabase.csv");
               if(accountFile.open(QIODevice::ReadOnly | QIODevice::Text)){
                  QTextStream out1(&accountFile);
                   lastLine = out1.readAll();
                   accountFile.close();
                   accountFile.remove();
               }
               else{
                    QMessageBox::warning(this,"Exception","file could not be opened for new account record");
                    return;
               }

               // sentence to add to accounts.csv
                accStringNew = accStringNew + "," + this->pin+ "," +this->personName + ",0\n";
               //QMessageBox::information(this,"New Line:",accStringNew);
               QFile accountWrite("accountsDatabase.csv");
               if(accountWrite.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
                          // QMessageBox::about(parent,"Succesful","Opened new try");
                         QTextStream out2(&accountWrite);
                         out2<<lastLine;
                         out2<<accStringNew;
                         accountWrite.close();
                 }
                 else{
                         QMessageBox::warning(this,"Exception","file could not be opened for signup file creation");
                         return;
                  }

               QMessageBox::information(this,"Your new account created.","Your new account no. is :  "+QString::number(accNew)+"\nCurrent Balance: ₹0\nLogin with credentials and start using the service soon :)");
                this->close();
               return;
}


void newUser::on_password_textChanged(const QString &arg1)
{
        on_confirmPin_textChanged(ui->password->text());
}

void newUser::on_confirmPassword_textChanged(const QString &arg1)
{
    if(ui->password->text() != ui->confirmPassword->text()){
            ui->passWarn->setVisible(true);
    }
    else{
        ui->passWarn->setVisible(false);
    }

}

void newUser::on_pin_textChanged(const QString &arg1)
{
    on_confirmPin_textChanged(ui->pin->text());
}

void newUser::on_confirmPin_textChanged(const QString &arg1)
{
    if(ui->pin->text() != ui->confirmPin->text()){
        ui->pinWarn->setVisible(true);
    }
    else{
        ui->pinWarn->setVisible(false);
    }
}



// Useless

void newUser::on_confirmPin_editingFinished(){
    return;
}

