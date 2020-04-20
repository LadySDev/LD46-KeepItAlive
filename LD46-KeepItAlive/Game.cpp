#include "Game.h"

Game::Game(int width, int height, const char* title, float scale)
{
	m_window.create(sf::VideoMode(width, height), title, sf::Style::None);

	m_window.setFramerateLimit(30);

	m_scale = scale;

	m_resource = new Resource(m_scale);

	m_characterStates = {"satiated", "hungry", "starved", "dead"};

	m_player = new Player(this);
	m_player->setState(m_characterStates[0]);
	m_player->setAlimentQuantity(10);

	m_children = new Children(this);
	m_children->setState(m_characterStates[0]);
	m_children->setAlimentQuantity(10);

	m_day = 1;
	m_aliment = 40;

	launchMainTitleScene();

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

			processEventCurrentScene(event, mousePosition);
		}

		updateCurrentScene(deltaTime);

		m_window.clear();
		renderCurrentScene(&m_window);
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

std::vector<std::string> Game::getCharacterStates()
{
	return m_characterStates;
}

Player* Game::getPlayer()
{
	return m_player;
}

Children* Game::getChildren()
{
	return m_children;
}

int Game::getDay()
{
	return m_day;
}

void Game::addADay()
{
	m_day = m_day + 1;
}

int Game::getAliment()
{
	return m_aliment;
}

void Game::addAliment(int quantity)
{
	m_aliment = m_aliment + quantity;
}

void Game::launchMainTitleScene()
{
	resetAllScene();
	m_mainTitleScene = new MainTitleScene(this);
}

void Game::launchGameScene()
{
	resetAllScene();
	m_gameScene = new GameScene(this);
}

void Game::processEventCurrentScene(sf::Event event, sf::Vector2f mousePosition)
{
	if (m_mainTitleScene != NULL)
	{
		m_mainTitleScene->processEvent(event, mousePosition);
	}
	else if (m_gameScene != NULL)
	{
		m_gameScene->processEvent(event, mousePosition);
	}
}

void Game::updateCurrentScene(sf::Time deltaTime)
{
	if (m_mainTitleScene != NULL)
	{
		m_mainTitleScene->update(deltaTime);
	}
	else if (m_gameScene != NULL)
	{
		m_gameScene->update(deltaTime);
	}
}

void Game::renderCurrentScene(sf::RenderWindow* window)
{
	if (m_mainTitleScene != NULL)
	{
		m_mainTitleScene->render(window);
	}
	else if (m_gameScene != NULL)
	{
		m_gameScene->render(window);
	}
}

void Game::resetAllScene()
{
	if (m_mainTitleScene != NULL)
	{
		m_mainTitleScene = NULL;
	}
	else if (m_gameScene != NULL)
	{
		m_gameScene = NULL;
	}
}

void Game::close()
{
	m_window.close();
}
