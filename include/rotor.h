#pragma once

#include "quaternion.h"

namespace vector_transformation {

/**
 * Rotate 3D vector on angles around global axis as three independent turns.
 * Uses quaternions under the hood.
 * Global axis orientation:
 * X(roll) - forward
 * Y(pitch) - right
 * Z(yaw) - down
 * @tparam Type - float(default), double
 */

template <class Type = float>
class Rotate_global {
public:
    using q_t = quaternion::Quaternion<Type>;
    using v_t = typename q_t::v3_t;

    Rotate_global() = delete;

    /**
     * @param roll_rad - angle of rotation around x axis, rad
     * @param pitch_rad - angle of rotation around y axis, rad
     * @param yaw_rad - angle of rotation around z axis, rad
     */
    Rotate_global(Type roll_rad, Type pitch_rad, Type yaw_rad)
            : roll_rad_{roll_rad}, pitch_rad_{pitch_rad}, yaw_rad_{yaw_rad} {
        q_roll_ = q_t{-roll_rad, 0, 0};
        q_roll_.Normalize();
        q_roll_inv_ = q_roll_.GetInverse();
        q_pitch_    = q_t{0, -pitch_rad, 0};
        q_pitch_.Normalize();
        q_pitch_inv_ = q_pitch_.GetInverse();
        q_yaw_       = q_t{0, 0, yaw_rad};
        q_yaw_.Normalize();
        q_yaw_inv_ = q_yaw_.GetInverse();
    }

    /**
     * Rotate 3D vector on angles around global axis as three independent turns.
     * @param base - input vector
     * @return rotated vector
     */
    v_t Vector(const v_t& base) {
        q_t q_base(0, base.x, base.y, base.z);
        q_t q_tmp = q_roll_ * q_base * q_roll_inv_;
        q_tmp     = q_pitch_ * q_tmp * q_pitch_inv_;
        q_tmp     = q_yaw_ * q_tmp * q_yaw_inv_;
        return q_tmp.GetImaginary();
    }

private:
    q_t q_roll_;
    q_t q_roll_inv_;
    q_t q_pitch_;
    q_t q_pitch_inv_;
    q_t q_yaw_;
    q_t q_yaw_inv_;

    /// For pretty debug
    Type roll_rad_{0};
    Type pitch_rad_{0};
    Type yaw_rad_{0};
};


template <class Type>
Rotate_global(Type, Type, Type) -> Rotate_global<float>;

template <class Type, Type...>
Rotate_global(Type...) -> Rotate_global<float>;

}  // namespace vector_transformation
