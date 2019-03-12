#pragma once
#include "../kdtree/KDTree.hh"
#include "../materials/AllMaterialContainer.hh"

struct Scene {
    KDTree kdtree;
    AllMaterialContainer allMaterialContainer;
};
