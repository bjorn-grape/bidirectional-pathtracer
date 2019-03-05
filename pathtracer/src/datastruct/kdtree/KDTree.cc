#include <memory>

#include "KDTree.hh"

void KDTree::build(std::vector<Polygon> &polygons) {
    if (root_ != nullptr) {
        std::cerr << "KDTree not empty !" << std::endl;
        return;
    }
    root_ = std::make_shared<KDNode>();

    auto min_coord = Vector3D<float>(INFINITY, INFINITY, INFINITY);
    auto max_coord = Vector3D<float>(-INFINITY, -INFINITY, -INFINITY);
    for (const auto &polygon: polygons) {
        auto mean = polygon.meanVertices();
        min_coord = min_coord.minOfTwoCoordinates(mean);
        max_coord = max_coord.maxOfTwoCoordinates(mean);
    }

    BoundingBox b = BoundingBox(min_coord, max_coord);
    root_.get()->build(polygons.begin(), polygons.end(), b);
}
