#include <iostream>
#include "quaternion.h"
#include "rotor.h"

int main() {
    /// Ось Х - вперед / Ось Y - вправо / Ось Z - вниз
    /// Положительный угол поворота - по часовой стрелки по направлению оси

    /// Ротор поворота вокруг оси Х на 180 градусов и вокруг оси z на 90
    vector_transformation::Rotate_global r(3.14, 0, 3.14 / 2);

    /// Поворот еденичного вектора  0 1 0 -> получаем вектор 1 0 0
    auto v = r.vector({0, 1, 0});
    return 0;
}
