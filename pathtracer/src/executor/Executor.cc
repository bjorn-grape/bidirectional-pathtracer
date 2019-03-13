#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/string.hpp>
#include <chrono>
#include "Executor.hh"
#include "../scene_elements/fixed_size_vectors/Vector3D.hh"
#include "../scene_elements/Polygon.hh"
#include "../parser/ObjectFileParser.hh"
#include "../scene_elements/serialized/camera/Camera.hh"
#include "../parser/SaveManager.hh"
#include "../factory/SceneFactory.hh"
#include "../datastruct/kdtree/KDTree.hh"
#include "../tools/performances/Stats.hh"
#include "../datastruct/materials/AllMaterialContainer.hh"
#include "../datastruct/scene/Scene.hh"

void Executor::load(const std::string &path) {
    SaveManager::Load(path, sceneSave_);
    loaded_ = true;
}

void Executor::save(const std::string &path) {
    SaveManager::Save(path, sceneSave_);
}

void Executor::setType(Executor::jobType type) {
    type_ = type;
}

void Executor::run() {
    map_actions[type_](*this);
}


Executor::Executor() {
    map_actions[jobType::none] = [](Executor &executor) {};
    map_actions[jobType::buildscene] = [](Executor &executor) { executor.sceneSave_ = SceneFactory::BuildScene(); };
    map_actions[jobType::executeScene] = [](Executor &executor) { executor.renderScene(); };
    map_actions[jobType::buildTreeAndPrint] = [](Executor &executor) { executor.createTreeAndPrint(); };
}

void Executor::createTreeAndPrint() {
    Scene scene;
    ObjectFileParser::fromAllObjsToObjStruct(sceneSave_.getObjects(), scene);
    scene.kdtree.printPrefix();
}


void Executor::setSavePath(const std::string &path) {
    save_path = path;
}

void Executor::renderScene() {
    if (!loaded_) {
        std::cout << "Please load a json.\n";
        return;
    }
    Scene scene;
    std::cout << "Building Tree..." << std::endl;
    ObjectFileParser::fromAllObjsToObjStruct(sceneSave_.getObjects(), scene);
    std::cout << "Done." << std::endl;
    std::cout << "Rendering Image..." << std::endl;
    sceneSave_.getCamera().computeImageRaw(scene.kdtree);
    std::cout << "Done." << std::endl;
    sceneSave_.getCamera().dumpImageToPpm(save_path);
}





