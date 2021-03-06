#include "GameSceneDayActionPanel.h"

GameSceneDayActionPanel::GameSceneDayActionPanel(Game* game, GameScene* gameScene, GameSceneDayPanel* dayPanel)
{
	m_game = game;
	m_gameScene = gameScene;
	m_dayPanel = dayPanel;
	m_seedManager = m_gameScene->getSeedManager();
	m_inventory = m_gameScene->getInventory();

	m_shape.setSize(sf::Vector2f(584 * m_game->getScale(), m_game->getSize().y));
	m_shape.setPosition(sf::Vector2f(m_game->getSize().x - m_shape.getSize().x, 0));
	m_shape.setOrigin(sf::Vector2f(0, 0));
	m_shape.setFillColor(sf::Color(102, 102, 102));

	m_colorTextButton = sf::Color::White;

	//TITLE ACTIONS
	m_textActions.setFont(*m_game->getResource()->getFont("eternityTime"));
	m_textActions.setCharacterSize(25 * m_game->getScale());
	m_textActions.setFillColor(m_colorTextButton);
	m_textActions.setString("ACTIONS");
	m_textActions.setPosition(sf::Vector2f(m_shape.getPosition().x + m_shape.getSize().x / 2, m_shape.getPosition().y + (106 * m_game->getScale())));
	m_textActions.setOrigin(sf::Vector2f(m_textActions.getGlobalBounds().width / 2, m_textActions.getGlobalBounds().height / 2));

	//ACTIONS
	for (int i = 0; i < 10; i++)
	{
		sf::RectangleShape shape = *m_game->getResource()->getShape("gameDayActionUnchecked");
		shape.setPosition(sf::Vector2f(m_shape.getPosition().x + 5 + (i * (shape.getSize().x + 5)), m_textActions.getPosition().y + (30.3 * m_game->getScale())));
		shape.setOrigin(sf::Vector2f());

		m_shapeActions.push_back(shape);
	}

	m_action = -1;

	//SHOP
	sf::RectangleShape shapeShop = *m_game->getResource()->getShape("gameDayActionButtonOut");
	shapeShop.setPosition(sf::Vector2f(m_shape.getPosition().x + m_shape.getSize().x / 2, m_textActions.getPosition().y + (136.36 * m_game->getScale())));
	shapeShop.setOrigin(sf::Vector2f(shapeShop.getGlobalBounds().width / 2, shapeShop.getGlobalBounds().height / 2));

	sf::Text textShop;
	textShop.setFont(*m_game->getResource()->getFont("eternityTime"));
	textShop.setCharacterSize(20 * m_game->getScale());
	textShop.setFillColor(m_colorTextButton);
	textShop.setString("SHOP");
	textShop.setPosition(sf::Vector2f(shapeShop.getPosition().x, shapeShop.getPosition().y));
	textShop.setOrigin(sf::Vector2f(textShop.getGlobalBounds().width / 2, textShop.getGlobalBounds().height / 2));

	m_btnShop = new Button(m_game, shapeShop, textShop);
	m_btnShop->onClick = [this] {

	};

	//TITLE INVENTORY
	m_textInventory.setFont(*m_game->getResource()->getFont("eternityTime"));
	m_textInventory.setCharacterSize(25 * m_game->getScale());
	m_textInventory.setFillColor(m_colorTextButton);
	m_textInventory.setString("INVENTORY");
	m_textInventory.setPosition(sf::Vector2f(m_shape.getPosition().x + m_shape.getSize().x / 2, shapeShop.getPosition().y + (75.75 * m_game->getScale())));
	m_textInventory.setOrigin(sf::Vector2f(m_textInventory.getGlobalBounds().width / 2, m_textInventory.getGlobalBounds().height / 2));

	//INVENTORY
	//Seed
	std::map<std::string, std::pair<Seed*, int>>* inventorySeeds = m_inventory->getSeeds();
	std::map<std::string, std::pair<Seed*, int>>::iterator it;
	for (it = inventorySeeds->begin(); it != inventorySeeds->end(); ++ it)
	{
		sf::RectangleShape shapeSeed = *m_game->getResource()->getShape("gameDayActionButtonOut");
		shapeSeed.setPosition(sf::Vector2f(m_shape.getPosition().x + m_shape.getSize().x / 4 - (4.54 * m_game->getScale()), m_shape.getPosition().y + (363.63 * m_game->getScale()) + (shapeSeed.getGlobalBounds().height / 2) + (shapeSeed.getGlobalBounds().height * m_btnSeeds.size())));
		shapeSeed.setOrigin(sf::Vector2f(shapeSeed.getGlobalBounds().width / 2, shapeSeed.getGlobalBounds().height / 2));

		std::string nameSeed = it->first;
		std::transform(nameSeed.begin(), nameSeed.end(), nameSeed.begin(), ::toupper);

		sf::Text textSeed;
		textSeed.setFont(*m_game->getResource()->getFont("eternityTime"));
		textSeed.setCharacterSize(20 * m_game->getScale());
		textSeed.setFillColor(m_colorTextButton);
		textSeed.setString(nameSeed);
		textSeed.setPosition(sf::Vector2f(shapeSeed.getPosition().x, shapeSeed.getPosition().y));
		textSeed.setOrigin(sf::Vector2f(textSeed.getGlobalBounds().width / 2, textSeed.getGlobalBounds().height / 2));

		sf::Text textSeedQuantity;
		textSeedQuantity.setFont(*m_game->getResource()->getFont("eternityTime"));
		textSeedQuantity.setCharacterSize(25 * m_game->getScale());
		textSeedQuantity.setFillColor(m_colorTextButton);
		textSeedQuantity.setString(" x" + std::to_string(it->second.second));
		textSeedQuantity.setPosition(sf::Vector2f(textSeed.getPosition().x + textSeed.getGlobalBounds().width / 2 + (15 * m_game->getScale()), textSeed.getPosition().y - (5 * m_game->getScale())));
		textSeedQuantity.setOrigin(sf::Vector2f(textSeedQuantity.getGlobalBounds().width / 2, textSeedQuantity.getGlobalBounds().height / 2));

		SeedInventoryButton* btnSeed = new SeedInventoryButton(m_game, shapeSeed, textSeed, textSeedQuantity);
		btnSeed->onClick = [this] {
			m_dayPanel->showActionAllowed("eggplant");
			m_isActionOnGoing = true;
		};

		m_btnSeeds.push_back(btnSeed);
	}

	//Bar
	m_shapeBar = *m_game->getResource()->getShape("gameDayActionVerticalBar");
	m_shapeBar.setPosition(sf::Vector2f(m_shape.getPosition().x + m_shape.getSize().x / 2, m_shape.getPosition().y + (363.63 * m_game->getScale())));
	m_shapeBar.setOrigin(sf::Vector2f(m_shapeBar.getGlobalBounds().width / 2, 0));

	//Other

	//BUTTON WATER
	sf::RectangleShape shapeWater = *m_game->getResource()->getShape("gameDayActionButtonOut");
	shapeWater.setPosition(sf::Vector2f(m_shape.getPosition().x + m_shape.getSize().x / 2, m_shape.getPosition().y + m_shape.getSize().y - (shapeWater.getGlobalBounds().height * 4) - (22.72 * m_game->getScale())));
	shapeWater.setOrigin(sf::Vector2f(shapeWater.getGlobalBounds().width / 2, shapeWater.getGlobalBounds().height / 2));

	sf::Text textWater;
	textWater.setFont(*m_game->getResource()->getFont("eternityTime"));
	textWater.setCharacterSize(20 * m_game->getScale());
	textWater.setFillColor(m_colorTextButton);
	textWater.setString("WATER");
	textWater.setPosition(sf::Vector2f(shapeWater.getPosition().x, shapeWater.getPosition().y));
	textWater.setOrigin(sf::Vector2f(textWater.getGlobalBounds().width / 2, textWater.getGlobalBounds().height / 2));

	m_btnWater = new Button(m_game, shapeWater, textWater);
	m_btnWater->onClick = [this] {
		m_dayPanel->showActionAllowed("water");
		m_isActionOnGoing = true;
	};

	//BUTTON HARVEST
	sf::RectangleShape shapeHarvest = *m_game->getResource()->getShape("gameDayActionButtonOut");
	shapeHarvest.setPosition(sf::Vector2f(m_shape.getPosition().x + m_shape.getSize().x / 2, m_shape.getPosition().y + m_shape.getSize().y - (shapeHarvest.getGlobalBounds().height * 3) - (15.15 * m_game->getScale())));
	shapeHarvest.setOrigin(sf::Vector2f(shapeHarvest.getGlobalBounds().width / 2, shapeHarvest.getGlobalBounds().height / 2));

	sf::Text textHarvest;
	textHarvest.setFont(*m_game->getResource()->getFont("eternityTime"));
	textHarvest.setCharacterSize(20 * m_game->getScale());
	textHarvest.setFillColor(m_colorTextButton);
	textHarvest.setString("HARVEST");
	textHarvest.setPosition(sf::Vector2f(shapeHarvest.getPosition().x, shapeHarvest.getPosition().y));
	textHarvest.setOrigin(sf::Vector2f(textHarvest.getGlobalBounds().width / 2, textHarvest.getGlobalBounds().height / 2));

	m_btnHarvest = new Button(m_game, shapeHarvest, textHarvest);
	m_btnHarvest->onClick = [this] {
		m_dayPanel->showActionAllowed("harvest");
		m_isActionOnGoing = true;
	};

	//Action On Going
	m_isActionOnGoing = false;

	m_shapeActionOnGoing = m_shape;
	m_shapeActionOnGoing.setFillColor(sf::Color(163, 163, 163, 180));

	//BUTTON CANCEL
	sf::RectangleShape shapeCancel = *m_game->getResource()->getShape("gameDayActionButtonOut");
	shapeCancel.setPosition(sf::Vector2f(m_shape.getPosition().x + m_shape.getSize().x / 2, m_shape.getPosition().y + m_shape.getSize().y - shapeCancel.getGlobalBounds().height - (15.15 * m_game->getScale())));
	shapeCancel.setOrigin(sf::Vector2f(shapeCancel.getGlobalBounds().width / 2, shapeCancel.getGlobalBounds().height / 2));

	sf::Text textCancel;
	textCancel.setFont(*m_game->getResource()->getFont("eternityTime"));
	textCancel.setCharacterSize(20 * m_game->getScale());
	textCancel.setFillColor(m_colorTextButton);
	textCancel.setString("CANCEL");
	textCancel.setPosition(sf::Vector2f(shapeCancel.getPosition().x, shapeCancel.getPosition().y));
	textCancel.setOrigin(sf::Vector2f(textCancel.getGlobalBounds().width / 2, textCancel.getGlobalBounds().height / 2));

	m_btnCancel = new Button(m_game, shapeCancel, textCancel);
	m_btnCancel->onClick = [this] {
		m_dayPanel->showActionAllowed("end");
		m_isActionOnGoing = false;
	};
}

void GameSceneDayActionPanel::processEvent(sf::Event event, sf::Vector2f mousePosition)
{
	if (m_isActionOnGoing == true)
	{
		m_btnCancel->processEvent(event, mousePosition);
	}
	else
	{
		m_btnShop->processEvent(event, mousePosition);

		for (int i = 0; i < m_btnSeeds.size(); i++)
		{
			m_btnSeeds.at(i)->processEvent(event, mousePosition);
		}

		m_btnWater->processEvent(event, mousePosition);
		m_btnHarvest->processEvent(event, mousePosition);
	}
}

void GameSceneDayActionPanel::update(sf::Time deltaTime)
{
	if (m_isActionOnGoing == true)
	{
		m_btnCancel->update(deltaTime);
	}
	else
	{
		m_btnShop->update(deltaTime);

		for (int i = 0; i < m_btnSeeds.size(); i++)
		{
			std::string seedName = m_btnSeeds.at(i)->getText();
			std::transform(seedName.begin(), seedName.end(), seedName.begin(), ::tolower);
			std::map<std::string, std::pair<Seed*, int>> seeds = *m_inventory->getSeeds();
			std::map<std::string, std::pair<Seed*, int>>::const_iterator it = seeds.find(seedName);
			if (it == seeds.end())
			{
				m_btnSeeds.erase(m_btnSeeds.begin() + i);
			}
			else {
				m_btnSeeds.at(i)->setQuantity(" x"+ std::to_string(it->second.second));
				m_btnSeeds.at(i)->update(deltaTime);
			}
		}

		m_btnWater->update(deltaTime);
		m_btnHarvest->update(deltaTime);
	}
}

void GameSceneDayActionPanel::render(sf::RenderWindow* window)
{
	window->draw(m_shape);

	window->draw(m_textActions);

	for (int i = 0; i < 10; i++)
	{
		window->draw(m_shapeActions[i]);
	}

	m_btnShop->render(window);

	if (m_action < 9)
	{
		window->draw(m_textInventory);

		for (int i = 0; i < m_btnSeeds.size(); i++)
		{
			m_btnSeeds.at(i)->render(window);
		}

		window->draw(m_shapeBar);

		m_btnWater->render(window);
		m_btnHarvest->render(window);
	}
	

	if (m_isActionOnGoing == true)
	{
		window->draw(m_shapeActionOnGoing);
		m_btnCancel->render(window);
	}
}

void GameSceneDayActionPanel::useAction()
{
	m_action = m_action + 1;
	if (m_action <= 9)
	{
		m_shapeActions[m_action].setTextureRect(sf::IntRect(m_shapeActions[m_action].getTextureRect().left, 50, m_shapeActions[m_action].getTextureRect().width, m_shapeActions[m_action].getTextureRect().height));
	}
}

void GameSceneDayActionPanel::endAction()
{
	m_isActionOnGoing = false;
}
