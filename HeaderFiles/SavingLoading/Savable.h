#ifndef SAVABLE_H
#define SAVABLE_H
#include <nlohmann/json_fwd.hpp>

using json = nlohmann::json;

class Savable
{

public:
    virtual ~Savable() = default;

    virtual json SaveJson() const = 0;
    virtual void LoadJson(const json& j) = 0;
};



#endif //SAVABLE_H
