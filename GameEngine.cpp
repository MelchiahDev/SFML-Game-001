#include "GameEngine.hpp"
#include "Entity.hpp"
#include "EntityManager.hpp"

GameEngine::GameEngine()
  : m_window(std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "My Game"))
{  
  // Do not add runtime code here.
}

void GameEngine::mainLoop()
{
  EntityManager::instance().update();
  m_sInput.run();
  m_sRender.run();
  m_currentFrame++;
}

void GameEngine::run()
{
  EntityManager::instance();

  // You can test stuff here.

  EntityManager::instance().addEntity("foo");
  // EntityManager::instance().addEntity("foo");
  // EntityManager::instance().addEntity("baz");
  // EntityManager::instance().addEntity("foo");
  EntityManager::instance().update();

  // ...

  while(m_window->isOpen() && !m_pause)
  {
    mainLoop();
  }
}

GameEngine& GameEngine::instance()
{
  static GameEngine instance;
  return instance;
}

std::shared_ptr<sf::RenderWindow>& GameEngine::getWindow()
{
  return m_window;
}
