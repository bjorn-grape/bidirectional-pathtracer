#include "Scene.hh"

void Scene::AddMaterials(const std::vector<Material> &materials) {
    allMaterialContainer.addMaterials(materials);
}
