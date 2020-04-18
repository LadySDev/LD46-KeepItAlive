#include "MainTitleScene.h"
#include <iostream>

MainTitleScene::MainTitleScene(Game* game)
{
	m_game = game;
	
	sf::Vector2f size = sf::Vector2f(250.f * m_game->getScale(), 250.f * m_game->getScale());
	sf::Vector2f position = sf::Vector2f(m_game->getSize().x / 2, m_game->getSize().y / 2);
	sf::Vector2f origin = sf::Vector2f(size.x / 2, size.y / 2);
	m_panel = new MainTitlePanel(m_game, size, position, origin);
}

void MainTitleScene::processEvent(sf::Event event, sf::Vector2f mousePosition)
{
	m_panel->processEvent(event, mousePosition);
}

void MainTitleScene::update(sf::Time deltaTime)
{
	m_panel->update(deltaTime);
}

void MainTitleScene::render(sf::RenderWindow* window)
{
	m_panel->render(window);
}
