#include "Game.h"

Game::Game(int width, int height, const char* title)
{
	m_window.create(sf::VideoMode(width, height), title);
	m_window.setFramerateLimit(30);

	m_window.setPosition(sf::Vector2i(-1930, -5));

	while (m_window.isOpen())
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_window.close();
			}
		}

		m_window.clear();
		m_window.display();
	}
}
