#include "../include/Reward.h"
#include <iostream>

Reward::Reward(std::string rewardID, std::string offeredBy, std::string desc, std::string status) {
    this->rewardID = rewardID;
    this->offeredBy = offeredBy;
    this->desc = desc;
    this->status = status;
}

void Reward::offerReward() {
    status = "Active";
    std::cout << "Reward " << rewardID << " has been offered.\n";
}

void Reward::cancelReward() {
    status = "Cancelled";
    std::cout << "Reward " << rewardID << " has been cancelled.\n";
}

std::string Reward::getRewardStatus() { return status; }
std::string Reward::getRewardID() { return rewardID; }
std::string Reward::getOfferedBy() { return offeredBy; }
std::string Reward::getRewardDesc() { return desc; }
