#include "Components.hpp"
#include "SFML/System/Vector2.hpp"

CTransform::CTransform() : position(Vec2()), velocity(Vec2()) {}
CTransform::CTransform(const Vec2 &p, const Vec2 &v) : position(p) , velocity(v) {}

CName::CName(const std::string &name) : name(name) {}

CShapeCircle::CShapeCircle(float radius)
  : radius(radius)
  , shape(std::make_shared<sf::CircleShape>(radius)) {}

CShapeRect::CShapeRect(Vec2 size)
  : shape(std::make_shared<sf::RectangleShape>(sf::Vector2f(size._x, size._y))) {}
