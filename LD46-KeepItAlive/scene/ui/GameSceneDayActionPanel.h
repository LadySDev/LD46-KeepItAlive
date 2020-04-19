#pragma once

#include "../../Game.h"
class Game;

#include "../GameScene.h"
class GameScene;

#include "Button.h"

class GameSceneDayActionPanel
{
public:
	GameSceneDayActionPanel(Game* game, GameScene* gameScene);

	virtual void processEvent(sf::Event event, sf::Vector2f mousePosition);
	virtual void update(sf::Time deltaTime);
	virtual void render(sf::RenderWindow* window);

private:
	Game* m_game;
	GameScene* m_gameScene;
	SeedManager* m_seedManager;
	Inventory* m_inventory;

	sf::RectangleShape m_shape;

	sf::Color m_colorTextButton;

	sf::Text m_textActions;
	std::vector<sf::RectangleShape> m_shapeActions;

	Button* m_btnShop;

	//INVENTORY
	sf::Text m_textInventory;
	//Seed
	std::vector<Button*> m_btnSeeds;
	//Bar
	sf::RectangleShape m_shapeBar;
	//Other

	//WATER
	Button* m_btnWater;

	//HARVEST
	Button* m_btnHarvest;

	bool m_isActionOnGoing;
	sf::RectangleShape m_shapeActionOnGoing;
	Button* m_btnCancel;
};