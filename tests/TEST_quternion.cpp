#include <gtest/gtest.h>
#include "gtest/gtest.h"
#include "quaternion.h"


template <class T>
struct A {
    A(T a) {
        v = a;
    }  // #2
    T v;
};

template <class T>
A(T) -> A<float>;

TEST(quternion, defaul_constructor) {
    quaternion::Quaternion quat;

    EXPECT_EQ(quat.GetReal(), 1.0);
    EXPECT_EQ(quat.GetImaginary().x, 0.0);
    EXPECT_EQ(quat.GetImaginary().y, 0.0);
    EXPECT_EQ(quat.GetImaginary().z, 0.0);
}

TEST(quternion, constructor_components) {
    quaternion::Quaternion quat(2., 2., 2., 2.);
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


//
// Quaternion<Type>& operator=(const Quaternion<Type>& q_rhv) {
//    w_ = q_rhv.w_;
//    x_ = q_rhv.x_;
//    y_ = q_rhv.y_;
//    z_ = q_rhv.z_;
//    return *this;
//}
TEST(quternion, operator_assignment_copy) {
    quaternion::Quaternion quat(2., 2., 2., 2.);
    quaternion::Quaternion quat_new;
}

//
// Quaternion(Type x_ang_rad, Type y_ang_rad, Type z_ang_rad) {

//}
TEST(quternion, constructor_rpy) {}


// Quaternion<Type> operator*(const Quaternion<Type>& q_rhv) {
//
// }
TEST(quternion, operator_multiply) {}


//
// Quaternion<Type>& Multiply(Type gain) {

//}

TEST(quternion, Multiply) {}


// Quaternion<Type> GetInverse() const {}

TEST(quternion, GetInverse) {}


// Quaternion<Type>& GetNormalize() const {

//}

TEST(quternion, GetNormalize) {}


// void Normalize() {
//
// }

TEST(quternion, Normalize) {}


// Quaternion<Type> Clone() const {
// }

TEST(quternion, Clone) {}


TEST(quternion, GetReal) {}

TEST(quternion, GetImaginary) {}
