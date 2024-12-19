#ifndef PLAYERXP_H
#define PLAYERXP_H
#include <nlohmann/json_fwd.hpp>
#include "SavingLoading/Savable.h"

using json = nlohmann::json;

class PlayerXP: public Savable
{

    int currentXP;
    int level;

public:
    PlayerXP() : currentXP(0), level(1) {}
    bool AddXP(const int &amount);
    void LevelUp();

    int GetCurrentXP() const { return currentXP; }
    int GetLevel() const { return level; }

    json SaveJson() const override;
    void LoadJson(const json &j) override;
};

#endif //PLAYERXP_H
