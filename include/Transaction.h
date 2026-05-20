#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "Person.h"
#include <string>

class Transaction {
private:
    std::string transactionID, date;
    Person* person;
public:
    Transaction(std::string transactionID, std::string date, Person* person);
    virtual ~Transaction() = default;
    virtual void processTransaction();
    std::string getTransactionID();
    std::string getDate();
    Person* getPerson();
};
#endif
