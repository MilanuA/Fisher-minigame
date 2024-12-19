#include "Player/Player.h"
#include <iostream>
#include "Fish/Fish.h"
#include "SavingLoading/SaveLoad.h"
#include "SavingLoading/SavingPaths.h"
#include "Text/TextFormatting.h"


Player::Player()
{
}

void Player::AddFish(const Fish &fish, const int &amount)
{
    inventory.AddFishToInventory(fish, amount);
}

void Player::ShowInventory(Game &game)
{
    inventory.ShowInventory(game, Coins);
}

void Player::ChangeRodInInventory(const Rod &rod)
{
    inventory.ChangeRod(rod);
}

void Player::SavePlayerData() const
{
    json playerData;

    playerData["inventory"] = inventory.SaveJson();
    playerData["coins"] = Coins.SaveJson();
    playerData["xp"] = xp.SaveJson();

    SaveLoad::Save(playerData, SavingPaths::GetSaveFilePath("player_data"));
}

void Player::LoadPlayerData()
{
    if (!SavingPaths::HasSaveFile("player_data"))
    {
        std::cout << "Player data file does not exist" << std::endl;
        return;
    }

    json playerData;

    if (!SaveLoad::Load(playerData, SavingPaths::GetSaveFilePath("player_data")))
    {
        std::cout << "Failed to load player data" << std::endl;
        return;
    }

    LoadDataFromJson(playerData, "inventory", inventory, "Inventory");
    LoadDataFromJson(playerData, "coins", Coins, "Coins");
    LoadDataFromJson(playerData, "xp", xp, "XP");

    std::cout << "Player data loaded successfully" << std::endl;
}

int Player::RodMultiplayer() const
{
    return inventory.CurrentRodMultiplayer();
}

void Player::EarnXP(const int &amount)
{
    bool leveledUp = xp.AddXP(amount);

    std::cout << "You earned " << amount << " xp! Total xp: " << xp.GetCurrentXP()<< "\n";
    std::cout << "---------------------------------------\n" << TextFormatting::Reset;

    if (!leveledUp) return;

    std::cout <<"\n" << TextFormatting::Bold << TextFormatting::Orange << "------------------------------\n";
    std::cout << "You leveled up! You are now level " << xp.GetLevel()<< "\n";
    std::cout << "------------------------------\n" << TextFormatting::Reset;
}

void Player::LoadDataFromJson(const json& playerData, const std::string& key, auto& dataObject, const std::string& dataName)
{
    if (!playerData.contains(key))
    {
        std::cout << dataName << " missing in player data" << std::endl;
        return;
    }

    dataObject.LoadJson(playerData[key]);
}