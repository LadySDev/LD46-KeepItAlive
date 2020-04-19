#include "Resource.h"

Resource::Resource(float scale)
{
	m_assetPath = "asset/";
	m_scale = scale;

	//MAIN TITLE
	if (m_mainTitleBG.loadFromFile(m_assetPath + "Ecran_titre_1.2.bmp"))
	{
		EXIT_FAILURE;
	}

	if (m_mainTitleUI.loadFromFile(m_assetPath + "MainTitleUI.png"))
	{
		EXIT_FAILURE;
	}

	//FONT
	if (m_EternityTime.loadFromFile(m_assetPath + "Eternity Time.ttf"))
	{
		EXIT_FAILURE;
	}

	//GAME DAY ACTIONS
	if (m_gameDayActions.loadFromFile(m_assetPath + "GameDayActions.png"))
	{
		EXIT_FAILURE;
	}

	//ITEMS
	if (m_items.loadFromFile(m_assetPath + "GameDayActions.png"))
	{
		EXIT_FAILURE;
	}

	create();
}

void Resource::create()
{
	m_shapeMainTitleBG.setSize(sf::Vector2f(1920.f * m_scale, 1080.f * m_scale));
	m_shapeMainTitleBG.setTexture(&m_mainTitleBG);
	m_shapeMainTitleBG.setTextureRect(sf::IntRect(0.f, 0.f, 1920.f, 1080.f));

	//Shape Button
	m_mainTitleButtonOut.setSize(sf::Vector2f(198.f * m_scale, 50.f * m_scale));
	m_mainTitleButtonOut.setTexture(&m_mainTitleUI);
	m_mainTitleButtonOut.setTextureRect(sf::IntRect(151.f, 1.f, 198.f, 50.f));

	//Shape Action
	m_gameDayActionUnchecked.setSize(sf::Vector2f(50.f * m_scale, 50.f * m_scale));
	m_gameDayActionUnchecked.setTexture(&m_gameDayActions);
	m_gameDayActionUnchecked.setTextureRect(sf::IntRect(0.f, 0.f, 50.f, 50.f));

	m_gameDayActionChecked.setSize(sf::Vector2f(50.f * m_scale, 50.f * m_scale));
	m_gameDayActionChecked.setTexture(&m_gameDayActions);
	m_gameDayActionChecked.setTextureRect(sf::IntRect(0.f, 50.f, 50.f, 50.f));

	m_gameDayActionButtonOut.setSize(sf::Vector2f(264.f * m_scale, 50.f * m_scale));
	m_gameDayActionButtonOut.setTexture(&m_gameDayActions);
	m_gameDayActionButtonOut.setTextureRect(sf::IntRect(52.f, 1.f, 264.f, 50.f));

	m_gameDayActionVerticalBar.setSize(sf::Vector2f(16.f * m_scale, 459.f * m_scale));
	m_gameDayActionVerticalBar.setTexture(&m_gameDayActions);
	m_gameDayActionVerticalBar.setTextureRect(sf::IntRect(317.f, 1.f, 16.f, 459.f));

	//ITEMS
	m_itemEggplant.setSize(sf::Vector2f(36.f * m_scale, 36.f * m_scale));
	m_itemEggplant.setTexture(&m_items);
	m_itemEggplant.setTextureRect(sf::IntRect(0.f, 0.f, 36.f, 36.f));
}

sf::RectangleShape* Resource::getShape(std::string name)
{
	if (name == "shapeMainTitleBG")
	{
		return &m_shapeMainTitleBG;
	}
	else if (name == "mainTitleButtonOut")
	{
		return &m_mainTitleButtonOut;
	}
	else if (name == "gameDayActionUnchecked")
	{
		return &m_gameDayActionUnchecked;
	}
	else if (name == "gameDayActionChecked")
	{
		return&m_gameDayActionChecked;
	}
	else if (name == "gameDayActionButtonOut")
	{
		return&m_gameDayActionButtonOut;
	}
	else if (name == "gameDayActionVerticalBar")
	{
		return&m_gameDayActionVerticalBar;
	}
	else if (name == "itemEggplant")
	{
		return&m_itemEggplant;
	}
	else
	{
		return nullptr;
	}
}

sf::Font* Resource::getFont(std::string name)
{
	if (name == "eternityTime")
	{
		return &m_EternityTime;
	}
	else
	{
		return nullptr;
	}
}
