#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include "Item.h"
#include "Claim.h"
#include <string>
#include <vector>

class FileManager {
private:
    std::string itemsFile, usersFile, claimsFile;
public:
    FileManager(std::string itemsFile = "data/items.txt", 
                std::string usersFile = "data/users.txt", 
                std::string claimsFile = "data/claims.txt");
    void saveItems(std::vector<Item*> items);
    std::vector<Item*> loadItems();
    void saveClaims(std::vector<Claim*> claims);
    std::vector<Claim*> loadClaims();
};
#endif
