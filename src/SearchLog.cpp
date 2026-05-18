#include "../include/SearchLog.h"
#include <iostream>

static std::vector<SearchLog*> searchLogHistory;

SearchLog::SearchLog(std::string logID, std::string keyword, 
                     std::string timestamp, std::string studentID) {
    this->logID = logID;
    this->keyword = keyword;
    this->timestamp = timestamp;
    this->studentID = studentID;
}

void SearchLog::logSearch() {
    searchLogHistory.push_back(this);
    // Optionally log to console
    // std::cout << "Search logged for keyword: " << keyword << "\n";
}

std::vector<std::string> SearchLog::getHistory() {
    std::vector<std::string> history;
    for (SearchLog* log : searchLogHistory) {
        std::string entry = "Student " + log->getStudentID() + 
                            " searched '" + log->getKeyword() + 
                            "' at " + log->getTimestamp();
        history.push_back(entry);
    }
    return history;
}

std::string SearchLog::getLogID() {
    return logID;
}

std::string SearchLog::getKeyword() {
    return keyword;
}

std::string SearchLog::getTimestamp() {
    return timestamp;
}

std::string SearchLog::getStudentID() {
    return studentID;
}
