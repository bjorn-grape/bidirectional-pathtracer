#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/string.hpp>
#include <chrono>
#include "Executor.hh"
#include "../scene_elements/fixed_size_vectors/Vector3D.hh"
#include "../scene_elements/Polygon.hh"
#include "../parser/AllPolygonContainer.hh"
#include "../scene_elements/serialized/camera/Camera.hh"
#include "../parser/SaveManager.hh"
#include "../factory/SceneFactory.hh"
#include "../datastruct/kdtree/KDTree.hh"
#include "../tools/performances/Stats.hh"

Vector3D<float> centerGravityPolygons(std::vector<Polygon> polygons) {
    Vector3D<float> gravityCenter = Vector3D<float>();
    for (size_t i = 0; i < polygons.size(); ++i) {
        gravityCenter += polygons[i].meanVertices();
        std::cout << "center of gravity of " << i << " is " << polygons[i].meanVertices() << "\n";
    }
    gravityCenter /= polygons.size();
    return gravityCenter;
}


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
    map_actions[jobType::executeSceneKDTree] = [](Executor &executor) { executor.renderSceneKDTree(); };
    map_actions[jobType::buildTreeAndPrint] = [](Executor &executor) { executor.createTree(); };
}

void Executor::createTree() {
    auto polygonContainer = AllPolygonContainer(sceneSave_.getObjects());
    auto tree = KDTree(polygonContainer);
    tree.printPrefix();
}


void Executor::renderScene() {
    auto polygonContainer = AllPolygonContainer(sceneSave_.getObjects());
    std::cout << "start making image..." << std::endl;
    auto start = std::chrono::system_clock::now();
    sceneSave_.getCamera().computeImage(polygonContainer);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
    std::cout << "Done." << std::endl;
    sceneSave_.getCamera().dumpImageToPpm(save_path);
}

void Executor::setSavePath(const std::string &path) {
    save_path = path;
}

void Executor::renderSceneKDTree() {
    auto polygonContainer = AllPolygonContainer(sceneSave_.getObjects());
    std::cout << "start building KDTree..." << std::endl;
    KDTree tree(polygonContainer);
    std::cout << "Done." << std::endl;
    std::cout << "start making image..." << std::endl;
    auto start = std::chrono::system_clock::now();
    sceneSave_.getCamera().computeImage(tree, polygonContainer);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Done." << std::endl;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
    Stats::AABBvsRay.printInfos();
    sceneSave_.getCamera().dumpImageToPpm(save_path);
}





