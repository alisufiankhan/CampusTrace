#include "../include/Person.h"
#include <iostream>

Person::Person(std::string name, std::string ID, std::string contact, std::string password) {
    this->name = name;
    this->ID = ID;
    this->contact = contact;
    this->password = password;
}

bool Person::login() {
    std::string inputID, inputPassword;
    std::cout << "Enter ID: ";
    std::cin >> inputID;
    std::cout << "Enter Password: ";
    std::cin >> inputPassword;
    
    if (inputID == this->ID && inputPassword == this->password) {
        return true;
    }
    return false;
}

void Person::getInfo() {
    std::cout << "Name: " << name << "\n"
              << "ID: " << ID << "\n"
              << "Contact: " << contact << std::endl;
}

std::string Person::getName() {
    return name;
}

std::string Person::getID() {
    return ID;
}

std::string Person::getContact() {
    return contact;
}

std::string Person::getPassword() {
    return password;
}
