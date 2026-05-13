#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Person.h"
#include "Item.h"
#include <string>

// Base class for all transactions related to items
class Transaction {
private:
    std::string transactionID;
    std::string date;
    Person* person; // Associated person (Student or Admin)

public:
    // Constructor to initialize transaction details
    Transaction(std::string transactionID, std::string date, Person* person);

    // Virtual destructor
    virtual ~Transaction() {}

    // Processes the specific transaction logic
    virtual void processTransaction();

    // Getters
    std::string getTransactionID();
    std::string getDate();
    Person* getPerson();
};

#endif
