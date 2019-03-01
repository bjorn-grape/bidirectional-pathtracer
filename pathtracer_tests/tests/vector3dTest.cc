
#include "gtest/gtest.h"

#include "Vector3D.hh"


TEST(TestVector3, constructorEquals) {
    auto a = Vector3D(0, 0, 0);
    auto b = Vector3D<int>();
    EXPECT_EQ(a, b);
}

TEST(TestVector3, plusVector) {
    auto a = Vector3D(1, 1, 1);
    auto b = Vector3D(2, 2, 2);
    a = a + a;
    EXPECT_EQ(a, b);
}

TEST(TestVector3, plusElementRight) {
    auto a = Vector3D(1, 1, 1);
    auto b = Vector3D(2, 2, 2);
    a = a + 1;
    EXPECT_EQ(a, b);
}

TEST(TestVector3, plusElementLeft) {
    auto a = Vector3D(1, 1, 1);
    auto b = Vector3D(2, 2, 2);
    a = 1 + a;
    EXPECT_EQ(a, b);
}

TEST(TestVector3, plusEqualVector) {
    auto a = Vector3D(1, 1, 1);
    auto b = Vector3D(2, 2, 2);
    a += a;
    EXPECT_EQ(a, b);
}

TEST(TestVector3, plusEqualElement) {
    auto a = Vector3D(1, 1, 1);
    auto b = Vector3D(2, 2, 2);
    a += 1;
    EXPECT_EQ(a, b);
}

TEST(TestVector3, minusVector) {
    auto a = Vector3D(1, 1, 1);
    auto b = Vector3D(2, 2, 2);
    b = b - a;
    EXPECT_EQ(a, b);
}

TEST(TestVector3, minusElement) {
    auto a = Vector3D(1, 1, 1);
    auto b = Vector3D(2, 2, 2);
    b = b - 1;
    EXPECT_EQ(a, b);
}

TEST(TestVector3, minusEqualVector) {
    auto a = Vector3D(1, 1, 1);
    auto b = Vector3D(2, 2, 2);
    b -= a;
    EXPECT_EQ(a, b);
}

TEST(TestVector3, minusEqualElement) {
    auto a = Vector3D(1, 1, 1);
    auto b = Vector3D(2, 2, 2);
    b -= 1;
    EXPECT_EQ(a, b);
}

TEST(TestVector3, timesVector) {
    auto a = Vector3D(2, 2, 2);
    auto b = Vector3D(2, 2, 2);
    auto c = Vector3D(4, 4, 4);
    EXPECT_EQ(a * b, c);
}

TEST(TestVector3, timesElementLeft) {
    auto a = Vector3D(2, 2, 2);
    auto c = Vector3D(4, 4, 4);
    EXPECT_EQ(2 * a, c);
}

TEST(TestVector3, timesElementRight) {
    auto a = Vector3D(2, 2, 2);
    auto c = Vector3D(4, 4, 4);
    EXPECT_EQ(a * 2, c);
}

TEST(TestVector3, timesEqualVector) {
    auto a = Vector3D(2, 2, 2);
    auto b = Vector3D(2, 2, 2);
    auto c = Vector3D(4, 4, 4);
    a *= b;
    EXPECT_EQ(a, c);
}

TEST(TestVector3, timesEqualElement) {
    auto a = Vector3D(2, 2, 2);
    auto c = Vector3D(4, 4, 4);
    a *= 2;
    EXPECT_EQ(a, c);
}


TEST(TestVector3, divideVector) {
    auto a = Vector3D(2, 2, 2);
    auto b = Vector3D(2, 2, 2);
    auto c = Vector3D(1, 1, 1);
    EXPECT_EQ(a / b, c);
}

TEST(TestVector3, divideElement) {
    auto a = Vector3D(2, 2, 2);
    auto c = Vector3D(1, 1, 1);
    EXPECT_EQ(a / 2, c);
}


TEST(TestVector3, divideEqualVector) {
    auto a = Vector3D(2, 2, 2);
    auto b = Vector3D(2, 2, 2);
    auto c = Vector3D(1, 1, 1);
    a /= b;
    EXPECT_EQ(a, c);
}

TEST(TestVector3, divideEqualElement) {
    auto a = Vector3D(2, 2, 2);
    auto c = Vector3D(1, 1, 1);
    a /= 2;
    EXPECT_EQ(a, c);
}

TEST(TestVector3, dotProduct) {
    auto a = Vector3D(1, 2, 3);
    auto b = Vector3D(2, 4, 6);
    EXPECT_EQ(a.dotproduct(b), 28);
}

TEST(TestVector3, crossProduct) {
    auto a = Vector3D(1, 2, 3);
    auto b = Vector3D(6, 5, 7);
    EXPECT_EQ(a.crossproduct(b), Vector3D(-1, 11, -7));
}

TEST(TestVector3, floatVectorEqualityTolerance) {
    Vector3D<float> expected = Vector3D<float>(0.f, 1, 0);
    Vector3D<float> got = Vector3D<float>(0, 1 + 10e-8f, 0);

    bool plop = expected == got;

    EXPECT_EQ(expected, got);
}


TEST(TestVector3, rotateOnXnothing) {
    auto expected = Vector3D<float>(1, 0, 0);

    auto got = Vector3D<float>(1, 0, 0);
    got.rotate(Vector2D<float>(2 * constants::PI , 0.f));

    EXPECT_EQ(expected, got);
}



TEST(TestVector3, rotateOnXsimple) {
    auto expected = Vector3D<float>(0, -1, 0);

    auto got = Vector3D<float>(0, 1, 0);
    got.rotate(Vector2D<float>(constants::PI , 0.f));

    EXPECT_EQ(expected, got);
}

TEST(TestVector3, rotateOnZsimple2) {
    auto expected = Vector3D<float>(0, 0, -1);

    auto got = Vector3D<float>(0, 0, 1);
    got.rotate(Vector2D<float>(-constants::PI/2.f , 0.f));

    EXPECT_EQ(expected, got);
}
