#pragma once

#include <cmath>
#include <cstdint>
#include <type_traits>

namespace quaternion {

template <class T                                                  = float,
          std::enable_if_t<std::is_floating_point<T>::value, bool> = true>
class Quaternion {
public:
    using Type = T;

    struct v3_t {
        Type x{0};  ///> forward
        Type y{0};  ///> left
        Type z{0};  ///> up
    };

    Quaternion() = default;
    Quaternion(Type w, Type x, Type y, Type z) : w_(w), x_(x), y_(y), z_(z) {}
    Quaternion(const Quaternion<Type>& q_rhv)
            : w_(q_rhv.w_), x_(q_rhv.x_), y_(q_rhv.y_), z_(q_rhv.z_) {}

    Quaternion<Type>& operator=(Quaternion<Type>& q_rhv) {
        w_ = q_rhv.w_;
        x_ = q_rhv.x_;
        y_ = q_rhv.y_;
        z_ = q_rhv.z_;
        return *this;
    }
    Quaternion<Type>& operator=(Quaternion<Type>&& q_rhv) {
        w_ = q_rhv.w_;
        x_ = q_rhv.x_;
        y_ = q_rhv.y_;
        z_ = q_rhv.z_;
        return *this;
    }

    /**
     * Quaternion from euler angles.
     * Describe rotate motion as a sequence of three  continues turn: x,y,z
     * axis. Each turn around axis changes local coordinate system.
     * Base coordinate system is:
     * x - forward
     * y - left
     * z - up
     * @param x_ang_rad - rotation angle around x axis
     * @param y_ang_rad - rotation angle around y axis
     * @param z_ang_rad - rotation angle around z axis
     */
    Quaternion(Type x_ang_rad, Type y_ang_rad, Type z_ang_rad) {
        Type cr, sr, cp, sp, cy, sy;

        if constexpr (std::is_same_v<Type, double>) {
            cr = cos(x_ang_rad * 0.5);
            sr = sin(x_ang_rad * 0.5);
            cp = cos(y_ang_rad * 0.5);
            sp = sin(y_ang_rad * 0.5);
            cy = cos(z_ang_rad * 0.5);
            sy = sin(z_ang_rad * 0.5);
        } else {
            cr = cosf(x_ang_rad * 0.5f);
            sr = sinf(x_ang_rad * 0.5f);
            cp = cosf(y_ang_rad * 0.5f);
            sp = sinf(y_ang_rad * 0.5f);
            cy = cosf(z_ang_rad * 0.5f);
            sy = sinf(z_ang_rad * 0.5f);
        }

        w_ = cr * cp * cy + sr * sp * sy;
        x_ = sr * cp * cy - cr * sp * sy;
        y_ = cr * sp * cy + sr * cp * sy;
        z_ = cr * cp * sy - sr * sp * cy;
    }

    Quaternion<Type> operator*(const Quaternion<Type>& q_rhv) {
        Type w = (w_ * q_rhv.w_) - (x_ * q_rhv.x_) - (y_ * q_rhv.y_) -
                 (z_ * q_rhv.z_);
        Type x = (w_ * q_rhv.x_) + (x_ * q_rhv.w_) + (y_ * q_rhv.z_) -
                 (z_ * q_rhv.y_);
        Type y = (w_ * q_rhv.y_) - (x_ * q_rhv.z_) + (y_ * q_rhv.w_) +
                 (z_ * q_rhv.x_);
        Type z = (w_ * q_rhv.z_) + (x_ * q_rhv.y_) - (y_ * q_rhv.x_) +
                 (z_ * q_rhv.w_);
        return Quaternion<Type>(w, x, y, z);
    }

    Quaternion<Type>& Multiply(Type gain) {
        w_ *= gain;
        x_ *= gain;
        y_ *= gain;
        z_ *= gain;
        return *this;
    }

    Quaternion<Type> GetInverse() const {
        Quaternion<Type> q_conj{w_, -x_, -y_, -z_};
        Type             q_pow = w_ * w_ + x_ * x_ + y_ * y_ + z_ * z_;
        if (q_pow > 0.0) {
            return q_conj.Multiply(1.f / q_pow);
        }
        return {1, 0, 0, 0};
    }

    Quaternion<Type> GetNormalize() const {
        auto q = Clone();
        q.Normalize();
        return q;
    }

    void Normalize() {
        Type magnitude = sqrt(w_ * w_ + x_ * x_ + y_ * y_ + z_ * z_);
        if (magnitude > 0.) {
            w_ /= magnitude;
            x_ /= magnitude;
            y_ /= magnitude;
            z_ /= magnitude;
        }
    }

    Quaternion<Type> Clone() const {
        return {w_, x_, y_, z_};
    }

    v3_t GetImaginary() const {
        return {x_, y_, z_};
    }

    Type GetReal() {
        return w_;
    }

private:
    Type w_{1};
    Type x_{0};
    Type y_{0};
    Type z_{0};
};

template <class Type>
Quaternion(Type, Type, Type, Type) -> Quaternion<float>;

template <class Type>
Quaternion(Type, Type, Type) -> Quaternion<float>;

template <class Type, Type...>
Quaternion(Type...) -> Quaternion<float>;

}  // namespace quaternion
