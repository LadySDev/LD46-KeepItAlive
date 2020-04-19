#pragma once

#include "../../Game.h"
class Game;

#include "Button.h"

#include "../GameScene.h"
class GameScene;

class GameSceneMenuPanel
{
public:
	GameSceneMenuPanel(Game* game, GameScene* gameScene);

	virtual void processEvent(sf::Event event, sf::Vector2f mousePosition);
	virtual void update(sf::Time deltaTime);
	virtual void render(sf::RenderWindow* window);

private:
	Game* m_game;
	GameScene* m_gameScene;

	sf::RectangleShape m_shape;

	sf::Color m_colorText;

	Button* m_btnResume;
	Button* m_btnNewGame;
	Button* m_btnTitle;
	Button* m_btnQuit;
};