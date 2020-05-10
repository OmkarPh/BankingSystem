#ifndef WITHDRAW_H
#define WITHDRAW_H
#include<transaction.h>
#include <QDialog>
#include<QStandardPaths>

namespace Ui {
class withdraw;
}

class withdraw : public QDialog
{
    Q_OBJECT

public:
    explicit withdraw(QWidget *parent = nullptr, transaction *currentCust = nullptr);
    ~withdraw();
    transaction *customer;
private slots:
    void on_pushButton_3_clicked();

    void on_withdrawButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::withdraw *ui;
};

#endif // WITHDRAW_H
