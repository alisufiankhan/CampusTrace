#include "../include/ElectronicItem.h"
#include <iostream>

ElectronicItem::ElectronicItem(std::string itemID, std::string desc, std::string dateFound, std::string location, 
                               std::string status, std::string brand, std::string color, std::string serialNumber)
    : Item(itemID, desc, dateFound, location, status) {
    this->brand = brand;
    this->color = color;
    this->serialNumber = serialNumber;
}

void ElectronicItem::getDetails() {
    Item::getDetails();
    std::cout << "Brand: " << brand << " | Color: " << color << " | S/N: " << serialNumber << "\n";
}

std::string ElectronicItem::getBrand() { return brand; }
std::string ElectronicItem::getColor() { return color; }
std::string ElectronicItem::getSerialNumber() { return serialNumber; }
