#pragma once

#include "quaternion.h"

namespace vector_transformation {

template <class Type = float>
class Rotate_global {
public:
    using q_t = quaternion::Quaternion<Type>;
    using v_t = typename q_t ::v3_t;

    Rotate_global(float roll_rad, float pitch_rad, float yaw_rad)
            : roll_rad_{roll_rad}, pitch_rad_{pitch_rad}, yaw_rad_{yaw_rad} {
        q_roll_  = q_t{roll_rad, 0, 0};
        q_pitch_ = q_t{0, pitch_rad, 0};
        q_yaw_   = q_t{0, 0, yaw_rad};
    }

    v_t vector(v_t base) {
        q_t q_base(0, base.x, base.y, base.z);
        q_t q_tmp = q_roll_ * q_base * q_roll_.get_inverse();
        q_tmp     = q_pitch_ * q_tmp * q_pitch_.get_inverse();
        q_tmp     = q_yaw_ * q_tmp * q_yaw_.get_inverse();
        return q_tmp.get_vector();
    }

private:
    q_t   q_roll_;
    q_t   q_pitch_;
    q_t   q_yaw_;
    float roll_rad_{0};
    float pitch_rad_{0};
    float yaw_rad_{0};
};
}  // namespace vector_transformation
