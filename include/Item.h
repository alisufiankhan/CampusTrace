#ifndef ITEM_H
#define ITEM_H

#include <string>

// Base class for all lost/found items in the system
class Item {
private:
    std::string itemID;
    std::string desc;
    std::string dateFound;
    std::string location;
    std::string status;

public:
    // Constructor to initialize item details
    Item(std::string itemID, std::string desc, std::string dateFound, 
         std::string location, std::string status);

    // Virtual destructor for proper inheritance
    virtual ~Item() {}

    // Returns the details of the item
    virtual std::string getDetails();

    // Updates the status of the item (e.g., Found, Claimed)
    void updateStatus(std::string newStatus);

    // Checks if the item has been in the system past its expiry date
    bool isExpired();

    // Getters
    std::string getItemID();
    std::string getDesc();
    std::string getDateFound();
    std::string getLocation();
    std::string getStatus();
};

#endif
