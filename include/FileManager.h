#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "Item.h"
#include "Claim.h"
#include <vector>
#include <string>

// Handles saving and loading of system data to/from files
class FileManager {
public:
    // Saves item data to a file
    void saveItems(const std::vector<Item*>& items);

    // Loads item data from a file
    void loadItems(std::vector<Item*>& items);

    // Saves claim data to a file
    void saveClaims(const std::vector<Claim*>& claims);

    // Loads claim data from a file
    void loadClaims(std::vector<Claim*>& claims);
};

#endif
