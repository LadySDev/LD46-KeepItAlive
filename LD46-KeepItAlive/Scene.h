#pragma once

#include "Game.h"

class Game;

class Scene
{
public:
	Scene(Game* game);

	virtual void processEvent(sf::Event event);
	virtual void update(sf::Time deltaTime);
	virtual void render(sf::RenderWindow& window);

protected:
	Game* m_game;
};