#include "include/Person.h"
#include "include/Student.h"
#include "include/Admin.h"
#include "include/Item.h"
#include "include/ElectronicItem.h"
#include "include/DocumentItem.h"
#include "include/PersonalItem.h"
#include "include/Transaction.h"
#include "include/Claim.h"
#include "include/Handover.h"
#include "include/Reward.h"
#include "include/SearchLog.h"
#include "include/Report.h"
#include "include/FileManager.h"
#include "include/MatchEngine.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <limits>

std::vector<Claim*> allClaims;

void clearScreen() {
    // Basic screen clear
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

std::string currentDate() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d-%m-%Y", &tstruct);
    return std::string(buf);
}

int main() {
    FileManager fileManager("data/items.txt", "data/users.txt", "data/claims.txt");
    std::vector<Item*> allItems = fileManager.loadItems();
    allClaims = fileManager.loadClaims();

    std::vector<Person*> allUsers;
    allUsers.push_back(new Admin("Admin One", "A001", "0300-1234567", "admin123", "ADM001", "Morning"));
    allUsers.push_back(new Student("Ali Sufian", "S001", "0301-1234567", "ali123", "B25F0559AI154", "AI"));
    allUsers.push_back(new Student("Amina Shafique", "S002", "0302-1234567", "amina123", "B25F2267AI157", "AI"));
    allUsers.push_back(new Student("Umama Khurram", "S003", "0303-1234567", "umama123", "B25F2677AI147", "AI"));

    while (true) {
        clearScreen();
        std::cout << "Welcome to CampusTrace\n";
        std::cout << "1. Login as Admin\n";
        std::cout << "2. Login as Student\n";
        std::cout << "3. Exit\n";
        std::cout << "Choice: ";
        
        int mainChoice;
        if (!(std::cin >> mainChoice)) { 
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            continue; 
        }

        if (mainChoice == 3) {
            fileManager.saveItems(allItems);
            fileManager.saveClaims(allClaims);
            std::cout << "Goodbye\n";
            break;
        }

        if (mainChoice != 1 && mainChoice != 2) continue;

        std::string id, pass;
        std::cout << "Enter ID: "; std::cin >> id;
        std::cout << "Enter Password: "; std::cin >> pass;

        Person* loggedIn = nullptr;
        for (Person* p : allUsers) {
            if (p->getID() == id && p->getPassword() == pass) {
                if (mainChoice == 1 && dynamic_cast<Admin*>(p)) loggedIn = p;
                if (mainChoice == 2 && dynamic_cast<Student*>(p)) loggedIn = p;
            }
        }

        if (!loggedIn) {
            std::cout << "Login Failed. Try again.\n";
            std::cin.ignore(); std::cin.get();
            continue;
        }

        if (mainChoice == 1) {
            Admin* admin = dynamic_cast<Admin*>(loggedIn);
            while (true) {
                clearScreen();
                std::cout << "=== Admin Menu ===\n";
                std::cout << "1. Register new found item\n";
                std::cout << "2. View all items\n";
                std::cout << "3. Review pending claims\n";
                std::cout << "4. Process handover\n";
                std::cout << "5. View flagged students\n";
                std::cout << "6. Generate report\n";
                std::cout << "7. Logout\n";
                std::cout << "Choice: ";
                
                int adminChoice;
                if (!(std::cin >> adminChoice)) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); continue; }

                if (adminChoice == 1) {
                    admin->addItem(allItems);
                    fileManager.saveItems(allItems);
                } else if (adminChoice == 2) {
                    for (Item* item : allItems) {
                        item->getDetails();
                        if (item->isExpired()) std::cout << " (Expired)";
                        std::cout << "\n";
                    }
                } else if (adminChoice == 3) {
                    for (Claim* claim : allClaims) {
                        if (claim->getClaimStatus() == "Pending") {
                            std::cout << "Claim ID: " << claim->getClaimID() << " | Proof: " << claim->getProof() << "\n";
                            std::cout << "Approve (1) or Reject (2)? ";
                            int dec; 
                            if (!(std::cin >> dec)) { std::cin.clear(); std::cin.ignore(10000, '\n'); continue; }
                            if (dec == 1) {
                                admin->approveClaim(claim);
                            } else if (dec == 2) {
                                Student* s = dynamic_cast<Student*>(claim->getPerson());
                                if(s) admin->rejectClaim(claim, s);
                            }
                            fileManager.saveClaims(allClaims);
                        }
                    }
                } else if (adminChoice == 4) {
                    std::cout << "Enter Claim ID: ";
                    std::string cID; std::cin >> cID;
                    Claim* foundClaim = nullptr;
                    for (Claim* c : allClaims) {
                        if (c->getClaimID() == cID) foundClaim = c;
                    }
                    if (foundClaim) {
                        std::cout << "Enter Witness Name: ";
                        std::string witness; std::cin >> witness;
                        admin->processHandover(foundClaim, witness);
                        fileManager.saveItems(allItems);
                    } else {
                        std::cout << "Claim not found.\n";
                    }
                } else if (adminChoice == 5) {
                    for (Person* p : allUsers) {
                        Student* s = dynamic_cast<Student*>(p);
                        if (s && s->getIsFlagged()) {
                            std::cout << "- " << s->getName() << " (ID: " << s->getID() << ")\n";
                        }
                    }
                } else if (adminChoice == 6) {
                    Report rpt("R1", admin->getName(), "All", allItems);
                    rpt.generateReport();
                    rpt.countByStatus();
                    rpt.listExpired();
                } else if (adminChoice == 7) {
                    break;
                }
                std::cout << "Press enter to continue...";
                std::cin.ignore(); std::cin.get();
            }
        } else if (mainChoice == 2) {
            Student* student = dynamic_cast<Student*>(loggedIn);
            MatchEngine matchEngine;
            while (true) {
                clearScreen();
                std::cout << "=== Student Menu ===\n";
                std::cout << "1. Search for item\n";
                std::cout << "2. Submit claim\n";
                std::cout << "3. View my claims\n";
                std::cout << "4. View my status\n";
                std::cout << "5. Logout\n";
                std::cout << "Choice: ";
                
                int studentChoice;
                if (!(std::cin >> studentChoice)) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); continue; }

                if (studentChoice == 1) {
                    std::string keyword;
                    std::cout << "Enter keyword: "; std::cin >> keyword;
                    SearchLog log("SL" + std::to_string(time(0)), keyword, currentDate(), student->getID());
                    log.logSearch();
                    std::vector<Item*> results = matchEngine.searchByKeyword(keyword, allItems);
                    for (Item* item : results) {
                        item->getDetails();
                        std::cout << "\n";
                    }
                } else if (studentChoice == 2) {
                    std::string keyword;
                    std::cout << "Search item to claim: "; std::cin >> keyword;
                    std::vector<Item*> results = matchEngine.searchByKeyword(keyword, allItems);
                    for (Item* item : results) {
                        item->getDetails();
                        std::cout << "\n";
                    }
                    std::string iID;
                    std::cout << "Enter item ID to claim: "; std::cin >> iID;
                    Item* targetItem = nullptr;
                    for (Item* item : results) {
                        if (item->getItemID() == iID) targetItem = item;
                    }
                    if (targetItem) {
                        std::string proof;
                        std::cout << "Enter proof description: "; std::cin >> proof;
                        std::string cID = "C" + std::to_string(time(0));
                        Claim* claim = new Claim(cID, proof, "Pending", targetItem, "TXN" + std::to_string(time(0)), currentDate(), student);
                        claim->submitClaim();
                        allClaims.push_back(claim);
                        fileManager.saveClaims(allClaims);
                    } else {
                        std::cout << "Item not found in results.\n";
                    }
                } else if (studentChoice == 3) {
                    for (Claim* claim : allClaims) {
                        if (claim->getPerson() == student) {
                            claim->processTransaction();
                        }
                    }
                } else if (studentChoice == 4) {
                    student->viewStatus();
                } else if (studentChoice == 5) {
                    break;
                }
                std::cout << "Press enter to continue...";
                std::cin.ignore(); std::cin.get();
            }
        }
    }
    
    // Cleanup
    for (Item* i : allItems) delete i;
    for (Claim* c : allClaims) delete c;
    for (Person* p : allUsers) delete p;

    return 0;
}
