#pragma once

#include "../../Game.h"
class Game;

#include "../GameScene.h"
class GameScene;

#include "GameSceneDayActionPanel.h"
class GameSceneDayActionPanel;

class GameSceneDayPanel
{
public:
	GameSceneDayPanel(Game* game, GameScene* gameScene);

	virtual void processEvent(sf::Event event, sf::Vector2f mousePosition);
	virtual void update(sf::Time deltaTime);
	virtual void render(sf::RenderWindow* window);

private:
	Game* m_game;
	GameScene* m_gameScene;
	GameSceneDayActionPanel* m_panelAction;
};