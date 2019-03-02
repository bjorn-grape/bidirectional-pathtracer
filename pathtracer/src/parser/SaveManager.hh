//
// Created by bjorn on 02/03/19.
//

#ifndef PATHTRACER_SAVEMANAGER_HH
#define PATHTRACER_SAVEMANAGER_HH


#include <cereal/types/string.hpp>
#include "../scene_elements/serialized/SceneSave.hh"

class SaveManager {
public:
    static void Save(const std::string &path, const SceneSave &sceneSave);

    static void Load(const std::string &path, SceneSave &sceneSave);
};


#endif //PATHTRACER_SAVEMANAGER_HH
