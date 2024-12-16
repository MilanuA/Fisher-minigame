#ifndef MENU_H
#define MENU_H
#include <functional>
#include <map>
#include <string>

#include "Option.h"


class Menu
{
    std::map<int, Option> options;
    int optionCount = 0;

public:
    void AddOption(const std::string& description, std::function<void()> action);
    void ShowMenu();
};



#endif //MENU_H
