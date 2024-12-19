#ifndef ROD_H
#define ROD_H
#include "RodType.h"
#include <nlohmann/json.hpp>

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


namespace nlohmann
{
    template <>
    struct adl_serializer<Rod>
    {
        static void to_json(json& j, const Rod& rod) {
            j = json{{"type", rod.Type}, {"price", rod.Price}, {"fishMultiplier", rod.FishMultiplier}};
        }

        static void from_json(const json& j, Rod& rod) {
            rod.Type = j.at("type").get<RodType>();
            rod.Price = j.at("price").get<int>();
            rod.FishMultiplier = j.at("fishMultiplier").get<int>();
        }
    };
}



#endif //ROD_H
