#ifndef REWARD_H
#define REWARD_H
#include <string>

class Reward {
private:
    std::string rewardID, offeredBy, desc, status;
public:
    Reward(std::string rewardID, std::string offeredBy, std::string desc, std::string status);
    void offerReward();
    void cancelReward();
    std::string getRewardStatus();
    std::string getRewardID();
    std::string getOfferedBy();
    std::string getRewardDesc();
};
#endif
