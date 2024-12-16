#ifndef PLAYERINVENTORY_H
#define PLAYERINVENTORY_H
#include <unordered_map>

#include "PlayerCoins.h"
#include "Fish/Fish.h"
#include "Fish/FishType.h"
#include "Shop/Rod/Rod.h"

class Game;

class PlayerInventory
{
    std::unordered_map<FishType, int> inventory = {};
    void ShowChoices(PlayerCoins& coins, int coinsAdded);

    Rod currentRod = {RodType::Default, 0, 1};

public:
    int CurrentRodMultiplayer() const { return currentRod.FishMultiplier; }
    void AddFishToInventory(const Fish& fish, int amount);
    void ChangeRod(const Rod& rod);
    void ShowInventory(Game& game, PlayerCoins& coins);
};



#endif //PLAYERINVENTORY_H
