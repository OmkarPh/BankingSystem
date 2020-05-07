#include "welcome.h"
#include "ui_welcome.h"

Welcome::Welcome(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Welcome)
{
    ui->setupUi(this);
}

Welcome::~Welcome()
{
    delete ui;
}


void Welcome::on_loginButton_clicked()
{
        // Find account No. for entered username and password
        fstream userReader;
        userReader.open("userNameNPass.csv",ios::in);

        string username = (ui->username->text() ).toStdString();
        string password = (ui->password->text()).toStdString();

        string validUsername, validPassword;
        string line;
        string accountNo;
        bool flag = false;
        while(!userReader.eof()){
            getline(userReader,line);
            stringstream ss(line);

            getline(ss,validUsername,',');
            getline(ss,validPassword,',');
            getline(ss,accountNo,',');

            if(validUsername==username){
                flag = true;
                break;
            }
          }

        if(flag){
            if(validPassword == password){
                    // Change window to options.ui, hide this login window
                QMessageBox::about(this,"Successful Login","Correct username and password :)");
            }else{
                // Password is wrong, so create a dialog saying pass is wrong, Clear the lineEdit field for password
                QMessageBox::critical(this,"Invalid Password","The password you entered \ndoes not validate with the username entered");
                ui->password->setText("");
                return;
            }

       }else{
            // Show invalid username, it is not registered in a dialog
            QMessageBox::critical(this,"Invalid Username","The username you entered is not in our System\n Either it is not correct or not registered with us");
            QMessageBox::StandardButton newSignUp =  QMessageBox::question(this,"Invalid Username","Would you like to sign up for a new account?",QMessageBox::Yes | QMessageBox::No);
            if(newSignUp == QMessageBox::Yes)
                QMessageBox::about(this,"Sign Up","Redirecting to signup page");
        }
       ui->username->setText("");
       ui->password->setText("");
        userReader.close();
}

void Welcome::on_pushButton_clicked()
{
    qApp->exit();
}
