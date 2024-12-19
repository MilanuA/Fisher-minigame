#ifndef SAVELOAD_H
#define SAVELOAD_H
#include "Savable.h"


class SaveLoad
{
    static void LogError(const std::string& message);
public:
    static bool Save(const json &passedData, const std::string& filepath);
    static bool Load(json &loadInto, const std::string& filepath);
};



#endif //SAVELOAD_H
