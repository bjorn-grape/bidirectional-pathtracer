//
// Created by bjorn on 04/03/19.
//

#ifndef PATHTRACER_KDNODE_HH
#define PATHTRACER_KDNODE_HH


#include <memory>
#include "../../scene_elements/fixed_size_vectors/Vector3D.hh"
#include "../../scene_elements/Polygon.hh"
#include "../box/BoundingBox.hh"
#include "../SplitAxis.hh"

class KDNode {
public:
    typedef std::vector<Polygon, std::allocator<Polygon>>::iterator vectorIterator;


    std::vector<Polygon> getPolygon(Vector3D<float> origin, Vector3D<float> direction);

    void
    build(vectorIterator it1, vectorIterator it2, const BoundingBox &box);

private:
    float splitValue_ = 0.f;
    SplitAxis::Axis splitAxis_ = SplitAxis::none;
    std::optional<Vector3D<float>> minBox_ = std::nullopt;
    std::optional<Vector3D<float>> maxBox_ = std::nullopt;
    std::shared_ptr<KDNode> left_ = nullptr;
    std::shared_ptr<KDNode> right_ = nullptr;
    std::vector<Polygon> polygons;
};


#endif //PATHTRACER_KDNODE_HH
