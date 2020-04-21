#pragma once

#include "../Game.h"
class Game;

#include "../item/SeedManager.h"
#include "../Inventory.h"

#include "ui/GameSceneDayPanel.h"
class GameSceneDayPanel;

#include "ui/Button.h"
class Button;

#include "ui/GameSceneMenuPanel.h"
class GameSceneMenuPanel;

class GameScene
{
public:
	GameScene(Game* game);

	virtual void processEvent(sf::Event event, sf::Vector2f mousePosition);
	virtual void update(sf::Time deltaTime);
	virtual void render(sf::RenderWindow* window);

	void inactiveMenu();

	SeedManager* getSeedManager();
	Inventory* getInventory();
private:
	Game* m_game;

	SeedManager* m_seedManager;
	Inventory* m_inventory;

	GameSceneDayPanel* m_dayPanel;

	GameSceneMenuPanel* m_menuPanel;

	sf::Color m_colorText;
	Button* m_menu;
	bool m_isMenuActive;

	void showMenu();
	void hideMenu();
};