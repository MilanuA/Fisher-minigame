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

public:
    Player();
    PlayerCoins Coins;

    void AddFish(const Fish& fish, int amount);
    void EarnXP(int amount);
    void ShowInventory(Game& game) ;
    void ChangeRodInInventory(const Rod& rod);

    int RodMultiplayer();

    int GetLevel() const { return xp.GetLevel(); }
};

#endif //PLAYER_H
