#include "GameScene.h"

GameScene::GameScene(Game* game)
{
	m_game = game;

	m_seedManager = new SeedManager();
	m_inventory = new Inventory(m_seedManager);
	m_inventory->addSeed("eggplant", 6);

	m_dayPanel = new GameSceneDayPanel(m_game, this);

	m_colorText = sf::Color(239, 132, 100);

	sf::RectangleShape shapeMenu = *m_game->getResource()->getShape("mainTitleButtonOut");
	shapeMenu.setPosition(sf::Vector2f(m_game->getSize().x - shapeMenu.getGlobalBounds().width - 5, 5));
	shapeMenu.setOrigin(sf::Vector2f(0, 0));

	sf::Text textMenu;
	textMenu.setFont(*m_game->getResource()->getFont("eternityTime"));
	textMenu.setCharacterSize(20 * m_game->getScale());
	textMenu.setFillColor(m_colorText);
	textMenu.setString("MENU");
	textMenu.setPosition(sf::Vector2f(shapeMenu.getPosition().x + shapeMenu.getGlobalBounds().width / 2, shapeMenu.getPosition().y + shapeMenu.getGlobalBounds().height / 2));
	textMenu.setOrigin(sf::Vector2f(textMenu.getGlobalBounds().width / 2, textMenu.getGlobalBounds().height / 2));

	m_menu = new Button(shapeMenu, textMenu);
	m_menu->onClick = [this] {

	};

	m_isMenuActive = false;
}

void GameScene::processEvent(sf::Event event, sf::Vector2f mousePosition)
{
	if (m_isMenuActive == false)
	{
		if (m_menu->processEvent(event, mousePosition))
		{
			m_isMenuActive = true;
			showMenu();
		}
		else
		{
			m_dayPanel->processEvent(event, mousePosition);
		}
	}
	else if (m_isMenuActive == true)
	{
		m_menuPanel->processEvent(event, mousePosition);
	}
}

void GameScene::update(sf::Time deltaTime)
{
	if (m_isMenuActive == false && m_menuPanel != NULL)
	{
		hideMenu();
	}
	else if (m_isMenuActive == true)
	{
		m_menuPanel->update(deltaTime);
	}

	m_dayPanel->update(deltaTime);
	m_menu->update(deltaTime);
}

void GameScene::render(sf::RenderWindow* window)
{
	m_dayPanel->render(window);
	m_menu->render(window);

	if (m_isMenuActive == true)
	{
		m_menuPanel->render(window);
	}
}

void GameScene::inactiveMenu()
{
	m_isMenuActive = false;
}

SeedManager* GameScene::getSeedManager()
{
	return m_seedManager;
}

Inventory* GameScene::getInventory()
{
	return m_inventory;
}

void GameScene::showMenu()
{
	m_menuPanel = new GameSceneMenuPanel(m_game, this);
}

void GameScene::hideMenu()
{
	m_menuPanel = NULL;
}
