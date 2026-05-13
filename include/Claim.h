#ifndef CLAIM_H
#define CLAIM_H

#include "Transaction.h"
#include "Item.h"
#include <string>

// Represents a claim transaction for a lost item
class Claim : public Transaction {
private:
    std::string claimID;
    std::string proof;
    std::string claimStatus;
    Item* item; // The item being claimed

public:
    // Constructor to initialize claim details
    Claim(std::string transactionID, std::string date, Person* person, 
          std::string claimID, std::string proof, std::string claimStatus, Item* item);

    // Submits the claim to the system
    void submitClaim();

    // Validates the proof provided for the claim
    bool validateClaim();

    // Processes the claim transaction logic
    void processTransaction() override;

    // Sets the status of the claim to disputed if multiple claims exist
    void setDisputed();

    // Getters
    std::string getClaimID();
    std::string getProof();
    std::string getClaimStatus();
    Item* getItem();
};

#endif
