#ifndef BALANCE_H
#define BALANCE_H

#include <QDialog>

namespace Ui {
class balance;
}

class balance : public QDialog
{
    Q_OBJECT

public:
    explicit balance(QWidget *parent = nullptr);
    ~balance();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::balance *ui;
};

#endif // BALANCE_H
