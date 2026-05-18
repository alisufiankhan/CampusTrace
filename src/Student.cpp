#include "../include/Student.h"
#include "../include/Claim.h"
#include "../include/Item.h"
#include <iostream>
#include <vector>

extern std::vector<Claim*> globalClaims;
extern std::vector<Item*> globalItems;

Student::Student(std::string name, std::string ID, std::string contact, 
                 std::string password, std::string rollNumber, std::string dept)
    : Person(name, ID, contact, password) {
    this->rollNumber = rollNumber;
    this->dept = dept;
    this->rejections = 0;
    this->isFlagged = false;
}

void Student::claimItem() {
    if (isFlagged) {
        std::cout << "You are flagged and cannot claim items.\n";
        return;
    }

    std::string itemID, proof;
    std::cout << "Enter Item ID to claim: ";
    std::cin >> itemID;
    std::cout << "Enter Proof of ownership: ";
    std::cin >> proof;

    Item* targetItem = nullptr;
    for (Item* item : globalItems) {
        if (item->getItemID() == itemID) {
            targetItem = item;
            break;
        }
    }

    if (targetItem == nullptr) {
        std::cout << "Item not found.\n";
        return;
    }

    std::string txID = "TXN" + std::to_string(globalClaims.size() + 1);
    std::string claimID = "CLM" + std::to_string(globalClaims.size() + 1);
    std::string date = "2026-05-18"; 

    Claim* newClaim = new Claim(txID, date, this, claimID, proof, "Pending", targetItem);
    globalClaims.push_back(newClaim);
    targetItem->updateStatus("UnderReview");
    std::cout << "Claim submitted successfully.\n";
}

void Student::viewStatus() {
    bool found = false;
    std::cout << "--- My Claims ---\n";
    for (Claim* claim : globalClaims) {
        if (claim->getPerson() == this) {
            std::cout << "Claim ID: " << claim->getClaimID() 
                      << ", Status: " << claim->getClaimStatus() 
                      << ", Item: " << claim->getItem()->getDesc() << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "No claims found.\n";
    }
}

void Student::incrementRejections() {
    rejections++;
    if (rejections >= 3) {
        isFlagged = true;
        std::cout << "Warning: You have been flagged due to 3 rejected claims.\n";
    }
}

std::string Student::getRollNumber() {
    return rollNumber;
}

std::string Student::getDept() {
    return dept;
}

int Student::getRejections() {
    return rejections;
}

bool Student::getIsFlagged() {
    return isFlagged;
}
