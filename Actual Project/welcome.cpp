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

11772201,1436,OmkarGajananPhansopkar,4500\n11772202,1234,KaranSudhakarKotian,5800\n11834592,2020,AniruddhaShriwant,15500\n11773503,9876,RupeshSandeshRaut,5400\n11773505,4567,RohanDarade,9000\n

*/
Welcome::Welcome(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Welcome)
{
    //userPath = ":/database/DB/userNameNPass.csv";
    //accPath = ":/database/DB/accountsDatabase.csv";
    userPath = "userNameNPass.csv";
    accPath = "accountsDatabase.csv";
    QString textUser = "omkar@2003,1436@omkar,11772201\nkaran@2003,karan@123,11772202\naniruddha16203,galaxy@M20,11834592\nrupesh@raut,rupesh2003,11773503\ndarade@rohan,rohan@web,11773505\n";
    QString textAcc = "11772201,1436,OmkarGajananPhansopkar,4500\n11772202,1234,KaranSudhakarKotian,5800\n11834592,2020,AniruddhaShriwant,15500\n11773503,9876,RupeshSandeshRaut,5400\n11773505,4567,RohanDarade,9000\n";
    QFile temp1(userPath);
    QFile temp2(accPath);

    if (!temp1.exists() || !temp2.exists()){

        if(temp1.open(QIODevice::WriteOnly | QIODevice::Truncate))
        {
            // QMessageBox::about(parent,"Succesful","Opened new try");
            QTextStream out(&temp1);
            out << textUser;
            temp1.close();
        }
        if(temp2.open(QIODevice::WriteOnly | QIODevice::Truncate))
        {
            // QMessageBox::about(parent,"Succesful","Opened new try");
            QTextStream out(&temp2);
            out << textAcc;
            temp2.close();
        }
    }
    this->setWindowTitle("Welcome to XYZ bank");
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
    int lineNo = 0;
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
          lineNo++;
          QString eachLine = in.readLine(); //read one line at a time
          QStringList words = eachLine.split(',');
          validUsername = words.at(0);
          validPassword = words.at(1);
          accountNo = words.at(2);
          //    QMessageBox::about(this," user ",validUsername);
       //       QMessageBox::about(this," pass ",validPassword);
    //          QMessageBox::about(this," acc ",accountNo);

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
                currentCutomer = new Options(this,lineNo);
                currentCutomer->setModal(true);
                currentCutomer->show();
                //this->hide();
                currentCutomer->exec();
                this->show();
           }else{
               //  This block is complete
               QMessageBox::critical(this,"Invalid Password","The password you entered \ndoes not validate with the username entered\n Try again and keep track of Case");
               ui->password->setText("");
               return;
           }

       }else{
           QMessageBox::critical(this,"Invalid Username","The username you entered is not in our System\n Either it is incorrect or not registered with us yet");
           QMessageBox::StandardButton newSignUp =  QMessageBox::question(this,"Invalid Username","Would you like to sign up for a new account?",QMessageBox::Yes | QMessageBox::No);
           if(newSignUp == QMessageBox::Yes){
               QMessageBox::about(this,"Sign Up","Redirecting to signup page");
               on_signUpButton_clicked();
               // Signup block is incomplete
           }
       }

       ui->username->setText("");
       ui->password->setText("");

       ui->pushButton_2->setText("Show");
       ui->password->setEchoMode(QLineEdit::Password);

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

void Welcome::on_pushButton_2_clicked(bool hide)
{
    if(ui->pushButton_2->text()=="Show"){
        ui->pushButton_2->setText("Hide");
        ui->password->setEchoMode(QLineEdit::Normal);
    }
    else{
        ui->pushButton_2->setText("Show");
        ui->password->setEchoMode(QLineEdit::Password);
    }
    /*
    if(!hide){
        ui->pushButton_2->setText("Show");
        ui->password->setEchoMode(QLineEdit::Password);
    }
    */
}

void Welcome::on_pushButton_5_clicked()
{
        abt = new about(this);
        abt->show();
        abt->exec();
}


void Welcome::on_signUpButton_clicked()
{
    custNew3 = new newUser(this);
    custNew3->setModal(true);
    custNew3->show();
    custNew3->exec();
}
