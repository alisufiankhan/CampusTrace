#include "../include/Admin.h"
#include "../include/Item.h"
#include "../include/ElectronicItem.h"
#include "../include/DocumentItem.h"
#include "../include/PersonalItem.h"
#include "../include/Claim.h"
#include "../include/Student.h"
#include "../include/Handover.h"
#include <iostream>
#include <ctime>

Admin::Admin(std::string name, std::string ID, std::string contact, std::string password,
             std::string adminID, std::string shift)
    : Person(name, ID, contact, password) {
    this->adminID = adminID;
    this->shift = shift;
}

void Admin::addItem(std::vector<Item*>& items) {
    int category;
    std::cout << "Choose category:\n1. Electronic\n2. Document\n3. Personal\nChoice: ";
    std::cin >> category;

    std::string itemID, desc, dateFound, location;
    std::cout << "Enter Item ID: "; std::cin >> itemID;
    std::cout << "Enter Description: "; std::cin >> desc;
    std::cout << "Enter Date Found (DD-MM-YYYY): "; std::cin >> dateFound;
    std::cout << "Enter Location: "; std::cin >> location;
    std::string status = "Found";

    if (category == 1) {
        std::string brand, color, serialNumber;
        std::cout << "Enter Brand: "; std::cin >> brand;
        std::cout << "Enter Color: "; std::cin >> color;
        std::cout << "Enter Serial Number: "; std::cin >> serialNumber;
        items.push_back(new ElectronicItem(itemID, desc, dateFound, location, status, brand, color, serialNumber));
        std::cout << "Electronic item added successfully.\n";
    } else if (category == 2) {
        std::string docType, issuedBy;
        std::cout << "Enter Doc Type: "; std::cin >> docType;
        std::cout << "Enter Issued By: "; std::cin >> issuedBy;
        items.push_back(new DocumentItem(itemID, desc, dateFound, location, status, docType, issuedBy));
        std::cout << "Document item added successfully.\n";
    } else if (category == 3) {
        std::string color, size, material;
        std::cout << "Enter Color: "; std::cin >> color;
        std::cout << "Enter Size: "; std::cin >> size;
        std::cout << "Enter Material: "; std::cin >> material;
        items.push_back(new PersonalItem(itemID, desc, dateFound, location, status, color, size, material));
        std::cout << "Personal item added successfully.\n";
    } else {
        std::cout << "Invalid category.\n";
    }
}

void Admin::approveClaim(Claim* claim) {
    claim->setClaimStatus("Approved");
    claim->getItem()->updateStatus("Claimed");
    std::cout << "Claim approved.\n";
}

void Admin::rejectClaim(Claim* claim, Student* student) {
    claim->setClaimStatus("Rejected");
    student->incrementRejections();
    std::cout << "Claim rejected.\n";
}

void Admin::processHandover(Claim* claim, std::string witness) {
    std::string hID = "H" + std::to_string(time(0));
    std::string tID = "TXN" + std::to_string(time(0));
    Handover* handover = new Handover(hID, "Good", witness, tID, "CurrentDate", claim->getPerson());
    claim->getItem()->updateStatus("Returned");
    handover->generateReceipt();
    std::cout << "Handover processed successfully.\n";
    delete handover; // clean up or add to a global list if required
}

std::string Admin::getAdminID() { return adminID; }
std::string Admin::getShift() { return shift; }
