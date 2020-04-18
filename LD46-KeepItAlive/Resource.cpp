#include "Resource.h"

Resource::Resource()
{
	m_assetPath = "asset/";

	if (m_mainTitleUI.loadFromFile(m_assetPath + "MainTitleUI.png"))
	{
		EXIT_FAILURE;
	}

	m_mainTitleButton.setTexture(&m_mainTitleUI);
	m_mainTitleButton.setTextureRect(sf::IntRect(0, 0, 114.f, 23.f));
}

sf::RectangleShape* Resource::getShape(std::string name)
{
	if (name == "mainTitleButton")
	{
		sf::RectangleShape shape = m_mainTitleButton;
		return &shape;
	}
	else
	{
		return nullptr;
	}
}
