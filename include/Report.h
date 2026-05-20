#ifndef REPORT_H
#define REPORT_H
#include "Item.h"
#include <string>
#include <vector>

class Report {
private:
    std::string reportID, generatedBy, dateRange;
    std::vector<Item*> items;
public:
    Report(std::string reportID, std::string generatedBy, std::string dateRange, std::vector<Item*> items);
    void generateReport();
    void countByStatus();
    void listExpired();
    std::string getReportID();
    std::string getGeneratedBy();
    std::string getDateRange();
};
#endif
