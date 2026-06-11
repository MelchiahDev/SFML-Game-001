#include "GameEngine.hpp"
#include "Components.hpp"
#include "Entity.hpp"
#include "EntityManager.hpp"
#include "SFML/System/Vector2.hpp"

GameEngine::GameEngine()
  : m_window(std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "My Game"))
{
  // Do not add runtime code here.
}

void GameEngine::mainLoop()
{
  EntityManager::instance().update();
  m_sInput.run();
  m_sMovement.run();
  m_sRender.run();
  m_currentFrame++;
}

void GameEngine::run()
{
  EntityManager::instance();

  // You can test stuff here.

  const auto& e = EntityManager::instance().addEntity("foo");
  e->addComponent<CShapeCircle>(100.0f);
  e->addComponent<CTransform>().position = Vec2(20.0f,100.0f);
  e->getComponent<CTransform>().velocity = Vec2(1.0f, 1.0f).deltaTime(60);

  const auto &e2 = EntityManager::instance().addEntity("foo");
  e2->addComponent<CShapeRect>(Vec2(30.0f, 50.0f));
  e2->addComponent<CTransform>().position = Vec2(10.f, 50.0f);

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
