#include <SFML/Graphics/RenderWindow.hpp>

#include "Components.hpp"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/System/Vector2.hpp"
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

/**
   At first, this system must set the position of each entity.
   Then, it should do otherupdate if new game logic dictates
   that some entities update their position.
*/
void SMovement::run()
{
  for(auto& e: EntityManager::instance().getEntities())
    {
      if(e->hasComponent<CTransform>())
	{
	  float x = e->getComponent<CTransform>().position._x;
	  float y = e->getComponent<CTransform>().position._y;

	  if(e->hasComponent<CShapeCircle>())
	    {
	      sf::Shape& shape = *e->getComponent<CShapeCircle>().shape;
	      shape.setPosition(sf::Vector2f(x, y));
	    }

	  if(e->hasComponent<CShapeRect>())
	    {
	      sf::Shape& shape = *e->getComponent<CShapeRect>().shape;
	      shape.setPosition(sf::Vector2f(x, y));
	    }

	  float deltaX = e->getComponent<CTransform>().velocity._x;
	  float deltaY = e->getComponent<CTransform>().velocity._y;

	  e->getComponent<CTransform>().position._x += deltaX;
	  e->getComponent<CTransform>().position._y += deltaY;
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
      if(e->hasComponent<CShapeCircle>())
	{
	  window->draw(*e->getComponent<CShapeCircle>().shape);	  
	}

      if(e->hasComponent<CShapeRect>())
	{
	  window->draw(*e->getComponent<CShapeRect>().shape);
	}
    }
  
  // end of render frame here
  window->display();
}
