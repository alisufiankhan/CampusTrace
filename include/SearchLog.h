#ifndef SEARCH_LOG_H
#define SEARCH_LOG_H

#include <string>
#include <vector>

// Logs search activities by students
class SearchLog {
private:
    std::string logID;
    std::string keyword;
    std::string timestamp;
    std::string studentID;

public:
    // Constructor to initialize search log details
    SearchLog(std::string logID, std::string keyword, 
              std::string timestamp, std::string studentID);

    // Logs a new search query
    void logSearch();

    // Returns the history of search logs
    std::vector<std::string> getHistory();

    // Getters
    std::string getLogID();
    std::string getKeyword();
    std::string getTimestamp();
    std::string getStudentID();
};

#endif
