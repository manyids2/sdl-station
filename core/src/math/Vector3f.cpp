#include "math/Vector3f.h"
#include "math/Misc.h"

Vector3f &Vector3f::round() {
  mX = (float)(int)(mX + 0.5f);
  mY = (float)(int)(mY + 0.5f);
  mZ = (float)(int)(mZ + 0.5f);

  return *this;

} // round

Vector3f &Vector3f::lerp(const Vector3f &_start, const Vector3f &_end,
                         const float _fraction) {
  mX = Math::lerp(_start.x(), _end.x(), _fraction);
  mY = Math::lerp(_start.y(), _end.y(), _fraction);
  mZ = Math::lerp(_start.z(), _end.z(), _fraction);

  return *this;

} // lerp
