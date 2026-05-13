#ifndef ADMIN_H
#define ADMIN_H

#include "Person.h"
#include <string>

// Represents an administrator responsible for managing items and claims
class Admin : public Person {
private:
    std::string adminID;
    std::string shift;

public:
    // Constructor to initialize admin details
    Admin(std::string name, std::string ID, std::string contact, 
          std::string password, std::string adminID, std::string shift);

    // Adds a new found item to the system
    void addItem();

    // Approves a claim submitted by a student
    void approveClaim();

    // Processes the physical handover of an item
    void processHandover();

    // Rejects a claim submitted by a student
    void rejectClaim();

    // Getters
    std::string getAdminID();
    std::string getShift();
};

#endif
