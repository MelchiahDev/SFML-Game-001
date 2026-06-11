#ifndef VEC2_H
#define VEC2_H

#include <cmath>
#include <numbers>

class Vec2
{
public:
  float _x;
  float _y;

  static Vec2 Zero();

  Vec2();
  Vec2(float x, float y);
  Vec2 operator + (const Vec2& head);
  Vec2 operator - (const Vec2 &head);
  Vec2 operator * (float val);
  float MagSquard();
  float Mag();
  Vec2 Normalize();
  float getRad();
  float getDegrees();
  Vec2& deltaTime(size_t fps);
};

#endif // VEC2_H
