#ifndef ADMIN_H
#define ADMIN_H
#include "Person.h"
#include "Item.h"
#include "Claim.h"
#include "Student.h"
#include <string>
#include <vector>

class Admin : public Person {
private:
    std::string adminID, shift;
public:
    Admin(std::string name, std::string ID, std::string contact, std::string password,
          std::string adminID, std::string shift);
    void addItem(std::vector<Item*>& items);
    void approveClaim(Claim* claim);
    void rejectClaim(Claim* claim, Student* student);
    void processHandover(Claim* claim, std::string witness);
    std::string getAdminID();
    std::string getShift();
};
#endif
