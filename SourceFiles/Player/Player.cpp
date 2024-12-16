
#include "Player/Player.h"

#include <iostream>

#include "Fish/Fish.h"
#include "Text/TextFormatting.h"


Player::Player()
{
}

void Player::AddFish(const Fish& fish, int amount)
{
    inventory.AddFishToInventory(fish, amount);
}

void Player::ShowInventory(Game& game)
{
    inventory.ShowInventory(game, Coins);
}

void Player::ChangeRodInInventory(const Rod &rod)
{
    inventory.ChangeRod(rod);
}

int Player::RodMultiplayer()
{
    return inventory.CurrentRodMultiplayer();
}

void Player::EarnXP(int amount)
{
    bool leveledUp = xp.AddXP(amount);

    std::cout << "You earned " << amount << " xp! Total xp: " << xp.GetCurrentXP()<< "\n";
    std::cout << "---------------------------------------\n" << TextFormatting::Reset;

    if (!leveledUp) return;

    std::cout <<"\n" << TextFormatting::Bold << TextFormatting::Orange << "------------------------------\n";
    std::cout << "You leveled up! You are now level " << xp.GetLevel()<< "\n";
    std::cout << "------------------------------\n" << TextFormatting::Reset;
}

