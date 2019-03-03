#include "SceneFactory.hh"
#include "../color/Colors.hh"

SceneSave SceneFactory::BuildScene() {
    SceneSave save;
    AllLights allLights;

    allLights.ambient_lights_.emplace_back(AmbientLight(3.f, Colors::RED));
    allLights.directional_lights_.emplace_back(DirectionalLight(Vector3D(1.f, 0.f, 0.f), 1.0f, Colors::BLUE));
    save.setAllLights(allLights);

    Camera camera = Camera(1.f, Vector2D(512, 512), Vector3D(0.f, 0.0f, -2.f), Vector3D(0.f, 0.f, 1.f), 60);
    save.setCamera(camera);

    ObjectPaths objectPath("cube.mtl", "cube.obj", Vector3D(0.f, 0.f, 0.f));
    save.addObject(objectPath);

    return save;
}
