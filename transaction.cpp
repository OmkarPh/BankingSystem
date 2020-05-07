#include "transaction.h"

class transactionData : public QSharedData
{
public:

};

transaction::transaction() : data(new transactionData)
{

}

transaction::transaction(const transaction &rhs) : data(rhs.data)
{

}

transaction &transaction::operator=(const transaction &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

transaction::~transaction()
{

}
