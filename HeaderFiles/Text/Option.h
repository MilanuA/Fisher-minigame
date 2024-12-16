//
// Created by alex on 14.12.24.
//

#ifndef OPTION_H
#define OPTION_H
#include <functional>
#include <string>


struct Option
{
    std::string description;
    std::function<void()> action;
};



#endif //OPTION_H
