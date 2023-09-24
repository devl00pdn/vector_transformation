#include <gtest/gtest.h>
#include "quaternion.h"


TEST(quternion, defaul_constructor) {
    quaternion::Quaternion quat;

    EXPECT_EQ(quat.GetReal(), 1.0);
    EXPECT_EQ(quat.GetImaginary().x, 0.0);
    EXPECT_EQ(quat.GetImaginary().y, 0.0);
    EXPECT_EQ(quat.GetImaginary().z, 0.0);
}

TEST(quternion, constructor_components) {
    quaternion::Quaternion quat(2, 2, 2, 2);
    EXPECT_EQ(quat.GetReal(), 2.0);
    EXPECT_EQ(quat.GetImaginary().x, 2.0);
    EXPECT_EQ(quat.GetImaginary().y, 2.0);
    EXPECT_EQ(quat.GetImaginary().z, 2.0);
}

TEST(quternion, constructor_copy) {
    quaternion::Quaternion quat(2., 2., 2., 2.);
    quaternion::Quaternion quat_new(quat);
    EXPECT_EQ(quat_new.GetReal(), 2.0);
    EXPECT_EQ(quat_new.GetImaginary().x, 2.0);
    EXPECT_EQ(quat_new.GetImaginary().y, 2.0);
    EXPECT_EQ(quat_new.GetImaginary().z, 2.0);
}

TEST(quternion, operator_assignment_copy) {
    quaternion::Quaternion quat(2., 2., 2., 2.);
    quaternion::Quaternion quat_new;
    quat_new = quat;
    EXPECT_EQ(quat_new.GetReal(), 2.0);
    EXPECT_EQ(quat_new.GetImaginary().x, 2.0);
    EXPECT_EQ(quat_new.GetImaginary().y, 2.0);
    EXPECT_EQ(quat_new.GetImaginary().z, 2.0);
}

TEST(quternion, constructor_rpy) {
    float                  rad_90deg = static_cast<float>(M_PI_2);
    quaternion::Quaternion quat_from_rpy(rad_90deg, rad_90deg, rad_90deg);
    EXPECT_NEAR(quat_from_rpy.GetReal(), 0.7071068, 0.001);
    EXPECT_NEAR(quat_from_rpy.GetImaginary().x, 0, 0.001);
    EXPECT_NEAR(quat_from_rpy.GetImaginary().y, 0.7071068, 0.001);
    EXPECT_NEAR(quat_from_rpy.GetImaginary().z, 0, 0.001);

    quaternion::Quaternion<double> quatd_from_rpy(rad_90deg, rad_90deg,
                                                  rad_90deg);
    EXPECT_NEAR(quatd_from_rpy.GetReal(), 0.7071068, 0.001);
    EXPECT_NEAR(quatd_from_rpy.GetImaginary().x, 0, 0.001);
    EXPECT_NEAR(quatd_from_rpy.GetImaginary().y, 0.7071068, 0.001);
    EXPECT_NEAR(quatd_from_rpy.GetImaginary().z, 0, 0.001);
}


// Quaternion<Type> operator*(const Quaternion<Type>& q_rhv) {
//
// }
TEST(quternion, operator_multiply) {
    quaternion::Quaternion quat1(0.7071068f, 0.f, 0.7071068f, 0.f);
    quaternion::Quaternion quat2(-0.7071068f, 0.f, -0.7071068f, 0.f);

    auto q_product = quat1 * quat2;
    EXPECT_NEAR(q_product.GetReal(), 0, 0.001);
    EXPECT_NEAR(q_product.GetImaginary().x, 0, 0.001);
    EXPECT_NEAR(q_product.GetImaginary().y, -1, 0.001);
    EXPECT_NEAR(q_product.GetImaginary().z, 0, 0.001);
}


TEST(quternion, Multiply) {
    quaternion::Quaternion quat(2., 2., 2., 2.);
    quat.Multiply(2);
    EXPECT_EQ(quat.GetReal(), 4.0);
    EXPECT_EQ(quat.GetImaginary().x, 4.0);
    EXPECT_EQ(quat.GetImaginary().y, 4.0);
    EXPECT_EQ(quat.GetImaginary().z, 4.0);
}


TEST(quternion, GetInverse) {
    quaternion::Quaternion quat(0.7071068f, 0.f, 0.7071068f, 0.f);
    auto                   inv_q = quat.GetInverse();
    EXPECT_NEAR(inv_q.GetReal(), 0.7071068, 0.001);
    EXPECT_NEAR(inv_q.GetImaginary().x, 0, 0.001);
    EXPECT_NEAR(inv_q.GetImaginary().y, -0.7071068, 0.001);
    EXPECT_NEAR(inv_q.GetImaginary().z, 0, 0.001);
}


TEST(quternion, GetNormalize) {
    quaternion::Quaternion quat(2., 2., 2., 2.);
    auto                   norm_q = quat.GetNormalize();
    EXPECT_NEAR(norm_q.GetReal(), 0.5, 0.001);
    EXPECT_NEAR(norm_q.GetImaginary().x, 0.5, 0.001);
    EXPECT_NEAR(norm_q.GetImaginary().y, 0.5, 0.001);
    EXPECT_NEAR(norm_q.GetImaginary().z, 0.5, 0.001);
}


TEST(quternion, Normalize) {
    quaternion::Quaternion quat(2., 2., 2., 2.);
    quat.Normalize();
    EXPECT_NEAR(quat.GetReal(), 0.5, 0.001);
    EXPECT_NEAR(quat.GetImaginary().x, 0.5, 0.001);
    EXPECT_NEAR(quat.GetImaginary().y, 0.5, 0.001);
    EXPECT_NEAR(quat.GetImaginary().z, 0.5, 0.001);
}


TEST(quternion, Clone) {
    quaternion::Quaternion quat(2., 2., 2., 2.);
    auto                   quat_cloned = quat.Clone();
    EXPECT_EQ(quat_cloned.GetReal(), 2.0);
    EXPECT_EQ(quat_cloned.GetImaginary().x, 2.0);
    EXPECT_EQ(quat_cloned.GetImaginary().y, 2.0);
    EXPECT_EQ(quat_cloned.GetImaginary().z, 2.0);
}

TEST(quternion, GetReal) {
    quaternion::Quaternion quat(2., 3., 4., 5.);
    EXPECT_EQ(quat.GetReal(), 2.0);
}

TEST(quternion, GetImaginary) {
    quaternion::Quaternion quat(2., 3., 4., 5.);
    EXPECT_EQ(quat.GetImaginary().x, 3.0);
    EXPECT_EQ(quat.GetImaginary().y, 4.0);
    EXPECT_EQ(quat.GetImaginary().z, 5.0);
}
