#include "Entity.hpp"

#include <memory>
#include <tuple>

Entity::Entity(const std::string &tag, size_t id)
    : m_tag(tag)
    , m_id(id)
    , m_alive(true)
    , m_components()
{

}

const std::string &Entity::tag() { return m_tag; }

void Entity::destroy() { m_alive = false; }

const bool& Entity::isAlive()
{
  return m_alive;
}
