#pragma once

#include <SFML/Graphics.hpp>

class Game
{
public:
	Game(int width, int height, const char* title);
private:
	sf::RenderWindow m_window;
};