#include "Vec2.hpp"

namespace vec2math {
  double pi = 2 * acos(0.0);
  float pi_flt = 2*acos(0.0f);
}

Vec2::Vec2()
    : _x(0.0), _y(0.0)
      {}

Vec2::Vec2(float x, float y)
    : _x(x), _y(y)
{}

Vec2 Vec2::operator + (const Vec2& head)
{
  return Vec2(_x + head._x, _y + head._y);
}

Vec2 Vec2::operator - (const Vec2& head)
{
  return Vec2(_x - head._x, _y - head._y);
}

Vec2 Vec2::operator * (float val) {
  return Vec2(_x * val, _y * val);
}

float Vec2::MagSquard()
{
  return (_x * _x) + (_y * _y);
}

float Vec2::Mag()
{
  return std::sqrt((_x * _x) + (_y * _y));
}

Vec2 Vec2::Zero()
{
  return Vec2(0.0f, 0.0f);
}

Vec2 Vec2::Normalize() {

  const float mag = Mag();

  if (mag != 0.0f) {
    _x = _x / mag;
    _y = _y / mag;

  } else {
    _x = 0.0f;
    _y = 0.0f;
  }

  return *this;
}

float Vec2::getRad() {

  if (_x != 0.0f)
    return std::atan2(_y, _x);
  else
    return 0.0f;
}

float Vec2::getDegrees() {

  if (_x != 0.0f) {

    const float radians = std::atan2(_y, _x);
    return radians * 180 / vec2math::pi_flt;

  }
  else
    return 0.0f;
}

Vec2& Vec2::deltaTime(size_t fps) {

  if (fps != 0) {

    float _fpsRec = 1.0f / static_cast<float>(fps);
    _x = _x * _fpsRec;
    _y = _y * _fpsRec;

    }

    return *this;
}
