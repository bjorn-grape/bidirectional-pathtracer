#include "SceneFactory.hh"
#include "Colors.hh"

SceneSave SceneFactory::BuildScene() {
    SceneSave save;
    AllLights allLights;

    allLights.ambient_lights_.emplace_back(AmbientLight(3.f, Colors::RED));
    allLights.directional_lights_.emplace_back(DirectionalLight(Vector3D(1.f, 0.f, 0.f), 1.0f, Colors::BLUE));
    save.setAllLights(allLights);

    Camera camera = Camera(Vector2D<unsigned>(512, 512), Vector3D(0.f, 0.0f, -6.f), Vector3D(0.f, 0.f, 1.f), 60);
    save.setCamera(camera);

    ObjectPaths objectPath("cornell2.mtl", "cornell2.obj", Vector3D(0.f, 0.f, 0.f));
    save.addObject(objectPath);

    RenderType rd = RenderType(RenderType::pathtracer, 1, 2, 5, 2, 5);
    save.setRenderType(rd);
    return save;
}
