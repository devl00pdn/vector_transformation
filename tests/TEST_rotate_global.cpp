#include <gtest/gtest.h>
#include "rotor.h"

using namespace vector_transformation;

TEST(Rotate_global, roll) {
    float         deg90_rad = static_cast<float>(M_PI_2);
    Rotate_global rotate(deg90_rad, 0, 0);
    using v_t = decltype(rotate)::v_t;

    v_t  v{0, 1, 0};
    auto result = rotate.Vector(v);

    EXPECT_NEAR(result.x, 0.0, 0.001);
    EXPECT_NEAR(result.y, 0.0, 0.001);
    EXPECT_NEAR(result.z, -1.0, 0.001);

    rotate = {-deg90_rad, 0, 0};
    result = rotate.Vector(v);

    EXPECT_NEAR(result.x, 0.0, 0.001);
    EXPECT_NEAR(result.y, 0.0, 0.001);
    EXPECT_NEAR(result.z, 1.0, 0.001);
}


TEST(Rotate_global, pitch) {
    float         deg90_rad = static_cast<float>(M_PI_2);
    Rotate_global rotate(0, deg90_rad, 0);
    using v_t = decltype(rotate)::v_t;

    v_t  v{1, 0, 0};
    auto result = rotate.Vector(v);

    EXPECT_NEAR(result.x, 0.0, 0.001);
    EXPECT_NEAR(result.y, 0.0, 0.001);
    EXPECT_NEAR(result.z, 1.0, 0.001);

    rotate = {0, -deg90_rad, 0};
    result = rotate.Vector(v);

    EXPECT_NEAR(result.x, 0.0, 0.001);
    EXPECT_NEAR(result.y, 0.0, 0.001);
    EXPECT_NEAR(result.z, -1.0, 0.001);
}


TEST(Rotate_global, yaw) {
    float         deg90_rad = static_cast<float>(M_PI_2);
    Rotate_global rotate(0, 0, deg90_rad);
    using v_t = decltype(rotate)::v_t;

    v_t  v{1, 0, 0};
    auto result = rotate.Vector(v);

    EXPECT_NEAR(result.x, 0.0, 0.001);
    EXPECT_NEAR(result.y, 1.0, 0.001);
    EXPECT_NEAR(result.z, 0.0, 0.001);

    rotate = {0, 0, -deg90_rad};
    result = rotate.Vector(v);

    EXPECT_NEAR(result.x, 0.0, 0.001);
    EXPECT_NEAR(result.y, -1.0, 0.001);
    EXPECT_NEAR(result.z, 0.0, 0.001);
}


TEST(Rotate_global, roll_pitch_yaw) {
    float         deg90_rad = static_cast<float>(M_PI_2);
    Rotate_global rotate(deg90_rad, -deg90_rad, deg90_rad);
    using v_t = decltype(rotate)::v_t;

    v_t  v{1, 0, 1};
    auto result = rotate.Vector(v);

    EXPECT_NEAR(result.x, -1.0, 0.001);
    EXPECT_NEAR(result.y, 0.0, 0.001);
    EXPECT_NEAR(result.z, -1.0, 0.001);
}
