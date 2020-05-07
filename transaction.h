#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>

class transactionData;

class transaction
{
    Q_OBJECT
public:
    transaction();
    transaction(const transaction &);
    transaction &operator=(const transaction &);
    ~transaction();

private:
    QSharedDataPointer<transactionData> data;
};

#endif // TRANSACTION_H
