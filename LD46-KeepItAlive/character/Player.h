#pragma once

#include "../Game.h"
class Game;

class Player
{
public:
	Player(Game* game);

	void setState(std::string state);
	void setAlimentQuantity(int quantity);

	void setPosition(sf::Vector2f position);

	virtual void update(sf::Time deltaTime);
	virtual void render(sf::RenderWindow* window);

private:
	Game* m_game;
	std::string m_state;
	int m_alimentQuantity;

	sf::RectangleShape m_borderPhoto;
	sf::RectangleShape m_shapePhoto;

	sf::RectangleShape m_borderState;
	sf::RectangleShape m_shapeState;
};