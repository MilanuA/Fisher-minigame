//
// Created by alex on 14.12.24.
//

#include "../../HeaderFiles/Text/Menu.h"

#include <iostream>

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
        std::cin >> choice;

        if (choice == optionCount + 1)
        {
            running = false;
        }
        else if (options.count(choice))
        {
            options[choice].action();
        }
        else
        {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}
