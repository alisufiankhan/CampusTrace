#ifndef REPORT_H
#define REPORT_H

#include "Item.h"
#include <string>
#include <vector>

// Generates system reports regarding items and their statuses
class Report {
private:
    std::string reportID;
    std::string generatedBy;
    std::string dateRange;

public:
    // Constructor to initialize report details
    Report(std::string reportID, std::string generatedBy, std::string dateRange);

    // Generates a comprehensive report
    void generateReport();

    // Counts items based on their status
    int countByStatus(std::string status);

    // Lists items that have expired
    void listExpired();

    // Getters
    std::string getReportID();
    std::string getGeneratedBy();
    std::string getDateRange();
};

#endif
