#ifndef WELCOME_H
#define WELCOME_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Welcome; }
QT_END_NAMESPACE

class Welcome : public QMainWindow
{
    Q_OBJECT

public:
    Welcome(QWidget *parent = nullptr);
    ~Welcome();

private:
    Ui::Welcome *ui;
};
#endif // WELCOME_H
