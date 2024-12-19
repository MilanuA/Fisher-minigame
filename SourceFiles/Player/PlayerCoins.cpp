#include "Player/PlayerCoins.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

PlayerCoins::PlayerCoins() : coins(0)
{

}

void PlayerCoins::AddCoins(const int &amount)
{
    coins += amount;
}

void PlayerCoins::DecreaseCoins(const int &amount)
{
    coins -= amount;
}

json PlayerCoins::SaveJson() const
{
    return json
    {
        {"coins", coins}
    };
}

void PlayerCoins::LoadJson(const json &j) {
}
