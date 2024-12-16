#ifndef ROD_H
#define ROD_H
#include "RodType.h"

struct Rod
{
    RodType Type;
    int Price;
    int FishMultiplier;

    static std::string ToString(RodType type);
};

inline std::string Rod::ToString(RodType type)
{
    switch (type)
    {
        case RodType::Default: return "Default";
        case RodType::Gold: return "Gold";
        case RodType::Silver: return "Silver";
        case RodType::Steel: return "Steel";
        default: return "Unknown";
    }
}

#endif //ROD_H
