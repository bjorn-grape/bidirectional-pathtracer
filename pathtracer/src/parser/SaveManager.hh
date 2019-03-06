#pragma  once

#include <cereal/types/string.hpp>
#include "../scene_elements/serialized/SceneSave.hh"

class SaveManager {
public:
    static void Save(const std::string &path, const SceneSave &sceneSave);

    static void Load(const std::string &path, SceneSave &sceneSave);
};


