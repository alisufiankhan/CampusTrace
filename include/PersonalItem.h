#ifndef PERSONAL_ITEM_H
#define PERSONAL_ITEM_H

#include "Item.h"
#include <string>

// Specialized class for personal items like bags or clothing
class PersonalItem : public Item {
private:
    std::string color;
    std::string size;
    std::string material;

public:
    // Constructor to initialize personal item details
    PersonalItem(std::string itemID, std::string desc, std::string dateFound, 
                 std::string location, std::string status, 
                 std::string color, std::string size, std::string material);

    // Returns details specific to personal items
    std::string getDetails() override;

    // Getters
    std::string getColor();
    std::string getSize();
    std::string getMaterial();
};

#endif
