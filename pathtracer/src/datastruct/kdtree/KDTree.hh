#pragma once

#include <memory>
#include "KDNode.hh"
#include "../../scene_elements/Polygon.hh"
#include "../../scene_elements/Ray.hh"

class KDTree {
public:
    KDTree() = default;

    explicit KDTree(std::vector<Polygon> &polygons);

    void getIntersectionList(const Ray &ray, std::vector<Polygon *> &resultList);

    void printPrefix();

    std::shared_ptr<KDNode> root_ = nullptr;

};
