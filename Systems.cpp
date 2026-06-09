#include <SFML/Graphics/RenderWindow.hpp>

#include "Systems.hpp"
#include "EntityManager.hpp"
#include "GameEngine.hpp"

void SInput::run()
{
  auto& window = GameEngine::instance().getWindow();

  while (window->pollEvent(m_event))
	{
		if (m_event.type == sf::Event::Closed)
		{
			window->close();
		}
	}
}


void SRender::run()
{
  auto& window = GameEngine::instance().getWindow();

  window->clear(sf::Color::Black);
  // draw everything here

  for(auto& e: EntityManager::instance().getEntities())
    {
      window->draw(*e->cShape->shape);
    }
  
  // end of render frame here
  window->display();
}
