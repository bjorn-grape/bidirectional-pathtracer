//
// Created by bjorn on 25/02/19.
//

#pragma once


#include <vector>
#include <ostream>
#include "fixed_size_vectors/Vector3D.hh"
#include "fixed_size_vectors/Vector2D.hh"

class Polygon {
public:
    void add(const Vector3D<float> &vextex, const Vector3D<float> &normal,
             const Vector2D<float> &texcoord, const Vector3D<uint8_t> &color);

    const std::vector<Vector3D<float>> &getVertices() const;

    const std::vector<Vector3D<float>> &getNormals() const;

    const std::vector<Vector2D<float>> &getTexcoords() const;

    const std::vector<Vector3D<uint8_t>> &getColors() const;

    const Vector3D<float> meanVertices() const;

    bool isValid();

    bool isTriangle() const;

    size_t size() const;

    friend std::ostream &operator<<(std::ostream &os, const Polygon &polygon);

private:
    std::vector<Vector3D<float>> vertices_;
    std::vector<Vector3D<float>> normals_;
    std::vector<Vector2D<float>> texcoords_;
    std::vector<Vector3D<uint8_t>> colors_;
};
