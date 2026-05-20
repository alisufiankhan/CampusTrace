#ifndef ELECTRONICITEM_H
#define ELECTRONICITEM_H
#include "Item.h"
#include <string>

class ElectronicItem : public Item {
private:
    std::string brand, color, serialNumber;
public:
    ElectronicItem(std::string itemID, std::string desc, std::string dateFound, std::string location, 
                   std::string status, std::string brand, std::string color, std::string serialNumber);
    void getDetails() override;
    std::string getBrand();
    std::string getColor();
    std::string getSerialNumber();
};
#endif
