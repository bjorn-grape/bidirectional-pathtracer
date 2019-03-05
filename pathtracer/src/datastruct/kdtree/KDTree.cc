#include <memory>

#include "KDTree.hh"

void KDTree::build(const std::vector<Polygon>& polygons) {
    if (root_ != nullptr) {
        std::cerr << "KDTree not empty !" << std::endl;
        return;
    }
    root_= std::make_shared<KDNode>();
    root_.get()->build(polygons.begin(), polygons.end());
}
