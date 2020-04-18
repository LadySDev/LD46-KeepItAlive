#pragma once

#include <SFML/Graphics.hpp>
#include "Resource.h"

class Game
{
public:
	Game(int width, int height, const char* title);
private:
	sf::RenderWindow m_window;
	Resource* m_resource;
};