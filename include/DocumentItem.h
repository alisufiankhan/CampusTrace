#ifndef DOCUMENT_ITEM_H
#define DOCUMENT_ITEM_H

#include "Item.h"
#include <string>

// Specialized class for document items like ID cards or certificates
class DocumentItem : public Item {
private:
    std::string docType;
    std::string issuedBy;

public:
    // Constructor to initialize document item details
    DocumentItem(std::string itemID, std::string desc, std::string dateFound, 
                 std::string location, std::string status, 
                 std::string docType, std::string issuedBy);

    // Returns details specific to document items
    std::string getDetails() override;

    // Getters
    std::string getDocType();
    std::string getIssuedBy();
};

#endif
