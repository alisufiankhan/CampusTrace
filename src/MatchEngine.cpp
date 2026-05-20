#include "../include/MatchEngine.h"
#include <algorithm>

MatchEngine::MatchEngine() {}

std::string MatchEngine_toLower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

std::vector<Item*> MatchEngine::searchByKeyword(std::string keyword, std::vector<Item*> allItems) {
    std::vector<Item*> results;
    std::string kw = MatchEngine_toLower(keyword);
    for (Item* item : allItems) {
        if (MatchEngine_toLower(item->getDesc()).find(kw) != std::string::npos ||
            MatchEngine_toLower(item->getLocation()).find(kw) != std::string::npos) {
            results.push_back(item);
        }
    }
    return results;
}
