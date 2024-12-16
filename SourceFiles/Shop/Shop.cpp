#include "Shop/Shop.h"
#include <iostream>
#include "Text/TextFormatting.h"


Shop::Shop(std::shared_ptr<Player> playerPtr) : player(playerPtr)
{
    rods =
    {
            {RodType::Gold, 10, 2},
            {RodType::Silver, 800, 3},
            {RodType::Steel, 1200, 4}
    };
}

void Shop::ShowShop() const
{
    std::cout << "\n" << TextFormatting::Bold << TextFormatting::Yellow << "--- Shop ---\n" << TextFormatting::Reset;
    std::cout << "Your balance: " << player->Coins.GetCoins() << " coins\n";

    ShowOptions();
}

void Shop::ShowOptions() const
{
    std::cout << "\nOptions:\n";
    std::cout << "0. Go back\n";
    std::cout << "1. Buy rod\n";

    std::cout << TextFormatting::Bold << TextFormatting::Yellow << "-----------------\n" << TextFormatting::Reset;

    std::cout << "Your choice: ";
    int choice;
    std::cin >> choice;

    switch (choice)
    {
        case 0:
            std::cout << "\nYou left the shop.\n";
        break;
        case 1:
            ShowRodOptions();
            break;
        default:
            std::cout << "Invalid choice.\n";
            break;
    }
}

void Shop::ShowRodOptions() const
{
    std::cout << "\n" << TextFormatting::Bold << TextFormatting::Yellow << "--- Fishing rods ---\n" << TextFormatting::Reset;

    int count = 1;

    for (const auto& [type, price, multiplier] : rods)
    {
        std::cout << count << ". " << Rod::ToString(type) << " rod (" << price << " coins)\n";
        ++count;
    }

    std::cout << "\n0. Go back\n";

    std::cout << TextFormatting::Bold << TextFormatting::Yellow << "-------------\n" << TextFormatting::Reset;

    std::cout << "Your choice: ";

    bool isRunning = true;

    while (isRunning)
    {
        std::cout << "Your choice: ";
        int choice;
        std::cin >> choice;

        if (choice >= 1 && choice <= count - 1)
        {
            int cost = rods[choice - 1].Price;

            if (!player->Coins.HasEnoughCoins(cost))
            {
                std::cout << "You don't have enough coins to buy this rod.\n";
                continue;
            }

            player->Coins.DecreaseCoins(cost);
            player->ChangeRodInInventory(rods[choice - 1]);

            std::cout << "You bought a " << Rod::ToString(rods[choice - 1].Type) << " rod for " << cost << " coins.\n";
        }
        else if (choice == 0)
        {
            isRunning = false;
            ShowShop();
        }
        else
        {
            std::cout << "Invalid choice.\n";
        }
    }

}


