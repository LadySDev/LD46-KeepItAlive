#pragma once

#include "../../Game.h"
class Game;

#include "../GameScene.h"
class GameScene;

#include "Button.h"

#include "../../field/Field.h"
class Field;

class GameSceneDayFieldPanel
{
public:
	GameSceneDayFieldPanel(Game* game, GameScene* gameScene);

	virtual void processEvent(sf::Event event, sf::Vector2f mousePosition);
	virtual void update(sf::Time deltaTime);
	virtual void render(sf::RenderWindow* window);

private:
	Game* m_game;
	GameScene* m_gameScene;
	SeedManager* m_seedManager;
	Inventory* m_inventory;
	Player* m_player;
	Children* m_children;

	sf::RectangleShape m_shape;

	sf::Color m_colorTextButton;

	sf::RectangleShape m_shapeBarUp;

	sf::Text m_textTitleDay;
	sf::Text m_textDay;

	std::vector<Field*> m_fields;

	sf::RectangleShape m_shapeBarDown;

	sf::Text m_textTitleAliment;
	sf::Text m_textAliment;
};