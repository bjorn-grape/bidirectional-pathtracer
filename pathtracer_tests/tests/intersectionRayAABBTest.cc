#include "gtest/gtest.h"

#include "Tools.hh"
#include "Ray.hh"
#include "BoundingBox.hh"

TEST(TestRayAABB, basic) {
    Ray ray = Ray(Vector3D<float>(-2.f, 0.5f,0.f), Vector3D<float>(1.f,0.f,0.f));
    BoundingBox boundingBox = BoundingBox(Vector3D<float>(-1.f,-1.f,-1.f),Vector3D<float>(1.f,1.f,1.f));
    auto result = boundingBox.FasterDoIntersect(ray);
    ASSERT_TRUE(result);
}

TEST(TestRayAABB, basic2) {
    Ray ray = Ray(Vector3D<float>(-2.f, 0.5f, -0.9f), Vector3D<float>(1.f,0.f,0.f));
    BoundingBox boundingBox = BoundingBox(Vector3D<float>(-1.f,-1.f,-1.f),Vector3D<float>(1.f,1.f,1.f));
    auto result = boundingBox.FasterDoIntersect(ray);
    ASSERT_TRUE(result);
}