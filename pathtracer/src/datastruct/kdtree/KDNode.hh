#pragma once

#include <memory>
#include <ostream>
#include "../../scene_elements/fixed_size_vectors/Vector3D.hh"
#include "../../scene_elements/Polygon.hh"
#include "../box/BoundingBox.hh"
#include "../SplitAxis.hh"
#include "../../scene_elements/Ray.hh"
#include "../../parser/AllPolygonContainer.hh"

class KDNode {
public:
    KDNode(std::vector<unsigned> &indexList, AllPolygonContainer &polygons,
            const BoundingBox &box, unsigned depth);
    void printInfix(unsigned depth, bool isleft);
    void getIntersectionList(const Ray& ray, std::unordered_set<unsigned> &resultSet);

private:
    float splitValue_ = 0.f;
    SplitAxis::Axis splitAxis_ = SplitAxis::none;
    std::shared_ptr<BoundingBox> box_ = nullptr;
    std::shared_ptr<KDNode> left_ = nullptr;
    std::shared_ptr<KDNode> right_ = nullptr;
    std::shared_ptr<std::vector<unsigned>> polygons_;
};


