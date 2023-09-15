#pragma once

#include <SFML/Graphics.hpp>

#define WIDTH 500
#define HEIGHT 800

namespace fb
{

typedef std::string str;

bool STATE{ true };

static uint64_t distance_x = 0;
static uint64_t distance_y = 0;
static uint64_t pipes_count = 100;

sf::Clock clock;
sf::Time time;

inline int
handle_events (sf::Event const &event, sf::Window &window, bool &state)
{
  switch (event.type)
    {
    case sf::Event::Closed:
      state = false;
      window.close ();
      break;
    default:
      break;
    }
  return 0;
}

} // namespace fb
