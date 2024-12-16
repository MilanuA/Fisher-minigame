#ifndef FISH_H
#define FISH_H
#include <string>

#include "FishType.h"

struct Fish
{
    FishType Fishtype;
    int FishRarity;
    int FishPrice;
    int XP;
    int UnlockLevel;

    static std::string ToString(FishType type);
};


inline std::string Fish::ToString(FishType type)
{
    switch (type)
    {
        case FishType::None: return "Nothing";
        case FishType::Salmon: return "Salmon";
        case FishType::Tuna: return "Tuna";
        case FishType::Shark: return "Shark";
        case FishType::Goldfish: return "Goldfish";
        case FishType::Herring: return "Herring";
        case FishType::Perch: return "Perch";
        case FishType::Swordfish: return "Swordfish";
        case FishType::Cod: return "Cod";
        case FishType::Mackerel: return "Mackerel";
        case FishType::Trout: return "Trout";
        case FishType::Halibut: return "Halibut";
        case FishType::Snapper: return "Snapper";
        case FishType::Grouper: return "Grouper";
        case FishType::MahiMahi: return "MahiMahi";

        default: return "Nothing";
    }
}

#endif //FISH_H
