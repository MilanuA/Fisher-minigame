#include "../HeaderFiles/Fishing.h"

#include <iostream>

#include "Text/TextFormatting.h"

Fishing::Fishing(std::shared_ptr<Player> playerPtr)
    : player(playerPtr), totalRarity(0) {}

Fish Fishing::CastLine(std::vector<Fish> fishPool)
{
    int randomValue = rand() % totalRarity;
    int accumulatedRarity = 0;

    for (const auto& fish : fishPool)
    {
        if (player->GetLevel() < fish.UnlockLevel)
            continue;

        accumulatedRarity += fish.FishRarity;

        if (randomValue < accumulatedRarity)
        {
            return fish;
        }
    }

  return {FishType::None, 0, 0, 0, 0};;
}

int Fishing::GetRandomNumber(int min, int max)
{
    return min + rand() % ((max + 1) - min);
}

void Fishing::TryFishing(std::vector<Fish> fishPool)
{
    Fish caughtFish = CastLine(fishPool);

    if (caughtFish.Fishtype != FishType::None)
    {
        player->AddFish(caughtFish, player->RodMultiplayer());
        player->EarnXP(caughtFish.XP * player->RodMultiplayer());

        return;
    }

    std::cout << TextFormatting::Bold << TextFormatting::Red<< "\nYou caught nothing. Try again!\n" << TextFormatting::Reset;
}

void Fishing::RecalculateTotalRarity(std::vector<Fish> fishPool)
{
    totalRarity = 0;

    for (const Fish &fish: fishPool)
    {
        totalRarity += fish.FishRarity;
    }
}
