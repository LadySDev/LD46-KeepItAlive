#pragma once

#include <SFML/Graphics.hpp>

class Resource
{
public:
	Resource();

	sf::RectangleShape* getShape(std::string name);
private:
	std::string m_assetPath;

	//MAIN TITLE
	//Texture
	sf::Texture m_mainTitleUI;
	//Shape Button
	sf::RectangleShape m_mainTitleButton;
};