#pragma once
#include "../kdtree/KDTree.hh"
#include "../materials/AllMaterialContainer.hh"
#include "../../scene_elements/serialized/lights/AllLights.hh"

struct Scene {
    KDTree kdtree;
    void AddMaterials(const std::vector<Material>& materials);
    AllLights allLights;
private:
    AllMaterialContainer allMaterialContainer; // simple storage shouldn't be changed
};
