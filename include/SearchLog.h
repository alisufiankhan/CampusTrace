#ifndef SEARCHLOG_H
#define SEARCHLOG_H
#include <string>
#include <vector>

class SearchLog {
private:
    std::string logID, keyword, timestamp, studentID;
public:
    SearchLog(std::string logID, std::string keyword, std::string timestamp, std::string studentID);
    void logSearch();
    void getHistory();
    std::string getLogID();
    std::string getKeyword();
    std::string getTimestamp();
    std::string getStudentID();
};
#endif
