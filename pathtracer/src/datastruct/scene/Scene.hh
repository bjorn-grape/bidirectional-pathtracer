#pragma once
#include "../kdtree/KDTree.hh"
#include "../materials/AllMaterialContainer.hh"

struct Scene {
    KDTree kdtree;
    void AddMaterials(const std::vector<Material>& materials);
private:
    AllMaterialContainer allMaterialContainer; // simple storage shouldn't be changed
};
