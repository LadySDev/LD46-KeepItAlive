#pragma once

#include "../../Game.h"

class Game;

#include "MainTitleButton.h"

class MainTitlePanel
{
public:
	MainTitlePanel(Game* game, sf::Vector2f size, sf::Vector2f position, sf::Vector2f origin);

	virtual void processEvent(sf::Event event, sf::Vector2f mousePosition);
	virtual void update(sf::Time deltaTime);
	virtual void render(sf::RenderWindow* window);

private:
	Game* m_game;

	sf::RectangleShape m_shape;

	sf::Color m_colorText;

	//PANEL MAIN TITLE SCENE
	//BUTTON NEW GAME
	/*sf::RectangleShape m_buttonNewGame;
	sf::Text m_textNewGame;*/
	MainTitleButton* m_btnNewGame;

	//BUTTON QUIT
	/*sf::RectangleShape m_buttonQuit;
	sf::Text m_textQuit;*/
	MainTitleButton* m_btnQuit;
};