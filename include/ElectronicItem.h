#ifndef ELECTRONIC_ITEM_H
#define ELECTRONIC_ITEM_H

#include "Item.h"
#include <string>

// Specialized class for electronic items like phones or laptops
class ElectronicItem : public Item {
private:
    std::string brand;
    std::string color;
    std::string serialNumber;

public:
    // Constructor to initialize electronic item details
    ElectronicItem(std::string itemID, std::string desc, std::string dateFound, 
                   std::string location, std::string status, 
                   std::string brand, std::string color, std::string serialNumber);

    // Returns details specific to electronic items
    std::string getDetails() override;

    // Getters
    std::string getBrand();
    std::string getColor();
    std::string getSerialNumber();
};

#endif
