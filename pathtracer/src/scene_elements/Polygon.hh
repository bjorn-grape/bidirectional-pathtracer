//
// Created by bjorn on 25/02/19.
//

#ifndef PATHTRACER_TRIANGLE_HH
#define PATHTRACER_TRIANGLE_HH


#include <vector>
#include "fixed_size_vectors/Vector3D.hh"
#include "fixed_size_vectors/Vector2D.hh"

class Polygon {

    
private:
    std::vector<Vector3D<float>> vectices;
    std::vector<Vector3D<float>> normals;
    std::vector<Vector2D<float>> texcoords;
    std::vector<Vector3D<uint8_t>> colors;
};


#endif //PATHTRACER_TRIANGLE_HH
