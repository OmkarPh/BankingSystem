#ifndef NEWUSER_H
#define NEWUSER_H
#include<QMessageBox>
#include <QDialog>
#include<QTextStream>
#include<QFile>

namespace Ui {
class newUser;
}

class newUser : public QDialog
{
    Q_OBJECT

public:
    explicit newUser(QWidget *parent = nullptr);
    ~newUser();

private slots:
    void on_confirmPassword_textChanged(const QString &arg1);

    void on_confirmPin_editingFinished();

    void on_confirmPin_textChanged(const QString &arg1);

    void on_signUpButton_clicked();

    void on_password_textChanged(const QString &arg1);

    void on_pin_textChanged(const QString &arg1);

private:
    QString personName;
    QString username, password, pin;
    Ui::newUser *ui;
};

#endif // NEWUSER_H
