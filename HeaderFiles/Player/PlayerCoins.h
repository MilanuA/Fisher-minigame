#ifndef PLAYERCOINS_H
#define PLAYERCOINS_H
#include "SavingLoading/Savable.h"

class PlayerCoins : public Savable
{
    int coins;

public:
    PlayerCoins();

    int GetCoins() const { return coins; }

    void AddCoins(const int &amount);
    void DecreaseCoins(const int &amount);
    bool HasEnoughCoins(const int &amount) const { return coins >= amount; }

    json SaveJson() const override;

    void LoadJson(const json &j) override;
};



#endif //PLAYERCOINS_H
