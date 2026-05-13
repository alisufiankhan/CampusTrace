#ifndef PERSON_H
#define PERSON_H

#include <string>

// Base class for all users in the system
// Student and Admin both inherit from Person
class Person {
private:
    std::string name;
    std::string ID;
    std::string contact;
    std::string password;

public:
    // Constructor to initialize person details
    Person(std::string name, std::string ID, 
           std::string contact, 
           std::string password);

    // Virtual destructor for proper cleanup of derived classes
    virtual ~Person() {}

    // Logs the user into the system
    // Returns true if ID and password match
    bool login();

    // Prints all person details to console
    virtual void getInfo();

    // Getters
    std::string getName();
    std::string getID();
    std::string getContact();
    std::string getPassword();
};

#endif
