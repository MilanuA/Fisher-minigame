#ifndef GAME_H
#define GAME_H
#include <vector>

#include "Fishing.h"
#include "Player/Player.h"
#include "Shop/Shop.h"

class Game
{
    std::shared_ptr<Player> player;
    Shop shop;

    std::vector<Fish> fishPool;
    Fishing fishing;

public:
    Game();
    void Start();
    Fish GetFish(FishType fishType);
};

#endif //GAME_H
