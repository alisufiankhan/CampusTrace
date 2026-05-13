#ifndef HANDOVER_H
#define HANDOVER_H

#include "Transaction.h"
#include "Item.h"
#include <string>

// Represents a handover transaction when an item is returned to its owner
class Handover : public Transaction {
private:
    std::string handoverID;
    std::string condition;
    std::string witness;

public:
    // Constructor to initialize handover details
    Handover(std::string transactionID, std::string date, Person* person, 
             std::string handoverID, std::string condition, std::string witness);

    // Confirms that the item has been handed over
    void confirmHandover();

    // Generates a receipt for the handover transaction
    void generateReceipt();

    // Processes the handover transaction logic
    void processTransaction() override;

    // Getters
    std::string getHandoverID();
    std::string getCondition();
    std::string getWitness();
};

#endif
