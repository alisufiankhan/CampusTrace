#include "../include/PersonalItem.h"
#include <iostream>

PersonalItem::PersonalItem(std::string itemID, std::string desc, std::string dateFound, std::string location, 
                           std::string status, std::string color, std::string size, std::string material)
    : Item(itemID, desc, dateFound, location, status) {
    this->color = color;
    this->size = size;
    this->material = material;
}

void PersonalItem::getDetails() {
    Item::getDetails();
    std::cout << "Color: " << color << " | Size: " << size << " | Material: " << material << "\n";
}

std::string PersonalItem::getColor() { return color; }
std::string PersonalItem::getSize() { return size; }
std::string PersonalItem::getMaterial() { return material; }
