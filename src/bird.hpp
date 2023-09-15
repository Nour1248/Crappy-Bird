#pragma once

#include "pipe.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

namespace fb
{
class bird
{
private:
  // bird texture
  sf::Texture b;
  // bird sprite
  sf::Sprite bs;
  //
  bool released = true;
  // delay after last flap
  float click_time;

  //////////////////////////////////////////////////////////////////////////////////////////

public:
  explicit bird (str path)
  {
    b.create (90, 90);
    if (!b.loadFromFile (path))
      {
        std::cout << "failed to load texture\n";
      }
    bs.setTexture (b);
    bs.scale (1.5, 1.5);
    bs.setPosition (sf::Vector2f ((WIDTH / 2) - 34, (HEIGHT / 2) - 24));
  }

  //////////////////////////////////////////////////////////////////////////////////////////

  void
  animate (sf::Event &event)
  {
    if (event.type == sf::Event::MouseButtonPressed)
      {
        if (event.mouseButton.button == sf::Mouse::Left && released)
          {
            bs.setPosition (bs.getPosition ().x, bs.getPosition ().y - 40.0f);
            released = false;
            click_time = time.asSeconds ();
          }
      }
    else if (event.type == sf::Event::MouseButtonReleased)
      {
        if (event.mouseButton.button == sf::Mouse::Left)
          {
            released = true;
          }
      }
    if (time.asSeconds () > click_time + 0.15f)
      {
        bs.setPosition (bs.getPosition ().x, bs.getPosition ().y + 1.5f);
      }
  }

  //////////////////////////////////////////////////////////////////////////////////////////

  bool
  got_touched (fb::pipe *pipe[])
  {
    for (size_t i = 0; i < fb::pipes_count; i++)
      {
        if (this->bs.getGlobalBounds ().intersects (pipe[i]->get_position ()))
          {
            return true;
          }
      }
    return false;
  }

  //////////////////////////////////////////////////////////////////////////////////////////

  sf::Sprite
  get_sprite ()
  {
    return this->bs;
  }

  //////////////////////////////////////////////////////////////////////////////////////////

  float
  get_spriteX ()
  {
    return this->bs.getGlobalBounds ().left;
  }

  //////////////////////////////////////////////////////////////////////////////////////////

  float
  get_spriteY ()
  {
    return this->bs.getGlobalBounds ().top;
  }
};

} // namespace fb
