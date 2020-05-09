#ifndef OPTIONS_H
#define OPTIONS_H
#include<transaction.h>
#include<fstream>
#include <QDialog>
#include<QFile>
#include<iostream>
using namespace std;
namespace Ui {
class Options;
}

class Options : public QDialog
{
    Q_OBJECT

public:
    explicit Options(QWidget *parent = nullptr, int lineNoObtained = 0);
    ~Options();
    int lineNo;

    QString userPath;
    QString accPath ;

    QString accNoString, pinString, name, balanceString;
    int pin, accNo, balance;

    transaction *currentCust;
private slots:
    void on_pushButton_8_clicked();

    void on_logout_clicked();

private:
    Ui::Options *ui;
};

#endif // OPTIONS_H
