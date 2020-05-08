#include "welcome.h"
#include "ui_welcome.h"
#include<QResource>
#include <QTemporaryDir>
#include<QTextStream>
/*
 username and passwords:

omkar@2003,1436@omkar,11772201
karan@2003,karan@123,11772202
aniruddha16203,galaxy@M20,11834592
rupesh@raut,rupesh2003,11773503
darade@rohan,rohan@web,11773505


account details:

11772201,1436,OmkarGajananPhansopkar,4500
11772202,1234,KaranSudhakarKotian,5800
11834592,2020,AniruddhaShriwant,15500
11773503,9876,RupeshSandeshRaut,5400
11773505,4567,RohanDarade,9000


*/
Welcome::Welcome(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Welcome)
{
    userPath = ":/database/DB/userNameNPass.csv";
    accPath = ":/database/DB/accountsDatabase.csv";
    ui->setupUi(this);
}

Welcome::~Welcome()
{
    delete ui;
}


bool doesExist(string fileName){
    ifstream infile(fileName);
    if(infile.good()){
        infile.close();
        return true;
    }
    return false;
}

void Welcome::on_loginButton_clicked()
{
    username = ui->username->text();
    password = ui->password->text();

    bool foundUser = false;

    // Exception code
        QFile file(userPath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            QMessageBox::warning(this,"Exception","file could not be opened");
            return;
        }
    // Exception code

       QTextStream in(&file);
       while (!in.atEnd())
       {
          QString eachLine = in.readLine(); //read one line at a time
          QStringList words = eachLine.split(',');
          validUsername = words.at(0);
          validPassword = words.at(1);
          accountNo = words.at(2);
          //QMessageBox::about(this," user ",validUsername);
         // QMessageBox::about(this," pass ",validPassword);
         // QMessageBox::about(this," acc ",accountNo);
          if(validUsername==username){
              foundUser = true;
              break;
          }
       }
       file.close();

       if(foundUser){
           if(validPassword == password){
                   // Change window to options.ui, hide this login window
               QMessageBox::about(this,"Successful Login","Correct username and password :)");
           }else{
               // Password is wrong, so create a dialog saying pass is wrong, Clear the lineEdit field for password
               QMessageBox::critical(this,"Invalid Password","The password you entered \ndoes not validate with the username entered\n Try again and keep track of Case");
               ui->password->setText("");
               return;
           }

       }else{
           // Show invalid username, it is not registered in a dialog
           QMessageBox::critical(this,"Invalid Username","The username you entered is not in our System\n Either it is incorrect or not registered with us yet");
           QMessageBox::StandardButton newSignUp =  QMessageBox::question(this,"Invalid Username","Would you like to sign up for a new account?",QMessageBox::Yes | QMessageBox::No);
           if(newSignUp == QMessageBox::Yes)
               QMessageBox::about(this,"Sign Up","Redirecting to signup page");
       }

       ui->username->setText("");
       ui->password->setText("");

       return;
}





void Welcome::on_pushButton_clicked()
{
    qApp->exit();
}

bool Welcome::canEnableLoginButton(){
        username = ui->username->text();
        password = ui->password->text();
        if(username.length()<4 || username=="    " || password.length()<4 || password=="    ")
            return false;
        return true;
}

void Welcome::on_username_textChanged(const QString &arg1)
{
            ui->loginButton->setEnabled(canEnableLoginButton());
}

void Welcome::on_password_textChanged(const QString &arg1)
{
            ui->loginButton->setEnabled(canEnableLoginButton());
}

void Welcome::on_pushButton_2_clicked()
{
    if(ui->pushButton_2->text()=="Show"){
        ui->pushButton_2->setText("Hide");
        ui->password->setEchoMode(QLineEdit::Normal);
    }
    else{
        ui->pushButton_2->setText("Show");
        ui->password->setEchoMode(QLineEdit::Password);
    }

}
