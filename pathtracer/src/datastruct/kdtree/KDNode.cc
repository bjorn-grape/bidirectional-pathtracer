#include "KDNode.hh"

void KDNode::build(vectorIterator it1, vectorIterator it2, const BoundingBox &box) {
    switch (box.GetLargestDimension())
    {
        case SplitAxis::X :
            std::sort(it1,it2);

    }

}
