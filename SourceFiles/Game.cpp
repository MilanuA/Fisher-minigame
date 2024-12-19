#include "../HeaderFiles/Game.h"

#include <iostream>
#include "SavingLoading/SavingPaths.h"
#include "Text/Menu.h"
#include "Text/TextFormatting.h"


Game::Game(): player(std::make_shared<Player>()), fishing(player), shop(player)
{
    fishPool =
    {
        {FishType::Salmon, 30, 100, 50, 2},
        {FishType::Tuna, 20, 80, 40, 2},
        {FishType::Shark, 5, 300, 100, 5},
        {FishType::Goldfish, 70, 10, 10, 1},
        {FishType::Herring, 60, 20, 10, 1},
        {FishType::Perch, 50, 15, 8, 1},
        {FishType::Swordfish, 35, 150, 70, 3},
        {FishType::Cod, 35, 60, 30, 3},
        {FishType::Mackerel, 45, 25, 12, 4},
        {FishType::Trout, 38, 50, 25, 4},
        {FishType::Halibut, 15, 120, 60, 5},
        {FishType::Snapper, 18, 90, 45, 6},
        {FishType::Grouper, 12, 110, 55, 6},
        {FishType::MahiMahi, 22, 95, 48, 7}
    };

    fishing.RecalculateTotalRarity(fishPool);
}

void Game::Start()
{
    Menu menu;
    menu.AddOption("Fish", [this]() { fishing.TryFishing(fishPool); });
    menu.AddOption("Show inventory", [this]() { player->ShowInventory(*this); });
    menu.AddOption("Show shop", [this]() { shop.ShowShop(); });
    menu.AddOption("Save the game", [this]() { SaveGame(); });

    if (SavingPaths::HasSaveFile("player_data"))
        menu.AddOption("Load the game", [this]() { LoadGame(); });

    menu.ShowMenu();
}

Fish Game::GetFish(const FishType &fishType)
{
    for (const Fish &fish: fishPool)
    {
        if (fish.Fishtype != fishType) continue;

        return fish;
    }
    return Fish{FishType::None, 0, 0, 0};
}


void Game::SaveGame() const
{
    player->SavePlayerData();
    std::cout << TextFormatting::Bold << TextFormatting::Green <<"\nSuccessfully saved the game progress\n"<<TextFormatting::Reset << std::endl;
}

void Game::LoadGame() const
{
    player->LoadPlayerData();
    std::cout << TextFormatting::Bold << TextFormatting::Green <<"\nSuccessfully loaded the game progress\n"<<TextFormatting::Reset << std::endl;
}
