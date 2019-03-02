//
// Created by bjorn on 02/03/19.
//

#include <sstream>
#include <cereal/archives/json.hpp>
#include "SaveManager.hh"

void SaveManager::Save(const std::string &path, const SceneSave &sceneSave) {
    std::ofstream file(path);
    if (!file.is_open()) {
        std::cerr << "Cannot write Scene Save on " << path << std::endl;
        return;
    }
    cereal::JSONOutputArchive dumpToJson(file);
    dumpToJson(CEREAL_NVP(sceneSave));
    file << "\n}\n";

}

void SaveManager::Load(const std::string &path, SceneSave &sceneSave) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Cannot read Scene Save on " << path << std::endl;
        return;
    }
    cereal::JSONInputArchive loadToJson(file);
    loadToJson(sceneSave);
}
