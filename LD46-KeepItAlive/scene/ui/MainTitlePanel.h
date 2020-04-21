#pragma once

#include <SFML/Audio.hpp>

#include "../../Game.h"
class Game;

#include "Button.h"
class Button;

class MainTitlePanel
{
public:
	MainTitlePanel(Game* game);

	virtual void processEvent(sf::Event event, sf::Vector2f mousePosition);
	virtual void update(sf::Time deltaTime);
	virtual void render(sf::RenderWindow* window);

	void stopMusic();
private:
	Game* m_game;

	sf::RectangleShape m_shape;

	sf::Color m_colorText;

	sf::Sound m_music;

	//BUTTON NEW GAME
	Button* m_btnNewGame;

	//BUTTON QUIT
	Button* m_btnQuit;
};