#ifndef PERSONALITEM_H
#define PERSONALITEM_H
#include "Item.h"
#include <string>

class PersonalItem : public Item {
private:
    std::string color, size, material;
public:
    PersonalItem(std::string itemID, std::string desc, std::string dateFound, std::string location, 
                 std::string status, std::string color, std::string size, std::string material);
    void getDetails() override;
    std::string getColor();
    std::string getSize();
    std::string getMaterial();
};
#endif
