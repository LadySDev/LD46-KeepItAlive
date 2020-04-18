#include "Resource.h"

Resource::Resource(float scale)
{
	m_assetPath = "asset/";
	m_scale = scale;

	//MAIN TITLE
	if (m_mainTitleUI.loadFromFile(m_assetPath + "MainTitleUI.png"))
	{
		EXIT_FAILURE;
	}

	//Font
	if (m_EternityTime.loadFromFile(m_assetPath + "Eternity Time.ttf"))
	{
		EXIT_FAILURE;
	}

	create();
}

void Resource::create()
{
	//Shape Button
	m_mainTitleButtonOut.setSize(sf::Vector2f(150.f * m_scale, 28.f * m_scale));
	m_mainTitleButtonOut.setTexture(&m_mainTitleUI);
	m_mainTitleButtonOut.setTextureRect(sf::IntRect(0, 0, 150.f, 28.f));

	m_mainTitleButtonOver.setSize(sf::Vector2f(150.f * m_scale, 28.f * m_scale));
	m_mainTitleButtonOver.setTexture(&m_mainTitleUI);
	m_mainTitleButtonOver.setTextureRect(sf::IntRect(0, 28.f, 150.f, 28.f));

	m_mainTitleButtonPressed.setSize(sf::Vector2f(150.f * m_scale, 28.f * m_scale));
	m_mainTitleButtonPressed.setTexture(&m_mainTitleUI);
	m_mainTitleButtonPressed.setTextureRect(sf::IntRect(0, 56.f, 150.f, 28.f));
}

sf::RectangleShape* Resource::getShape(std::string name)
{
	if (name == "mainTitleButtonOut")
	{
		return &m_mainTitleButtonOut;
	}
	else if (name == "mainTitleButtonOver")
	{
		return &m_mainTitleButtonOver;
	}
	else if (name == "mainTitleButtonPressed")
	{
		return &m_mainTitleButtonPressed;
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
