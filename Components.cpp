#include "Components.hpp"

CShape::CShape() : shape(std::make_shared<sf::CircleShape>(50.0f)) {}

CName::CName(const std::string& name) : name(name) {}
