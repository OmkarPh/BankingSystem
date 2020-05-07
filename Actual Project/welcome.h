#ifndef WELCOME_H
#define WELCOME_H
#include<transaction.h>
#include <QMainWindow>
#include<string>
#include<fstream>
#include<iostream>
#include<QDialog>
#include<QMessageBox>
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

private slots:
    void on_loginButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::Welcome *ui;
};
#endif // WELCOME_H
