#include "EntityManager.hpp"
#include "Entity.hpp"
#include <algorithm>
#include <memory>

// This is meant to implement Delayed Effects.
void EntityManager::update()
{
  /* Add all entities in m_toAdd to the main one m_entities.
     In addition, they have to be added to m_entityMap as well. */
  for(auto e : m_toAdd)
    {
      m_entities.push_back(e);
      m_entityMap[e->tag()].push_back(e);
    }

  /* If entity is marked as dead, remove it from main entities vec.
     In addition, remove from m_entityMap as well. */

  auto retItrVals = std::remove_if(m_entities.begin(), m_entities.end(),
		 [](std::shared_ptr<Entity> e)
		 {
		   return !(e->isAlive()) ? true : false;
		 });

  m_entities.erase(retItrVals, m_entities.end());
  
    
  // Clear all entities in m_toAdd to have only newer added ones.
  m_toAdd.clear();
}

std::shared_ptr<Entity> EntityManager::addEntity(const std::string& tag)
{
  auto e = std::shared_ptr<Entity>(new Entity(tag, m_totalEntities++));
  m_toAdd.push_back(e);
 
  return e;
}


EntityVec& EntityManager::getEntities()
{
  return m_entities;
}

const EntityVec &EntityManager::getEntities(const std::string &tag)
{
  return m_entityMap[tag];
}

EntityManager& EntityManager::instance()
{
  static EntityManager instance;
  return instance;
}
