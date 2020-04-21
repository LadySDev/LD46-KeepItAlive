#include "GameSceneDayFieldPanel.h"

GameSceneDayFieldPanel::GameSceneDayFieldPanel(Game* game, GameScene* gameScene, GameSceneDayPanel* dayPanel)
{
	m_game = game;
	m_gameScene = gameScene;
	m_dayPanel = dayPanel;
	m_seedManager = m_gameScene->getSeedManager();
	m_inventory = m_gameScene->getInventory();
	m_player = m_game->getPlayer();
	m_children = m_game->getChildren();

	m_shape = *m_game->getResource()->getShape("shapeField");

	m_colorTextButton = sf::Color::White;

	//Shape Bar Up
	m_shapeBarUp.setSize(sf::Vector2f(935 * m_game->getScale(), 100 * m_game->getScale()));
	m_shapeBarUp.setPosition(sf::Vector2f(m_shape.getPosition().x + m_shape.getSize().x / 2, m_shape.getPosition().y + (7.57 * m_game->getScale())));
	m_shapeBarUp.setOrigin(sf::Vector2f(m_shapeBarUp.getSize().x / 2, 0));
	m_shapeBarUp.setFillColor(sf::Color(102, 102, 102));

	//Characters
	m_player->setPosition(sf::Vector2f(m_shape.getPosition().x + (7.57 * m_game->getScale()), m_shape.getPosition().y + (7.57 * m_game->getScale())));
	m_children->setPosition(sf::Vector2f(m_shape.getPosition().x + m_shape.getGlobalBounds().width - m_children->getSize().x - (7.57 * m_game->getScale()), m_shape.getPosition().y + (7.57 * m_game->getScale())));

	//TITLE DAY
	m_textTitleDay.setFont(*m_game->getResource()->getFont("eternityTime"));
	m_textTitleDay.setCharacterSize(40 * m_game->getScale());
	m_textTitleDay.setFillColor(m_colorTextButton);
	m_textTitleDay.setString("DAY ");
	m_textTitleDay.setPosition(sf::Vector2f(m_shapeBarUp.getPosition().x, m_shapeBarUp.getPosition().y + m_shapeBarUp.getSize().y / 2));
	m_textTitleDay.setOrigin(sf::Vector2f(m_textTitleDay.getGlobalBounds().width, m_textTitleDay.getGlobalBounds().height / 2));
	//Day
	m_textDay.setFont(*m_game->getResource()->getFont("eternityTime"));
	m_textDay.setCharacterSize(50 * m_game->getScale());
	m_textDay.setFillColor(m_colorTextButton);
	m_textDay.setString(" " + std::to_string(m_game->getDay()));
	m_textDay.setPosition(sf::Vector2f(m_shapeBarUp.getPosition().x, m_shapeBarUp.getPosition().y + m_shapeBarUp.getSize().y / 2 + (10 * m_game->getScale())));
	m_textDay.setOrigin(sf::Vector2f(0, m_textDay.getGlobalBounds().height));



	//////////FIELDS//////////
	//1//
	sf::ConvexShape m_shapeField1;
	m_shapeField1.setPointCount(4);
	m_shapeField1.setPoint(0, sf::Vector2f(298 * m_game->getScale(), 583 * m_game->getScale()));
	m_shapeField1.setPoint(1, sf::Vector2f(429 * m_game->getScale(), 583 * m_game->getScale()));
	m_shapeField1.setPoint(2, sf::Vector2f(370 * m_game->getScale(), 723 * m_game->getScale()));
	m_shapeField1.setPoint(3, sf::Vector2f(211 * m_game->getScale(), 723 * m_game->getScale()));
	Field* m_field1 = new Field(m_game, m_gameScene, m_shapeField1);
	m_field1->setSelectionPosition(sf::Vector2f(330 * m_game->getScale(), 652 * m_game->getScale()));
	m_fields.push_back(m_field1);

	for (int i = 0; i < m_fields.size(); i++)
	{
		Field* field = m_fields.at(i);
		field->onClick = [this, field] {
			if (field->isForPlant() == true && field->isSeedEmpty() == true)
			{
				field->plant(m_seedToPlant);
				m_gameScene->getInventory()->addSeed(m_seedToPlant, -1);
			}
			else if (field->isForWater() == true && field->isSeedEmpty() == false)
			{
				field->water();
			}
			else if (field->isForHarvest() == true && field->isSeedEmpty() == false)
			{
				m_game->addAliment(field->harvest());
			}

			m_dayPanel->endAction();
			m_dayPanel->useAction();
			showActionAllowed("end");
		};
	}

	//Shape Bar Down
	m_shapeBarDown.setSize(sf::Vector2f(935 * m_game->getScale(), 75 * m_game->getScale()));
	m_shapeBarDown.setPosition(sf::Vector2f(m_shape.getPosition().x + m_shape.getSize().x / 2, m_shape.getPosition().y + m_shape.getSize().y - (7.57 * m_game->getScale())));
	m_shapeBarDown.setOrigin(sf::Vector2f(m_shapeBarDown.getSize().x / 2, m_shapeBarDown.getSize().y));
	m_shapeBarDown.setFillColor(sf::Color(102, 102, 102));

	//Title Aliment
	m_textTitleAliment.setFont(*m_game->getResource()->getFont("eternityTime"));
	m_textTitleAliment.setCharacterSize(25 * m_game->getScale());
	m_textTitleAliment.setFillColor(m_colorTextButton);
	m_textTitleAliment.setString("ALIMENT ");
	m_textTitleAliment.setPosition(sf::Vector2f(m_shapeBarDown.getPosition().x, m_shapeBarDown.getPosition().y - m_shapeBarDown.getSize().y / 2));
	m_textTitleAliment.setOrigin(sf::Vector2f(m_textTitleAliment.getGlobalBounds().width, m_textTitleAliment.getGlobalBounds().height / 2));
	//Aliment
	m_textAliment.setFont(*m_game->getResource()->getFont("eternityTime"));
	m_textAliment.setCharacterSize(35 * m_game->getScale());
	m_textAliment.setFillColor(m_colorTextButton);
	m_textAliment.setString(" " + std::to_string(m_game->getAliment()));
	m_textAliment.setPosition(sf::Vector2f(m_shapeBarDown.getPosition().x, m_shapeBarDown.getPosition().y - m_shapeBarDown.getSize().y / 2 - (8 * m_game->getScale())));
	m_textAliment.setOrigin(sf::Vector2f(0, m_textAliment.getGlobalBounds().height / 2));
}

void GameSceneDayFieldPanel::processEvent(sf::Event event, sf::Vector2f mousePosition)
{
	for (int i = 0; i < m_fields.size(); i++)
	{
		m_fields.at(i)->processEvent(event, mousePosition);
	}
}

void GameSceneDayFieldPanel::update(sf::Time deltaTime)
{
	m_player->update(deltaTime);
	m_children->update(deltaTime);

	m_textDay.setString(" " + std::to_string(m_game->getDay()));

	for (int i = 0; i < m_fields.size(); i++)
	{
		m_fields.at(i)->update(deltaTime);
	}

	m_textAliment.setString(" " + std::to_string(m_game->getAliment()));
}

void GameSceneDayFieldPanel::render(sf::RenderWindow* window)
{
	window->draw(m_shape);
	window->draw(m_shapeBarUp);
	window->draw(m_shapeBarDown);

	m_player->render(window);
	m_children->render(window);

	window->draw(m_textTitleDay);
	window->draw(m_textDay);

	for (int i = 0; i < m_fields.size(); i++)
	{
		m_fields.at(i)->render(window);
	}

	window->draw(m_textTitleAliment);
	window->draw(m_textAliment);
}

void GameSceneDayFieldPanel::showActionAllowed(std::string action)
{
	if (action == "water")
	{
		for (int i = 0; i < m_fields.size(); i++)
		{
			m_fields.at(i)->setIsForWater();
		}
	}
	else if (action == "harvest")
	{
		for (int i = 0; i < m_fields.size(); i++)
		{
			m_fields.at(i)->setIsForHarvest();
		}
	}
	else if (action == "end")
	{
		for (int i = 0; i < m_fields.size(); i++)
		{
			m_fields.at(i)->endSelection();
		}
	}
	else
	{
		for (int i = 0; i < m_fields.size(); i++)
		{
			m_fields.at(i)->setIsForPlant();
		}

		if (action == "eggplant")
		{
			m_seedToPlant = action;
		}
	}
}
