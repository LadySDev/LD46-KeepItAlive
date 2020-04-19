#include "GameSceneDayPanel.h"

GameSceneDayPanel::GameSceneDayPanel(Game* game, GameScene* gameScene)
{
	m_game = game;
	m_gameScene = gameScene;

	m_panelAction = new GameSceneDayActionPanel(m_game, m_gameScene);
}

void GameSceneDayPanel::processEvent(sf::Event event, sf::Vector2f mousePosition)
{
	m_panelAction->processEvent(event, mousePosition);
}

void GameSceneDayPanel::update(sf::Time deltaTime)
{
	m_panelAction->update(deltaTime);
}

void GameSceneDayPanel::render(sf::RenderWindow* window)
{
	m_panelAction->render(window);
}
