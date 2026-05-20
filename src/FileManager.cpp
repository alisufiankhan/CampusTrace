#include "../include/FileManager.h"
#include "../include/ElectronicItem.h"
#include "../include/DocumentItem.h"
#include "../include/PersonalItem.h"
#include "../include/Claim.h"
#include <fstream>
#include <sstream>

FileManager::FileManager(std::string itemsFile, std::string usersFile, std::string claimsFile) {
    this->itemsFile = itemsFile.empty() ? "data/items.txt" : itemsFile;
    this->usersFile = usersFile.empty() ? "data/users.txt" : usersFile;
    this->claimsFile = claimsFile.empty() ? "data/claims.txt" : claimsFile;
}

std::vector<std::string> fm_split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void FileManager::saveItems(std::vector<Item*> items) {
    std::ofstream out(itemsFile);
    if (!out) return;
    for (Item* item : items) {
        if (ElectronicItem* e = dynamic_cast<ElectronicItem*>(item)) {
            out << "E|" << e->getItemID() << "|" << e->getDesc() << "|" << e->getDateFound() << "|" 
                << e->getLocation() << "|" << e->getStatus() << "|" 
                << e->getBrand() << "|" << e->getColor() << "|" << e->getSerialNumber() << "\n";
        } else if (DocumentItem* d = dynamic_cast<DocumentItem*>(item)) {
            out << "D|" << d->getItemID() << "|" << d->getDesc() << "|" << d->getDateFound() << "|" 
                << d->getLocation() << "|" << d->getStatus() << "|" 
                << d->getDocType() << "|" << d->getIssuedBy() << "\n";
        } else if (PersonalItem* p = dynamic_cast<PersonalItem*>(item)) {
            out << "P|" << p->getItemID() << "|" << p->getDesc() << "|" << p->getDateFound() << "|" 
                << p->getLocation() << "|" << p->getStatus() << "|" 
                << p->getColor() << "|" << p->getSize() << "|" << p->getMaterial() << "\n";
        } else {
            out << "I|" << item->getItemID() << "|" << item->getDesc() << "|" << item->getDateFound() << "|" 
                << item->getLocation() << "|" << item->getStatus() << "\n";
        }
    }
    out.close();
}

std::vector<Item*> FileManager::loadItems() {
    std::vector<Item*> items;
    std::ifstream in(itemsFile);
    if (!in) return items;
    std::string line;
    while (std::getline(in, line)) {
        if(line.empty()) continue;
        auto t = fm_split(line, '|');
        if (t.empty()) continue;
        std::string type = t[0];
        if (type == "E" && t.size() >= 9) {
            items.push_back(new ElectronicItem(t[1], t[2], t[3], t[4], t[5], t[6], t[7], t[8]));
        } else if (type == "D" && t.size() >= 8) {
            items.push_back(new DocumentItem(t[1], t[2], t[3], t[4], t[5], t[6], t[7]));
        } else if (type == "P" && t.size() >= 9) {
            items.push_back(new PersonalItem(t[1], t[2], t[3], t[4], t[5], t[6], t[7], t[8]));
        } else if (type == "I" && t.size() >= 6) {
            items.push_back(new Item(t[1], t[2], t[3], t[4], t[5]));
        }
    }
    return items;
}

void FileManager::saveClaims(std::vector<Claim*> claims) {
    std::ofstream out(claimsFile);
    if (!out) return;
    for (Claim* claim : claims) {
        out << claim->getClaimID() << "|" << claim->getProof() << "|" << claim->getClaimStatus() << "|"
            << (claim->getItem() ? claim->getItem()->getItemID() : "") << "|"
            << claim->getTransactionID() << "|" << claim->getDate() << "|"
            << (claim->getPerson() ? claim->getPerson()->getID() : "") << "\n";
    }
    out.close();
}

std::vector<Claim*> FileManager::loadClaims() {
    std::vector<Claim*> claims;
    std::ifstream in(claimsFile);
    if (!in) return claims;
    std::string line;
    while (std::getline(in, line)) {
        if(line.empty()) continue;
        auto t = fm_split(line, '|');
        if (t.size() >= 7) {
            claims.push_back(new Claim(t[0], t[1], t[2], nullptr, t[4], t[5], nullptr));
        }
    }
    return claims;
}
