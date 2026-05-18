#include "../include/Admin.h"
#include "../include/Student.h"
#include "../include/Item.h"
#include "../include/ElectronicItem.h"
#include "../include/DocumentItem.h"
#include "../include/PersonalItem.h"
#include "../include/Claim.h"
#include "../include/Handover.h"
#include <iostream>
#include <vector>

extern std::vector<Item*> globalItems;
extern std::vector<Claim*> globalClaims;

Admin::Admin(std::string name, std::string ID, std::string contact, 
             std::string password, std::string adminID, std::string shift)
    : Person(name, ID, contact, password) {
    this->adminID = adminID;
    this->shift = shift;
}

void Admin::addItem() {
    std::string category;
    std::cout << "Enter Category (Electronic, Document, Personal): ";
    std::cin >> category;

    std::string desc, dateFound, location;
    std::cout << "Enter Description: ";
    std::cin >> desc;
    std::cout << "Enter Date Found: ";
    std::cin >> dateFound;
    std::cout << "Enter Location: ";
    std::cin >> location;

    std::string itemID = "ITM" + std::to_string(globalItems.size() + 1);
    std::string status = "Found";

    if (category == "Electronic") {
        std::string brand, color, serialNumber;
        std::cout << "Enter Brand: "; std::cin >> brand;
        std::cout << "Enter Color: "; std::cin >> color;
        std::cout << "Enter Serial Number: "; std::cin >> serialNumber;
        globalItems.push_back(new ElectronicItem(itemID, desc, dateFound, location, status, brand, color, serialNumber));
        std::cout << "Electronic item added.\n";
    } else if (category == "Document") {
        std::string docType, issuedBy;
        std::cout << "Enter Document Type: "; std::cin >> docType;
        std::cout << "Enter Issued By: "; std::cin >> issuedBy;
        globalItems.push_back(new DocumentItem(itemID, desc, dateFound, location, status, docType, issuedBy));
        std::cout << "Document item added.\n";
    } else if (category == "Personal") {
        std::string color, size, material;
        std::cout << "Enter Color: "; std::cin >> color;
        std::cout << "Enter Size: "; std::cin >> size;
        std::cout << "Enter Material: "; std::cin >> material;
        globalItems.push_back(new PersonalItem(itemID, desc, dateFound, location, status, color, size, material));
        std::cout << "Personal item added.\n";
    } else {
        std::cout << "Invalid category!\n";
    }
}

void Admin::approveClaim() {
    std::string claimID;
    std::cout << "Enter Claim ID to approve: ";
    std::cin >> claimID;

    for (Claim* claim : globalClaims) {
        if (claim->getClaimID() == claimID) {
            // Note: Assuming setClaimStatus will be added by Umama
            claim->setClaimStatus("Approved");
            std::cout << "Claim approved.\n";
            return;
        }
    }
    std::cout << "Claim not found.\n";
}

void Admin::rejectClaim() {
    std::string claimID;
    std::cout << "Enter Claim ID to reject: ";
    std::cin >> claimID;

    for (Claim* claim : globalClaims) {
        if (claim->getClaimID() == claimID) {
            // Note: Assuming setClaimStatus will be added by Umama
            claim->setClaimStatus("Rejected");
            
            Student* student = dynamic_cast<Student*>(claim->getPerson());
            if (student) {
                student->incrementRejections();
            }
            std::cout << "Claim rejected.\n";
            return;
        }
    }
    std::cout << "Claim not found.\n";
}

void Admin::processHandover() {
    std::string claimID;
    std::cout << "Enter Claim ID for handover: ";
    std::cin >> claimID;

    Claim* targetClaim = nullptr;
    for (Claim* claim : globalClaims) {
        if (claim->getClaimID() == claimID) {
            targetClaim = claim;
            break;
        }
    }

    if (!targetClaim) {
        std::cout << "Claim not found.\n";
        return;
    }

    std::string condition, witness;
    std::cout << "Enter item condition: ";
    std::cin >> condition;
    std::cout << "Enter witness name: ";
    std::cin >> witness;

    std::string handoverID = "HO_" + targetClaim->getClaimID();
    
    Handover* newHandover = new Handover("TXN_HO", "2026-05-18", targetClaim->getPerson(),
                                         handoverID, condition, witness);
    
    targetClaim->getItem()->updateStatus("Returned");
    newHandover->generateReceipt();
    
    std::cout << "Handover processed successfully.\n";
}

std::string Admin::getAdminID() {
    return adminID;
}

std::string Admin::getShift() {
    return shift;
}
