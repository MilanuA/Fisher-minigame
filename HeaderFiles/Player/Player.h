#ifndef PLAYER_H
#define PLAYER_H

#include "PlayerCoins.h"
#include "PlayerInventory.h"
#include "PlayerXP.h"

class Game;

class Player
{
    PlayerInventory inventory;
    PlayerXP xp;

    void LoadDataFromJson(const json& playerData, const std::string& key, auto& dataObject, const std::string& dataName);

public:
    Player();
    PlayerCoins Coins;

    void AddFish(const Fish &fish, const int &amount);
    void EarnXP(const int &amount);
    void ShowInventory(Game &game) ;
    void ChangeRodInInventory(const Rod& rod);

    void SavePlayerData() const;
    void LoadPlayerData();

    int RodMultiplayer() const;
    int GetLevel() const { return xp.GetLevel(); }
};

#endif //PLAYER_H
