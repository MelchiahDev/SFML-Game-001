#ifndef COMPONENT_H
#define COMPONENT_H

#include <memory>
#include <string>

#include "SFML/Graphics/Shape.hpp"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/System/Vector2.hpp"

#include "Vec2.hpp"

struct Component {
public:
  bool has;
};

class CTransform: public Component
{
public:
  Vec2 position;
  Vec2 velocity;
  CTransform();
  CTransform(const Vec2 &p, const Vec2 &v);
};

class CName: public Component
{
public:
  std::string name;
  CName() = default;
  CName(const std::string& name);
};

class CShape : public Component {
public:
  CShape() = default;
};

class CShapeCircle: public CShape
{
public:
  float radius;
  std::shared_ptr<sf::CircleShape> shape;
  CShapeCircle() = default;
  CShapeCircle(float radius);
};

class CShapeRect: public CShape
{
public:
  float side;
  std::shared_ptr<sf::RectangleShape> shape;
  CShapeRect() = default;
  CShapeRect(Vec2 size);
};

#endif // COMPONENT_H
