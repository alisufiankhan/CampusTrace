#include "../include/Handover.h"
#include <iostream>

Handover::Handover(std::string handoverID, std::string condition, std::string witness,
                   std::string transactionID, std::string date, Person* person)
    : Transaction(transactionID, date, person) {
    this->handoverID = handoverID;
    this->condition = condition;
    this->witness = witness;
}

void Handover::confirmHandover() {
    std::cout << "Handover confirmed. ID: " << handoverID << " | Witness: " << witness << "\n";
}

void Handover::generateReceipt() {
    std::cout << "--- Handover Receipt ---\n"
              << "Handover ID: " << handoverID << "\n"
              << "Condition: " << condition << "\n"
              << "Witness: " << witness << "\n"
              << "Date: " << getDate() << "\n"
              << "Person: " << (getPerson() ? getPerson()->getName() : "None") << "\n"
              << "------------------------\n";
}

void Handover::processTransaction() {
    Transaction::processTransaction();
    std::cout << "Handover ID: " << handoverID << " | Condition: " << condition << " | Witness: " << witness << "\n";
}

std::string Handover::getHandoverID() { return handoverID; }
std::string Handover::getCondition() { return condition; }
std::string Handover::getWitness() { return witness; }
