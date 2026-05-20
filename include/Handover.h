#ifndef HANDOVER_H
#define HANDOVER_H
#include "Transaction.h"
#include <string>

class Handover : public Transaction {
private:
    std::string handoverID, condition, witness;
public:
    Handover(std::string handoverID, std::string condition, std::string witness,
             std::string transactionID, std::string date, Person* person);
    void confirmHandover();
    void generateReceipt();
    void processTransaction() override;
    std::string getHandoverID();
    std::string getCondition();
    std::string getWitness();
};
#endif
