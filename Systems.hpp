#ifndef SYSTEMS_H
#define SYSTEMS_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>


class System
{
public:
  virtual void run() = 0;
};


class SInput : public System
{
private:
  sf::Event m_event;
public:
  void run() override;
};

class SMovement : public System
{
public:
  void run() override;
};

class SRender: public System
{
public:
  void run() override;
};


#endif // SYSTEMS_H
