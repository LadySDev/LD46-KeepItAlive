#include "GameSceneDayPanel.h"

GameSceneDayPanel::GameSceneDayPanel(Game* game, GameScene* gameScene)
{
	m_game = game;
	m_gameScene = gameScene;

	m_actionPanel = new GameSceneDayActionPanel(m_game, m_gameScene, this);
	m_fieldPanel = new GameSceneDayFieldPanel(m_game, m_gameScene, this);
}

void GameSceneDayPanel::processEvent(sf::Event event, sf::Vector2f mousePosition)
{
	m_actionPanel->processEvent(event, mousePosition);
	m_fieldPanel->processEvent(event, mousePosition);
}

void GameSceneDayPanel::update(sf::Time deltaTime)
{
	m_actionPanel->update(deltaTime);
	m_fieldPanel->update(deltaTime);
}

void GameSceneDayPanel::render(sf::RenderWindow* window)
{
	m_actionPanel->render(window);
	m_fieldPanel->render(window);
}

void GameSceneDayPanel::showActionAllowed(std::string action)
{
	m_fieldPanel->showActionAllowed(action);
}

void GameSceneDayPanel::useAction()
{
	m_actionPanel->useAction();
}

void GameSceneDayPanel::endAction()
{
	m_actionPanel->endAction();
}

