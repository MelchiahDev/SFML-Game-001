#ifndef ENTITY_H
#define ENTITY_H

#include <cstddef>
#include <memory>
#include <tuple>

#include "Components.hpp"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

typedef std::tuple
< CTransform,
  CName,
  CShapeCircle,
  CShapeRect > ComponentsTuple;

class Entity {
private:

  const size_t m_id = 0;
  const std::string m_tag = "Default";
  bool m_alive;

  // components
  ComponentsTuple m_components;

  Entity(const std::string &tag, size_t id);

public:

  const std::string &tag();
  void destroy();
  const bool &isAlive();

  template <typename T, typename... TArgs>
  T& addComponent(TArgs&&... mArgs)
  {
    T& component = getComponent<T>();
    component = T(std::forward<TArgs>(mArgs)...);
    component.has = true;
    return component;
  }

  template <typename T>
  void removeComponent()
  {
    getComponent<T>() = T();
  }

  template <typename T>
  bool hasComponent()
  {
    return getComponent<T>().has;
  }

  template <typename T>
  T& getComponent()
  {
    return std::get<T>(m_components);
  }

  friend class EntityManager;
};

#endif // ENTITY_H
