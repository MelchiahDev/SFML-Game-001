#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <map>
#include <memory>
#include <vector>
#include "Entity.hpp"

typedef std::vector<std::shared_ptr<Entity>> EntityVec;
typedef std::map<std::string, EntityVec> EntityMap;

class EntityManager
{
private:
  EntityVec m_entities;
  EntityVec m_toAdd;
  EntityMap m_entityMap;
  size_t m_totalEntities = 0;
public:
  
  /* If there is any changes in entities, update should take care of
     it to avoid Iterator Invalidation. */
  void update();
  
  std::shared_ptr<Entity> addEntity(const std::string& tag);
  EntityVec& getEntities();
  const EntityVec& getEntities(const std::string& tag);

  static EntityManager& instance();
};

#endif // ENTITYMANAGER_H
