#ifndef COMPONENT_H
#define COMPONENT_H

#include <memory>
#include <string>

#include "SFML/Graphics/CircleShape.hpp"
#include "Vec2.hpp"


class CTransform
{
public:
  Vec2 position;
  Vec2 velocity;
  CTransform(const Vec2 & p, const Vec2 & v);
};


class CName
{
public:
  std::string name;
  CName(const std::string& name);
};


class CShape
{
public:
  std::shared_ptr<sf::Shape> shape;
  CShape();
};

#endif // COMPONENT_H
