#include "Player/PlayerCoins.h"

PlayerCoins::PlayerCoins() : coins(0)
{

}

void PlayerCoins::AddCoins(int amount)
{
    coins += amount;
}

void PlayerCoins::DecreaseCoins(int amount)
{
    coins -= amount;
}
