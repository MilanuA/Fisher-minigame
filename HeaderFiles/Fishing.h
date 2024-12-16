#ifndef FISHING_H
#define FISHING_H
#include <memory>
#include <vector>

#include "Fish/Fish.h"
#include "Player/Player.h"

class Fishing
{
    std::shared_ptr<Player> player;

    Fish CastLine(std::vector<Fish> fishPool);
    int GetRandomNumber(int min, int max);
    int totalRarity;


public:
    Fishing(std::shared_ptr<Player> playerPtr);
    void TryFishing(std::vector<Fish> fishPool);
    void RecalculateTotalRarity(std::vector<Fish> fishPool);
};



#endif //FISHING_H
