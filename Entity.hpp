#ifndef ENTITY_H
#define ENTITY_H

#include <cstddef>
#include <memory>

#include "Components.hpp"

class Entity
{
private:
  const size_t m_id = 0;
  const std::string m_tag = "Default";
  bool m_alive = true;
  Entity(const std::string& tag, size_t id);
  
  public:
  // components
  std::shared_ptr<CTransform> cTransform;
  std::shared_ptr<CName> cName;
  std::shared_ptr<CShape> cShape;
  
  const std::string& tag();
  void destroy();
  const bool& isAlive();

  friend class EntityManager;
};

#endif // ENTITY_H
