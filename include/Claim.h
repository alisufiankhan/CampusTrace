#ifndef CLAIM_H
#define CLAIM_H
#include "Transaction.h"
#include "Item.h"
#include <string>

class Claim : public Transaction {
private:
    std::string claimID, proof, status;
    Item* item;
public:
    Claim(std::string claimID, std::string proof, std::string status, Item* item,
          std::string transactionID, std::string date, Person* person);
    void submitClaim();
    bool validateClaim();
    void processTransaction() override;
    void setDisputed();
    void setClaimStatus(std::string newStatus);
    std::string getClaimID();
    std::string getProof();
    std::string getClaimStatus();
    Item* getItem();
};
#endif
