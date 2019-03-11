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

Vector3D<float> centerGravityPolygons(std::vector<Polygon> polygons) {
    Vector3D<float> gravityCenter = Vector3D<float>();
    for (size_t i = 0; i < polygons.size(); ++i) {
        gravityCenter += polygons[i].meanVertices();
        std::cout << "center of gravity of " << i << " is " << polygons[i].meanVertices() << "\n";
    }
    gravityCenter /= polygons.size();
    return gravityCenter;
}

void cameraHit() {
    auto list = ObjectFileParser::fromPathToObjStruct("cube.obj");
    Camera c = Camera(1.f, Vector2D<unsigned>(512, 512), Vector3D(1.5f, .7f, -1.f), Vector3D(-0.5f, 0.f, 1.f), 90);
    std::cout << "started compute" << std::endl;
    c.computeImage(list);
    std::cout << "end compute" << std::endl;
    c.dumpImageToPpm("test.ppm");
}

void cameraHit2() {
    auto list = ObjectFileParser::fromPathToObjStruct("cube.obj");
    Camera c = Camera(1.f, Vector2D<unsigned>(512, 512), Vector3D(0.f, 0.0f, -2.f), Vector3D(0.f, 0.f, 1.f), 60);
    std::cout << "started compute" << std::endl;
    c.computeImage(list);
    std::cout << "end compute" << std::endl;
    c.dumpImageToPpm("test2.ppm");
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
    map_actions[jobType::binaryTest] = [](Executor &executor) { cameraHit(); };
    map_actions[jobType::binaryTest2] = [](Executor &executor) { cameraHit2(); };
    map_actions[jobType::buildscene] = [](Executor &executor) { executor.sceneSave_ = SceneFactory::BuildScene(); };
    map_actions[jobType::executeScene] = [](Executor &executor) { executor.renderScene(); };
    map_actions[jobType::executeSceneKDTree] = [](Executor &executor) { executor.renderSceneKDTree(); };
    map_actions[jobType::buildTreeAndPrint] = [](Executor &executor){ executor.createTree();};
}

void Executor::createTree() {
    auto list = ObjectFileParser::fromAllObjsToObjStruct(sceneSave_.getObjects());
    auto tree = KDTree(list);
    tree.printPrefix();
}


void Executor::renderScene() {
    auto list = ObjectFileParser::fromAllObjsToObjStruct(sceneSave_.getObjects());
    std::cout << "start making image..." << std::endl;
    auto start = std::chrono::system_clock::now();
    sceneSave_.getCamera().computeImage(list);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
    std::cout << "Done." << std::endl;
    sceneSave_.getCamera().dumpImageToPpm(save_path);
}

void Executor::setSavePath(const std::string &path) {
    save_path = path;
}

void Executor::renderSceneKDTree() {
    auto list = ObjectFileParser::fromAllObjsToObjStruct(sceneSave_.getObjects());
    std::cout << "start building KDTree..." << std::endl;
    auto start = std::chrono::system_clock::now();

    KDTree tree(list);

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "Done." << std::endl;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

    std::cout << "Done." << std::endl;
    std::cout << "start making image..." << std::endl;

    start = std::chrono::system_clock::now();
    sceneSave_.getCamera().computeImage(tree);

    end = std::chrono::system_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Done." << std::endl;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

    Stats::AABBvsRay.printInfos();
    sceneSave_.getCamera().dumpImageToPpm(save_path);
}





