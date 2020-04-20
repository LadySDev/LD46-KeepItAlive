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
	sf::Texture m_mainTitleBG;
	sf::Texture m_mainTitleUI;
	//Shape Button
	sf::RectangleShape m_shapeMainTitleBG;
	sf::RectangleShape m_mainTitleButtonOut;
	sf::RectangleShape m_mainTitleButtonOver;
	sf::RectangleShape m_mainTitleButtonPressed;
	
	//FONT
	sf::Font m_EternityTime;

	//GAME DAY ACTIONS
	//Texture
	sf::Texture m_gameDayActions;
	//Shape Action
	sf::RectangleShape m_gameDayActionUnchecked;
	sf::RectangleShape m_gameDayActionChecked;
	sf::RectangleShape m_gameDayActionButtonOut;
	sf::RectangleShape m_gameDayActionVerticalBar;

	//ITEMS
	//Texture
	sf::Texture m_items;
	//Shape Item
	sf::RectangleShape m_itemEggplant;

	//GAME DAY FIELD
	//Texture
	sf::Texture m_gameDayField;
	sf::Texture m_charactersPhoto;
	sf::Texture m_field;
	//Shape Border Character;
	sf::RectangleShape m_shapeBorderCharacter;
	//Shape Photo Player
	sf::RectangleShape m_shapePlayer;
	//Shape Photo Children
	sf::RectangleShape m_shapeChildren;
	//Shape Border Character State
	sf::RectangleShape m_shapeBorderCharacterState;
	//Shape Character State
	sf::RectangleShape m_shapeCharacterState;
	//Shape field
	sf::RectangleShape m_shapeField;
};