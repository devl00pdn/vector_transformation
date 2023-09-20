#pragma once

#include <stdint.h>

namespace quaternion {

template <class T = float>
class Quaternion {
public:
    using Type = T;

    Quaternion() = default;
    Quaternion(Type w, Type i, Type j, Type k) : w_(w), i_(i), j_(j), k_(k) {}
    Quaternion(const Quaternion<Type>& q_rhv)
            : w_(q_rhv.w_), i_(q_rhv.i_), j_(q_rhv.j_), k_(q_rhv.k_) {}
    Quaternion<Type>& operator=(const Quaternion<Type>& q_rhv) {
        w_ = q_rhv.w_;
        i_ = q_rhv.i_;
        j_ = q_rhv.j_;
        k_ = q_rhv.k_;
    }


private:
    Type w_{1};
    Type i_{0};
    Type j_{0};
    Type k_{0};
};
}  // namespace quaternion
