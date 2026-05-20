#include "../include/Student.h"
#include "../include/Claim.h"
#include <iostream>
#include <vector>

extern std::vector<Claim*> allClaims;

Student::Student(std::string name, std::string ID, std::string contact, std::string password,
                 std::string rollNumber, std::string dept) 
    : Person(name, ID, contact, password) {
    this->rollNumber = rollNumber;
    this->dept = dept;
    this->rejections = 0;
    this->isFlagged = false;
}

void Student::claimItem(std::string itemID) {
    std::cout << "Creating claim for item: " << itemID << "\n";
}

void Student::viewStatus() {
    bool found = false;
    for (Claim* claim : allClaims) {
        if (claim->getPerson() == this) {
            std::cout << "Claim ID: " << claim->getClaimID() 
                      << " | Status: " << claim->getClaimStatus() << "\n";
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
        std::cout << "Warning: You have been flagged due to multiple rejected claims.\n";
    }
}

std::string Student::getRollNumber() { return rollNumber; }
std::string Student::getDept() { return dept; }
int Student::getRejections() { return rejections; }
bool Student::getIsFlagged() { return isFlagged; }
