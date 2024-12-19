#ifndef SAVINGPATHS_H
#define SAVINGPATHS_H
#include <string>


class SavingPaths
{
    static void EnsureSaveDirectoryExists(const std::string& directory);

public:
    static  std::string GetSaveFilePath(const std::string& className);
    static bool HasSaveFile(const std::string& className);
};



#endif //SAVINGPATHS_H
