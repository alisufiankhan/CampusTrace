#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <string>

// Represents a student user in the campus system
class Student : public Person {
private:
    std::string rollNumber;
    std::string dept;
    int rejections;
    bool isFlagged;

public:
    // Constructor to initialize student details
    Student(std::string name, std::string ID, std::string contact, 
            std::string password, std::string rollNumber, std::string dept);

    // Submits a claim for a lost item
    void claimItem();

    // Allows the student to view the status of their claims
    void viewStatus();

    // Increments the count of rejected claims for the student
    void incrementRejections();

    // Getters
    std::string getRollNumber();
    std::string getDept();
    int getRejections();
    bool getIsFlagged();
};

#endif
