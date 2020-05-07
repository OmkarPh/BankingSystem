#ifndef UTILITY_H
#define UTILITY_H

#include<iostream>
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;
class utilityData;

class utility
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
    Q_OBJECT
public:
    utility(string accNo);
    utility(const utility &);
    utility &operator=(const utility &);
    void updateBalance();
    void deposit(int amount);
    bool withdraw(int amount);
    ~utility();

private:
    QSharedDataPointer<utilityData> data;
};

#endif // UTILITY_H
