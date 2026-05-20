#include "../include/SearchLog.h"
#include <iostream>

SearchLog::SearchLog(std::string logID, std::string keyword, std::string timestamp, std::string studentID) {
    this->logID = logID;
    this->keyword = keyword;
    this->timestamp = timestamp;
    this->studentID = studentID;
}

void SearchLog::logSearch() {
    std::cout << "Log: " << logID << " | Kw: " << keyword << " | Time: " << timestamp << " | Student: " << studentID << "\n";
}

void SearchLog::getHistory() {
    std::cout << "History Entry - Log: " << logID << " | Keyword: " << keyword 
              << " | Time: " << timestamp << " | Student: " << studentID << "\n";
}

std::string SearchLog::getLogID() { return logID; }
std::string SearchLog::getKeyword() { return keyword; }
std::string SearchLog::getTimestamp() { return timestamp; }
std::string SearchLog::getStudentID() { return studentID; }
