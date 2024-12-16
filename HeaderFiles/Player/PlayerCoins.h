#ifndef PLAYERCOINS_H
#define PLAYERCOINS_H

class PlayerCoins
{

    int coins;

public:
    PlayerCoins();

    int GetCoins() const { return coins; }

    void AddCoins(int amount);
    void DecreaseCoins(int amount);
    bool HasEnoughCoins(int amount) const { return coins >= amount; }
};



#endif //PLAYERCOINS_H
