#ifndef DOCUMENTITEM_H
#define DOCUMENTITEM_H
#include "Item.h"
#include <string>

class DocumentItem : public Item {
private:
    std::string docType, issuedBy;
public:
    DocumentItem(std::string itemID, std::string desc, std::string dateFound, std::string location, 
                 std::string status, std::string docType, std::string issuedBy);
    void getDetails() override;
    std::string getDocType();
    std::string getIssuedBy();
};
#endif
