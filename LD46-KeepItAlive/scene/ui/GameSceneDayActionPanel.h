#pragma once

#include "../../Game.h"
class Game;

#include "../GameScene.h"
class GameScene;

#include "Button.h"
class Button;

#include "SeedInventoryButton.h"
class SeedInventoryButton;

#include "GameSceneDayPanel.h"
class GameSceneDayPanel;

class GameSceneDayActionPanel
{
public:
	GameSceneDayActionPanel(Game* game, GameScene* gameScene, GameSceneDayPanel* dayPanel);

	virtual void processEvent(sf::Event event, sf::Vector2f mousePosition);
	virtual void update(sf::Time deltaTime);
	virtual void render(sf::RenderWindow* window);

	void useAction();
	void endAction();
private:
	Game* m_game;
	GameScene* m_gameScene;
	GameSceneDayPanel* m_dayPanel;
	SeedManager* m_seedManager;
	Inventory* m_inventory;

	sf::RectangleShape m_shape;

	sf::Color m_colorTextButton;

	sf::Text m_textActions;
	std::vector<sf::RectangleShape> m_shapeActions;
	int m_action;

	Button* m_btnShop;

	//INVENTORY
	sf::Text m_textInventory;
	//Seed
	std::vector<SeedInventoryButton*> m_btnSeeds;
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