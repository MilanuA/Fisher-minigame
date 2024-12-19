#ifndef FISH_H
#define FISH_H
#include <string>
#include <nlohmann/json.hpp>
#include "FishType.h"

struct Fish
{
    FishType Fishtype;
    int FishRarity;
    int FishPrice;
    int XP;
    int UnlockLevel;

    static std::string ToString(FishType type);
    static FishType FromString(const std::string& type);
};

namespace nlohmann
{
    template <>
    struct adl_serializer<FishType> {
        static void to_json(json& j, const FishType& fishType) {
            j = Fish::ToString(fishType);
        }

        static void from_json(const json& j, FishType& fishType) {
            fishType = Fish::FromString(j.get<std::string>());
        }
    };
}


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

inline FishType Fish::FromString(const std::string& str)
{
    if (str == "Nothing") return FishType::None;
    if (str == "Salmon") return FishType::Salmon;
    if (str == "Tuna") return FishType::Tuna;
    if (str == "Shark") return FishType::Shark;
    if (str == "Goldfish") return FishType::Goldfish;
    if (str == "Herring") return FishType::Herring;
    if (str == "Perch") return FishType::Perch;
    if (str == "Swordfish") return FishType::Swordfish;
    if (str == "Cod") return FishType::Cod;
    if (str == "Mackerel") return FishType::Mackerel;
    if (str == "Trout") return FishType::Trout;
    if (str == "Halibut") return FishType::Halibut;
    if (str == "Snapper") return FishType::Snapper;
    if (str == "Grouper") return FishType::Grouper;
    if (str == "MahiMahi") return FishType::MahiMahi;

    return FishType::None;
}

#endif //FISH_H
