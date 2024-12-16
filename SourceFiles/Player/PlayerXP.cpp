

#include "Player/PlayerXP.h"

bool PlayerXP::AddXP(int amount)
{
    currentXP += amount;

    if (currentXP >= level * 100)
    {
        LevelUp();

        return true;
    }

    return false;
}

void PlayerXP::LevelUp()
{
    level++;
    currentXP = 0;
}