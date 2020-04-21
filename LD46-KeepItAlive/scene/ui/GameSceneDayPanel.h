#pragma once

#include "../../Game.h"
class Game;

#include "../GameScene.h"
class GameScene;

#include "GameSceneDayActionPanel.h"
class GameSceneDayActionPanel;

#include "GameSceneDayFieldPanel.h"
class GameSceneDayFieldPanel;

class GameSceneDayPanel
{
public:
	GameSceneDayPanel(Game* game, GameScene* gameScene);

	virtual void processEvent(sf::Event event, sf::Vector2f mousePosition);
	virtual void update(sf::Time deltaTime);
	virtual void render(sf::RenderWindow* window);

	void showActionAllowed(std::string action);
	void useAction();
	void endAction();
private:
	Game* m_game;
	GameScene* m_gameScene;
	GameSceneDayActionPanel* m_actionPanel;
	GameSceneDayFieldPanel* m_fieldPanel;
};