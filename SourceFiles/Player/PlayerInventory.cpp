#include "../HeaderFiles/Player/PlayerInventory.h"
#include <iostream>
#include <nlohmann/json.hpp>

#include "Game.h"
#include "Text/TextFormatting.h"

using json = nlohmann::json;

void PlayerInventory::AddFishToInventory(const Fish &fish, int amount)
{
    inventory[fish.Fishtype] += amount;

    std::cout << "\n" << TextFormatting::Bold << TextFormatting::Green << "---------------------------------------\n";
    std::cout << "You caught " << amount << "x " << Fish::ToString(fish.Fishtype)  << "!\n";
}

void PlayerInventory::ChangeRod(const Rod &rod)
{
    currentRod = rod;
}

void PlayerInventory::ShowInventory(Game &game, PlayerCoins& coins)
{
    int totalPrice = 0;

    std::cout << "\n" << TextFormatting::Bold << TextFormatting::Yellow <<"--- Your Inventory: ---\n" << TextFormatting::Reset;

    std::string rod = currentRod.Type != RodType::Default ? Rod::ToString(currentRod.Type) : Rod::ToString(RodType::Default);
    std::cout << "\nCurrent rod: " << rod << "\n";
    std::cout << "Current balance: " << coins.GetCoins() << " coins\n";

    std::cout<< "\nFishes:\n";

    if (inventory.empty())
    {
        std::cout << "Your inventory is empty.\n";

        std::cout << "\n" << TextFormatting::Bold << TextFormatting::Yellow <<"-------------\n" << TextFormatting::Reset;
        return;
    }

    std::cout << "\n";
    for (const std::pair<const FishType, int> &pair: inventory)
    {
        int fishPrice = game.GetFish(pair.first).FishPrice;

        totalPrice += fishPrice * pair.second;

        std::cout << "- " << pair.second << "x " << Fish().ToString(pair.first) << " (" << fishPrice << " coins)" << "\n";
    }

    std::cout << "\nTotal inventory price: " << totalPrice << " coins.\n";

    ShowChoices(coins, totalPrice);
}

json PlayerInventory::SaveJson() const
{
    return json
    {
        {"inventory", inventory},
        {"currentRod", currentRod}
    };
}

void PlayerInventory::LoadJson(const json &j)
{
    inventory = j.at("inventory").get<std::unordered_map<FishType, int>>();
    currentRod = j.at("currentRod").get<Rod>();
}


void PlayerInventory::ShowChoices(PlayerCoins& coins, int coinsAdded)
{
    std::cout << TextFormatting::Bold << TextFormatting::Yellow <<"\n--- Options ---\n" << TextFormatting::Reset;
    std::cout << "1. Go back\n";
    std::cout << "2. Sell your inventory\n";
    std::cout << "3. Exit\n";
    std::cout << TextFormatting::Bold << TextFormatting::Yellow <<"-----------\n" << TextFormatting::Reset;
    std::cout << "Your choice: ";
    int choice;
    std::cin >> choice;

    switch (choice)
    {
        case 1:
            break;
        case 2:
            inventory.clear();
            coins.AddCoins(coinsAdded);
            std::cout << "\nYou sold your inventory. Your current balance: " << coins.GetCoins() << " coins.\n";
            break;
        case 3:
            exit(0);
        default:
            std::cout << "Invalid choice. Please try again.\n";
            ShowChoices(coins, coinsAdded);
    }
}

