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

void Executor::saveScene(const std::string &path) {
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
    map_actions[jobType::build_scene] = [](Executor &executor) { executor.sceneSave_ = SceneFactory::BuildScene(); };
    map_actions[jobType::render_scene] = [](Executor &executor) { executor.renderScene(); };
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
    PhongImageFactory Pif = PhongImageFactory(sceneSave_.getCamera(), scene, sceneSave_.getRenderType());
    std::cout << "Building Tree..." << std::endl;
    ObjectFileParser::fromAllObjsToObjStruct(sceneSave_.getObjects(), scene);
    scene.allLights = sceneSave_.getAllLights();
    std::cout << "Done." << std::endl;
    std::cout << "Rendering Image..." << std::endl;
    Pif.compute();
    std::cout << "Done." << std::endl;
    Pif.dumpToPpm(save_path);
}

void Executor::renderScene() {
    if (!loaded_) {
        std::cout << "Please load a json.\n";
        return;
    }
    Scene scene;
    std::cout << "Building Tree..." << std::endl;
    ObjectFileParser::fromAllObjsToObjStruct(sceneSave_.getObjects(), scene);
    scene.allLights = sceneSave_.getAllLights();
    std::cout << "Done." << std::endl;

    auto type = sceneSave_.getRenderType();
    auto camera = sceneSave_.getCamera();

    if (type.getType() == RenderType::render_algo::raytracer) {
        auto imFact = PhongImageFactory(camera, scene, type);
        std::cout << "Rendering Image..." << std::endl;
        imFact.compute();
        std::cout << "Done." << std::endl;
        imFact.dumpToPpm(save_path);
    } else if (type.getType() == RenderType::render_algo::pathtracer) {
        auto imFact = PathtraceImageFactory(camera, scene, type);
        std::cout << "Rendering Image..." << std::endl;
        imFact.compute();
        std::cout << "Done." << std::endl;
    }

}





