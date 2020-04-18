#pragma once

#include <SFML/Graphics.hpp>

class Resource
{
public:
	Resource(float scale);

	void create();

	sf::RectangleShape* getShape(std::string name);
	sf::Font* getFont(std::string name);

private:
	std::string m_assetPath;

	float m_scale;

	//MAIN TITLE
	//Texture
	sf::Texture m_mainTitleUI;
	//Shape Button
	sf::RectangleShape m_mainTitleButtonOut;
	sf::RectangleShape m_mainTitleButtonOver;
	sf::RectangleShape m_mainTitleButtonPressed;
	//Font
	sf::Font m_EternityTime;
};