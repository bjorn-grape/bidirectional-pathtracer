#pragma once

#include <memory>
#include "KDNode.hh"
#include "../../scene_elements/Polygon.hh"
#include "../../scene_elements/Ray.hh"

class KDTree {
public:

    explicit KDTree(std::vector<Polygon>& polygons);

    void getIntersectionList(Ray ray);

    void printPrefix();
    std::shared_ptr<KDNode> root_ = nullptr;

};
