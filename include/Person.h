#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person {
private:
    std::string name, ID, contact, password;
public:
    Person(std::string name, std::string ID, std::string contact, std::string password);
    virtual ~Person() = default;
    bool login();
    virtual void getInfo();
    std::string getName();
    std::string getID();
    std::string getContact();
    std::string getPassword();
};
#endif
