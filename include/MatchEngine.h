#ifndef MATCH_ENGINE_H
#define MATCH_ENGINE_H

#include "Item.h"
#include <vector>
#include <string>

// Engine responsible for matching search queries with items
class MatchEngine {
public:
    // Searches for items matching a specific keyword
    std::vector<Item*> searchByKeyword(std::string keyword, const std::vector<Item*>& allItems);
};

#endif
