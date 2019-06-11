#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/string.hpp>
#include <chrono>
#include <PathtraceImageFactory.hh>
#include "Executor.hh"
#include "Vector3D.hh"
#include "Polygon.hh"
#include "ObjectFileParser.hh"
#include "Camera.hh"
#include "SaveManager.hh"
#include "SceneFactory.hh"
#include "KDTree.hh"
#include "Stats.hh"
#include "AllMaterialContainer.hh"
#include "Scene.hh"
#include "PhongImageFactory.hh"

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
    map_actions[jobType::raytrace] = [](Executor &executor) { executor.renderSceneRaytracing(); };
    map_actions[jobType::pathtrace] = [](Executor &executor) { executor.renderScenePathtracing(); };
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

void Executor::renderSceneRaytracing() {
    if (!loaded_) {
        std::cout << "Please load a json.\n";
        return;
    }
    Scene scene;
    PhongImageFactory Pif= PhongImageFactory(sceneSave_.getCamera(),scene);
    std::cout << "Building Tree..." << std::endl;
    ObjectFileParser::fromAllObjsToObjStruct(sceneSave_.getObjects(), scene);
    scene.allLights = sceneSave_.getAllLights();
    std::cout << "Done." << std::endl;
    std::cout << "Rendering Image..." << std::endl;
    Pif.compute();
    std::cout << "Done." << std::endl;
    Pif.dumpToPpm(save_path);
}

void Executor::renderScenePathtracing() {
    if (!loaded_) {
        std::cout << "Please load a json.\n";
        return;
    }
    Scene scene;
    std::cout << "Building Tree..." << std::endl;
    ObjectFileParser::fromAllObjsToObjStruct(sceneSave_.getObjects(), scene);
    scene.allLights = sceneSave_.getAllLights();
    std::cout << "Done." << std::endl;
    PathtraceImageFactory Ptif = PathtraceImageFactory(sceneSave_.getCamera(), scene);
    std::cout << "Rendering Image..." << std::endl;
    Ptif.compute();
    std::cout << "Done." << std::endl;
    Ptif.dumpToPpm(save_path);
}





