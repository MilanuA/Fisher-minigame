#ifndef SHOP_H
#define SHOP_H
#include <memory>
#include <vector>

#include "Player/Player.h"

class Shop
{
    std::shared_ptr<Player> player;

    void ShowOptions() const;
    void ShowRodOptions() const;

    std::vector<Rod> rods;

public:
    void ShowShop() const;
    Shop(const std::shared_ptr<Player> &playerPtr);
};



#endif //SHOP_H
