#include "../include/Item.h"
#include <iostream>
#include <ctime>
#include <cstdio>

Item::Item(std::string itemID, std::string desc, std::string dateFound, std::string location, std::string status) {
    this->itemID = itemID;
    this->desc = desc;
    this->dateFound = dateFound;
    this->location = location;
    this->status = status;
}

void Item::getDetails() {
    std::cout << "ID: " << itemID << " | Desc: " << desc << " | Date: " << dateFound 
              << " | Loc: " << location << " | Status: " << status << "\n";
}

void Item::updateStatus(std::string newStatus) {
    this->status = newStatus;
}

bool Item::isExpired() {
    struct tm foundTime = {0};
    int day, month, year;
    if (sscanf(dateFound.c_str(), "%d-%d-%d", &day, &month, &year) == 3) {
        foundTime.tm_mday = day;
        foundTime.tm_mon = month - 1;
        foundTime.tm_year = year - 1900;
        time_t found_t = mktime(&foundTime);
        time_t now_t = time(0);
        double diff = difftime(now_t, found_t);
        if (diff > 30 * 24 * 60 * 60) {
            return true;
        }
    }
    return false;
}

std::string Item::getItemID() { return itemID; }
std::string Item::getDesc() { return desc; }
std::string Item::getDateFound() { return dateFound; }
std::string Item::getLocation() { return location; }
std::string Item::getStatus() { return status; }
