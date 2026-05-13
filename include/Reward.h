#ifndef REWARD_H
#define REWARD_H

#include <string>

// Manages rewards offered for found items
class Reward {
private:
    std::string rewardID;
    std::string offeredBy;
    std::string rewardDesc;
    std::string rewardStatus;

public:
    // Constructor to initialize reward details
    Reward(std::string rewardID, std::string offeredBy, 
           std::string rewardDesc, std::string rewardStatus);

    // Offers a reward for a found item
    void offerReward();

    // Cancels an offered reward
    void cancelReward();

    // Gets the current status of the reward
    std::string getStatus();

    // Getters
    std::string getRewardID();
    std::string getOfferedBy();
    std::string getRewardDesc();
    std::string getRewardStatus();
};

#endif
