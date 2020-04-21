#pragma once

#include "../../Game.h"
class Game;

#include "../GameScene.h"
class GameScene;

#include "GameSceneDayPanel.h"
class GameSceneDayPanel;

#include "Button.h"

#include "../../field/Field.h"
class Field;

class GameSceneDayFieldPanel
{
public:
	GameSceneDayFieldPanel(Game* game, GameScene* gameScene, GameSceneDayPanel* dayPanel);

	virtual void processEvent(sf::Event event, sf::Vector2f mousePosition);
	virtual void update(sf::Time deltaTime);
	virtual void render(sf::RenderWindow* window);

	void showActionAllowed(std::string action);
private:
	Game* m_game;
	GameScene* m_gameScene;
	GameSceneDayPanel* m_dayPanel;
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
	std::string m_seedToPlant;

	sf::RectangleShape m_shapeBarDown;

	sf::Text m_textTitleAliment;
	sf::Text m_textAliment;
};