#include "../../HeaderFiles/Text/Menu.h"
#include <iostream>
#include <limits>
#include "Text/TextFormatting.h"


void Menu::AddOption(const std::string &description, std::function<void()> action)
{
    options[++optionCount] = {description, action};
}

void Menu::ShowMenu()
{
    bool running = true;
    while (running)
    {
        std::cout << TextFormatting::Bold << TextFormatting::Blue << "\n--- Fishing game menu ---\n" << TextFormatting::Reset;

        for (const auto& [key, value] : options)
        {
            std::cout << key << ". " << value.description << "\n";
        }

        std::cout << optionCount + 1 << ". Exit\n";
        std::cout << TextFormatting::Bold << TextFormatting::Blue << "--------------------\n" << TextFormatting::Reset;


        std::cout << "Choose an option: ";

        int choice;

        if (!(std::cin >> choice))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << TextFormatting::Bold << TextFormatting::Red <<"\nInvalid input. Please enter a number.\n" << TextFormatting::Reset;
            continue;
        }


        if (choice == optionCount + 1)
        {
            running = false;
        }
        else if (options.contains(choice))
        {
            options[choice].action();
        }
        else
        {
            std::cout << TextFormatting::Bold << TextFormatting::Red <<"\nInvalid choice.\n" << TextFormatting::Reset;
        }
    }
}