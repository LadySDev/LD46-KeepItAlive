#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <functional>

#include "../../Game.h"
class Game;

class SeedInventoryButton
{
public:
	SeedInventoryButton(Game* game, sf::RectangleShape shape, sf::Text text, sf::Text quantity);

	virtual bool processEvent(sf::Event event, sf::Vector2f mousePosition);
	virtual void update(sf::Time deltaTime);
	virtual void render(sf::RenderWindow* window);

	sf::RectangleShape* getShape();
	std::string getText();
	void setQuantity(std::string quantityText);

	std::function<void()> onClick;

private:
	Game* m_game;
	sf::RectangleShape m_shape;
	sf::Text m_text;
	sf::Text m_textQuantity;

	sf::Sound m_soundBtnOver;
	sf::Sound m_soundBtnPressed;

	bool m_isOver;
	bool m_isPressed;

	void setOver();
	void setOut();
	void setPressed();
	void setReleased();
};