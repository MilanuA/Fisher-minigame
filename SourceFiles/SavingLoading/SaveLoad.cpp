#include "../HeaderFiles/SavingLoading/SaveLoad.h"

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

void SaveLoad::LogError(const std::string &message)
{
    std::cerr << "ERROR: " << message << std::endl;
}

bool SaveLoad::Save(const json &passedData, const std::string &filepath)
{
    try
    {
        std::ofstream file(filepath);

        if (!file.is_open()) return false;

        file << passedData.dump(2);
        file.flush();
        file.close();
        return true;

    } catch (const std::ios_base::failure& e) {
        LogError("File I/O error during saving: " + std::string(e.what()));
        return false;
    } catch (const nlohmann::json::exception& e) {
        LogError("JSON error during saving: " + std::string(e.what()));
        return false;
    } catch (const std::exception& e) {
        LogError("General error during saving: " + std::string(e.what()));
        return false;
    } catch (...) {
        LogError("Unknown error during saving");
        return false;
    }
}

bool SaveLoad::Load(json &loadInto, const std::string &filepath)
{
    try
    {
        std::ifstream file(filepath);

        if (!file.is_open()) return false;

        file >> loadInto;

        file.close();

        return true;

    } catch (const std::ios_base::failure& e) {
        LogError("File I/O error during saving: " + std::string(e.what()));
        return false;
    } catch (const nlohmann::json::exception& e) {
        LogError("JSON error during saving: " + std::string(e.what()));
        return false;
    } catch (const std::exception& e) {
        LogError("General error during saving: " + std::string(e.what()));
        return false;
    } catch (...) {
        LogError("Unknown error during saving");
        return false;
    }
}
