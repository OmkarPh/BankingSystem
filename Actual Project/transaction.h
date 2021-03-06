#ifndef TRANSACTION_H
#define TRANSACTION_H

#include<iostream>
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;


class transaction
{

private:

public:
    transaction(QWidget* parent, int lineNoObtained);
    transaction(const transaction &);
    transaction &operator=(const transaction &);
    ~transaction();

    int lineNo;

    QString userPath;
    QString accPath ;
    QWidget *parent;
    QString accNoString, pinString, name, balanceString;
    int pin, accNo, balance;
    QString accRecord;

    void updateBalance();
    void deposit(int amount);
    bool withdraw(int amount);

    QString getBalance();
    static QString encrypt(QString givenQString, int p1 = 23, int p2 = 37);
};

#endif // TRANSACTION_H
