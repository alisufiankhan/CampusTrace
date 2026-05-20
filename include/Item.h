#ifndef ITEM_H
#define ITEM_H
#include <string>

class Item {
private:
    std::string itemID, desc, dateFound, location, status;
public:
    Item(std::string itemID, std::string desc, std::string dateFound, std::string location, std::string status);
    virtual ~Item() = default;
    virtual void getDetails();
    void updateStatus(std::string newStatus);
    bool isExpired();
    std::string getItemID();
    std::string getDesc();
    std::string getDateFound();
    std::string getLocation();
    std::string getStatus();
};
#endif
