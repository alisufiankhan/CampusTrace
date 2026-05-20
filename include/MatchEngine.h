#ifndef MATCHENGINE_H
#define MATCHENGINE_H
#include "Item.h"
#include <string>
#include <vector>

class MatchEngine {
public:
    MatchEngine();
    std::vector<Item*> searchByKeyword(std::string keyword, std::vector<Item*> allItems);
};
#endif
