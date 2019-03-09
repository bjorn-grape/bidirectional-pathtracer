
#pragma once

#include "AllPolygonContainer.hh"
#include "../scene_elements/Polygon.hh"
#include <iostream>





inline Polygon AllPolygonContainer::at(unsigned i) const {
    if (i >= polygons_.size())
        throw std::invalid_argument("Out of bounds!");
    return polygons_[i];
}

inline Polygon AllPolygonContainer::operator[](unsigned i) const {
    return polygons_[i];
}

inline std::vector<unsigned> AllPolygonContainer::getAllindexes() const {
    auto vect = std::vector<unsigned int>();
    vect.reserve(polygons_.size());
    for (unsigned i = 0; i < polygons_.size(); ++i) {
        vect.push_back(i);
    }
    return vect;
}

inline std::size_t AllPolygonContainer::size() const {
    return polygons_.size();
}



