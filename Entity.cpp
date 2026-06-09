#include "Entity.hpp"
#include "Components.hpp"
#include <memory>

Entity::Entity(const std::string& tag, size_t id)
  : m_tag(tag)
  , m_id(id)
  , cShape(std::make_shared<CShape>())
{

}

const std::string &Entity::tag() { return m_tag; }

void Entity::destroy() { m_alive = false; }

const bool& Entity::isAlive()
{
  return m_alive;
}
