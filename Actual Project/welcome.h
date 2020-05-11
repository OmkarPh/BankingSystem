#ifndef WELCOME_H
#define WELCOME_H
#include<transaction.h>
#include <QMainWindow>
#include<string>
#include<fstream>
#include<iostream>
#include<QString>
#include<QDialog>
#include<QMessageBox>
#include<options.h>
#include<about.h>
#include<newuser.h>
using namespace  std;
QT_BEGIN_NAMESPACE
namespace Ui { class Welcome; }
QT_END_NAMESPACE

class Welcome : public QMainWindow
{
    Q_OBJECT

public:
    Welcome(QWidget *parent = nullptr);
    ~Welcome();
    QString userPath;
    QString accPath ;
    QString username;
    QString password;
    QString validUsername;
    QString validPassword;
    QString accountNo;
    Options *currentCutomer;
    newUser *custNew3;

    about *abt;
private slots:
    void on_loginButton_clicked();

    void on_pushButton_clicked();

    void on_username_textChanged(const QString &arg1);

    void on_password_textChanged(const QString &arg1);

    bool canEnableLoginButton();
    void on_pushButton_2_clicked(bool hide=true);

    void on_pushButton_5_clicked();

    void on_signUpButton_clicked();

private:
    Ui::Welcome *ui;
};
#endif // WELCOME_H
