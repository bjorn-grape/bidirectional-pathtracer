#include "SceneFactory.hh"
#include "../color/Colors.hh"

SceneSave SceneFactory::BuildScene() {
    SceneSave save;
    AllLights allLights;

    allLights.ambient_lights_.emplace_back(AmbientLight(3.f, Colors::RED));
    allLights.directional_lights_.emplace_back(DirectionalLight(Vector3D(1.f, 0.f, 0.f), 1.0f, Colors::BLUE));
    save.setAllLights(allLights);

    Camera camera = Camera(1.f, Vector2D(512, 512), Vector3D(0.f, 0.0f, -6.f), Vector3D(0.f, 0.f, 1.f), 60);
    save.setCamera(camera);

    ObjectPaths objectPath("cube.mtl", "cube.obj", Vector3D(0.f, 0.f, 0.f));
    ObjectPaths objectPath2("cube.mtl", "cube.obj", Vector3D(0.3f, 0.3f, 0.3f));
    ObjectPaths objectPath3("cube.mtl", "cube.obj", Vector3D(0.5f, 0.5f, 0.5f));
    save.addObject(objectPath);
    save.addObject(objectPath2);
    save.addObject(objectPath3);

    return save;
}
