#include "../include/DocumentItem.h"
#include <iostream>

DocumentItem::DocumentItem(std::string itemID, std::string desc, std::string dateFound, std::string location, 
                           std::string status, std::string docType, std::string issuedBy)
    : Item(itemID, desc, dateFound, location, status) {
    this->docType = docType;
    this->issuedBy = issuedBy;
}

void DocumentItem::getDetails() {
    Item::getDetails();
    std::cout << "DocType: " << docType << " | IssuedBy: " << issuedBy << "\n";
}

std::string DocumentItem::getDocType() { return docType; }
std::string DocumentItem::getIssuedBy() { return issuedBy; }
