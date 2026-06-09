#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <memory>
#include <iostream>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>

#include "EntityManager.hpp"
#include "Systems.hpp"


class GameEngine
{
private:

  std::shared_ptr<sf::RenderWindow> m_window;
  
  size_t m_currentFrame;
  SRender m_sRender;
  SInput m_sInput;

  bool m_pause = false;
  
  GameEngine();
  void mainLoop();
  
public:

  void run();
  std::shared_ptr<sf::RenderWindow>& getWindow();
  static GameEngine& instance();


  
};

#endif // GAMEENGINE_H
