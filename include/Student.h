#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
#include <string>

class Student : public Person {
private:
    std::string rollNumber, dept;
    int rejections;
    bool isFlagged;
public:
    Student(std::string name, std::string ID, std::string contact, std::string password,
            std::string rollNumber, std::string dept);
    void claimItem(std::string itemID);
    void viewStatus();
    void incrementRejections();
    std::string getRollNumber();
    std::string getDept();
    int getRejections();
    bool getIsFlagged();
};
#endif
