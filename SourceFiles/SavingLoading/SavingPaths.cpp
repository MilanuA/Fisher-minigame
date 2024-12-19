#include "../../HeaderFiles/SavingLoading/SavingPaths.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

//Change this to your save directory
const std::string SAVE_DIRECTORY = "SavedGame/";

void SavingPaths::EnsureSaveDirectoryExists(const std::string &directory)
{
    try
    {
        if (!std::filesystem::exists(directory))
        {
            std::filesystem::create_directories(directory);
        }
    } catch (const std::filesystem::filesystem_error& e)
    {
        std::cerr << "Error while creating save directory: " << e.what() << std::endl;
    }
}

std::string SavingPaths::GetSaveFilePath(const std::string &className)
{
    EnsureSaveDirectoryExists(SAVE_DIRECTORY);
    return SAVE_DIRECTORY + className + ".json";
}

bool SavingPaths::HasSaveFile(const std::string &className)
{
    return std::filesystem::exists(GetSaveFilePath(className));
}
