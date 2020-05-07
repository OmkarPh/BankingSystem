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
     string  accNo;

     string pinString;
     int pin;

     string name;

     string  balanceString;
     int currBalance;

     int accLineNo;
     string accRecord;
public:
    transaction(string accNo);
    transaction(const transaction &);
    transaction &operator=(const transaction &);
    ~transaction();


    void updateBalance();
    void deposit(int amount);
    bool withdraw(int amount);

};

#endif // TRANSACTION_H
