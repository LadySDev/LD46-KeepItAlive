#include "Game.h"

Game::Game(int width, int height, const char* title, float scale)
{
	m_window.create(sf::VideoMode(width, height), title, sf::Style::None);

	m_window.setFramerateLimit(30);

	m_scale = scale;

	m_resource = new Resource(m_scale);

	m_mainTitleScene = new MainTitleScene(this);

	sf::Clock clock;
	while (m_window.isOpen())
	{
		sf::Time deltaTime = clock.getElapsedTime();

		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_window.close();
			}

			sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(m_window));

			m_mainTitleScene->processEvent(event, mousePosition);
		}

		m_mainTitleScene->update(deltaTime);

		m_window.clear();
		m_mainTitleScene->render(&m_window);
		m_window.display();
	}
}

Resource* Game::getResource()
{
	return m_resource;
}

sf::Vector2f Game::getSize()
{
	return sf::Vector2f(m_window.getSize().x, m_window.getSize().y);
}

float Game::getScale()
{
	return m_scale;
}

void Game::close()
{
	m_window.close();
}
