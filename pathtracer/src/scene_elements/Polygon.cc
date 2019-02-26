//
// Created by bjorn on 25/02/19.
//

#include "Polygon.hh"


const std::vector<Vector3D<float>> &Polygon::getVectices_() const {
    return vertices_;
}

const std::vector<Vector3D<float>> &Polygon::getNormals_() const {
    return normals_;
}

const std::vector<Vector2D<float>> &Polygon::getTexcoords_() const {
    return texcoords_;
}

const std::vector<Vector3D<uint8_t>> &Polygon::getColors_() const {
    return colors_;
}

bool Polygon::isValid() {
    return vertices_.size() > 2;
}

bool Polygon::isTriangle() {
    return vertices_.size() == 3;
}

void Polygon::add(const Vector3D<float> &vextex, const Vector3D<float> &normal,
                  const Vector2D<float> &texcoord, const Vector3D<uint8_t> &color) {
    vertices_.emplace_back(vextex);
    normals_.emplace_back(normal);
    texcoords_.emplace_back(texcoord);
    colors_.emplace_back(color);
}

std::ostream &operator<<(std::ostream &os, const Polygon &polygon) {
    for (int i = 0; i < polygon.size(); ++i) {
        os << "v" << i << ": " << polygon.vertices_[i]
           << " n" << i << ": " << polygon.normals_[i]
           << " t" << i << ": " << polygon.texcoords_[i]
           << " color" << i << ": " << polygon.colors_[i]
           << "\n";
    }
    return os;
}

size_t Polygon::size() const {
    return vertices_.size();
}
