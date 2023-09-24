### Vector transformation

---

Rotate 3D vector in NED global coordinate system on roll, pitch, yaw angles.  
All turns are independent.  
Quaternions under the hood.

#### Benefits

- Extremely simple
- Header only
- Depend on only c++17 (type_traits)
- Embedded friendly. No allocations / exceptions
- optimized calculations. Only multiplication, addition when rotation angles is static

#### Example

``` 
#include "rotor.h"

/// rotaion object -> roll around X axis on  90 deg 
Rotate_global rotate(M_PI_2, 0, 0);

using v_t = decltype(rotate)::v_t;
///    x, y, z
v_t  v{0, 1, 0};

auto result = rotate.Vector(v);
/// result.x -> 0
/// result.y -> 0
/// result.z -> -1


```