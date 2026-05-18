#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "include/FileManager.h"
#include "include/Item.h"
#include "include/Claim.h"
#include "include/Person.h"
#include "include/Student.h"
#include "include/Admin.h"
#include "include/Report.h"
#include "include/SearchLog.h"

// Global storage as requested
std::vector<Item*> globalItems;
std::vector<Claim*> globalClaims;
std::vector<Person*> globalUsers;

void adminMenu(Admin* admin, FileManager& fm) {
    while (true) {
        std::cout << "\n=== Admin Menu ===\n";
        std::cout << "1. Register new found item\n";
        std::cout << "2. View all items\n";
        std::cout << "3. Review pending claims\n";
        std::cout << "4. Process handover\n";
        std::cout << "5. Generate report\n";
        std::cout << "6. View flagged students\n";
        std::cout << "7. Logout\n";
        std::cout << "Choice: ";
        
        int choice;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again.\n";
            continue;
        }

        if (choice == 1) {
            admin->addItem();
            fm.saveItems(globalItems);
        } else if (choice == 2) {
            std::cout << "--- All Items ---\n";
            for (Item* item : globalItems) {
                std::cout << "- [" << item->getItemID() << "] " 
                          << item->getDesc() << " (" << item->getStatus() << ")\n";
            }
        } else if (choice == 3) {
            std::cout << "--- Pending Claims ---\n";
            for (Claim* claim : globalClaims) {
                if (claim->getClaimStatus() == "Pending" || claim->getClaimStatus() == "UnderReview") {
                    std::cout << "Claim ID: " << claim->getClaimID() 
                              << ", Item: " << claim->getItem()->getDesc() 
                              << ", Proof: " << claim->getProof() << "\n";
                }
            }
            std::cout << "1. Approve Claim\n2. Reject Claim\n3. Back\nChoice: ";
            int subChoice;
            if (!(std::cin >> subChoice)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            if (subChoice == 1) admin->approveClaim();
            else if (subChoice == 2) admin->rejectClaim();
            fm.saveClaims(globalClaims);
        } else if (choice == 4) {
            admin->processHandover();
            fm.saveItems(globalItems);
        } else if (choice == 5) {
            Report rpt("RPT001", admin->getName(), "All Time");
            rpt.generateReport();
        } else if (choice == 6) {
            std::cout << "--- Flagged Students ---\n";
            bool found = false;
            for (Person* p : globalUsers) {
                Student* s = dynamic_cast<Student*>(p);
                if (s && s->getIsFlagged()) {
                    std::cout << "- " << s->getName() << " (ID: " << s->getID() << ", Rejections: " << s->getRejections() << ")\n";
                    found = true;
                }
            }
            if (!found) std::cout << "No flagged students.\n";
        } else if (choice == 7) {
            std::cout << "Logging out...\n";
            break;
        } else {
            std::cout << "Invalid choice.\n";
        }
    }
}

void studentMenu(Student* student, FileManager& fm) {
    while (true) {
        std::cout << "\n=== Student Menu ===\n";
        std::cout << "1. Search for item by keyword\n";
        std::cout << "2. View my claims\n";
        std::cout << "3. Submit new claim\n";
        std::cout << "4. View my status\n";
        std::cout << "5. Logout\n";
        std::cout << "Choice: ";
        
        int choice;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again.\n";
            continue;
        }

        if (choice == 1) {
            std::string keyword;
            std::cout << "Enter keyword: ";
            std::cin >> keyword;
            
            SearchLog log("SL1", keyword, "2026-05-18", student->getID());
            log.logSearch();
            
            std::cout << "--- Search Results ---\n";
            bool found = false;
            for (Item* item : globalItems) {
                if (item->getDesc().find(keyword) != std::string::npos) {
                    std::cout << "- [" << item->getItemID() << "] " 
                              << item->getDesc() << " (" << item->getStatus() << ")\n";
                    found = true;
                }
            }
            if (!found) std::cout << "No matching items found.\n";
        } else if (choice == 2) {
            student->viewStatus();
        } else if (choice == 3) {
            student->claimItem();
            fm.saveClaims(globalClaims);
            fm.saveItems(globalItems);
        } else if (choice == 4) {
            std::cout << "--- My Trust Status ---\n";
            std::cout << "Rejections: " << student->getRejections() << "/3\n";
            std::cout << "Flagged: " << (student->getIsFlagged() ? "Yes" : "No") << "\n";
        } else if (choice == 5) {
            std::cout << "Logging out...\n";
            break;
        } else {
            std::cout << "Invalid choice.\n";
        }
    }
}

int main() {
    FileManager fm;
    // Load data from files
    fm.loadItems(globalItems);
    fm.loadClaims(globalClaims);

    // Hardcode some users so we can login and test the system
    globalUsers.push_back(new Admin("Admin Ali", "admin", "123456", "adminpass", "A01", "Morning"));
    globalUsers.push_back(new Student("Student Bob", "student", "654321", "studentpass", "R01", "CS"));

    while (true) {
        std::cout << "\n=== CampusTrace System ===\n";
        std::cout << "1. Admin Login\n";
        std::cout << "2. Student Login\n";
        std::cout << "3. Exit\n";
        std::cout << "Choice: ";
        
        int choice;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again.\n";
            continue;
        }

        if (choice == 3) {
            std::cout << "Exiting CampusTrace. Goodbye!\n";
            break;
        }
        
        if (choice != 1 && choice != 2) {
            std::cout << "Invalid choice.\n";
            continue;
        }

        std::string id, pass;
        std::cout << "Enter ID: ";
        std::cin >> id;
        std::cout << "Enter Password: ";
        std::cin >> pass;

        Person* loggedInUser = nullptr;
        for (Person* p : globalUsers) {
            if (p->getID() == id && p->getPassword() == pass) {
                if (choice == 1 && dynamic_cast<Admin*>(p) != nullptr) {
                    loggedInUser = p;
                    break;
                } else if (choice == 2 && dynamic_cast<Student*>(p) != nullptr) {
                    loggedInUser = p;
                    break;
                }
            }
        }

        if (loggedInUser) {
            std::cout << "Login successful! Welcome, " << loggedInUser->getName() << ".\n";
            if (choice == 1) {
                adminMenu(dynamic_cast<Admin*>(loggedInUser), fm);
            } else {
                studentMenu(dynamic_cast<Student*>(loggedInUser), fm);
            }
        } else {
            std::cout << "Invalid credentials or role. Please try again.\n";
        }
    }

    // Cleanup dynamically allocated memory
    for (Item* item : globalItems) delete item;
    for (Claim* claim : globalClaims) delete claim;
    for (Person* person : globalUsers) delete person;

    return 0;
}
