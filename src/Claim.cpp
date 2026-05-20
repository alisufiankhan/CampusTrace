#include "../include/Claim.h"
#include <iostream>

Claim::Claim(std::string claimID, std::string proof, std::string status, Item* item,
             std::string transactionID, std::string date, Person* person)
    : Transaction(transactionID, date, person) {
    this->claimID = claimID;
    this->proof = proof;
    this->status = status;
    this->item = item;
}

void Claim::submitClaim() {
    status = "Pending";
    std::cout << "Claim submitted successfully. Claim ID: " << claimID << "\n";
}

bool Claim::validateClaim() {
    return !proof.empty();
}

void Claim::processTransaction() {
    Transaction::processTransaction();
    std::cout << "Claim ID: " << claimID << " | Proof: " << proof << " | Status: " << status << "\n";
}

void Claim::setDisputed() {
    status = "Disputed";
    std::cout << "Claim " << claimID << " is now Disputed.\n";
}

void Claim::setClaimStatus(std::string newStatus) {
    this->status = newStatus;
}

std::string Claim::getClaimID() { return claimID; }
std::string Claim::getProof() { return proof; }
std::string Claim::getClaimStatus() { return status; }
Item* Claim::getItem() { return item; }
