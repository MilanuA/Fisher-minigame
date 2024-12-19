#include "Player/PlayerXP.h"
#include <nlohmann/json.hpp>
#include "SavingLoading/Savable.h"

using json = nlohmann::json;

bool PlayerXP::AddXP(const int &amount)
{
    currentXP += amount;

    if (currentXP >= level * 100)
    {
        LevelUp();

        return true;
    }

    return false;
}

void PlayerXP::LevelUp()
{
    level++;
    currentXP = 0;
}

json PlayerXP::SaveJson() const
{
    return json
    {
        {"currentXP", currentXP},
        {"level", level}
    };
}

void PlayerXP::LoadJson(const json &j)
{
    currentXP = j["currentXP"];
    level = j["level"];
}
