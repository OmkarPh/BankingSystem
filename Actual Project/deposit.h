#ifndef DEPOSIT_H
#define DEPOSIT_H
#include<transaction.h>
#include <QDialog>

namespace Ui {
class Deposit;
}

class Deposit : public QDialog
{
    Q_OBJECT

public:
    explicit Deposit(QWidget *parent = nullptr, transaction *currentCust = nullptr);
    ~Deposit();
    transaction *customer;
private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Deposit *ui;
};

#endif // DEPOSIT_H
