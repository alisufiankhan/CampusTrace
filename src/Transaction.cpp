#include "../include/Transaction.h"
#include <iostream>

Transaction::Transaction(std::string transactionID, std::string date, Person* person) {
    this->transactionID = transactionID;
    this->date = date;
    this->person = person;
}

void Transaction::processTransaction() {
    std::cout << "Txn ID: " << transactionID << " | Date: " << date 
              << " | Person: " << (person ? person->getName() : "None") << "\n";
}

std::string Transaction::getTransactionID() { return transactionID; }
std::string Transaction::getDate() { return date; }
Person* Transaction::getPerson() { return person; }
