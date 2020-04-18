#pragma once

#include "../Game.h"
#include "ui/MainTitlePanel.h"

class Game;
class MainTitlePanel;

class MainTitleScene
{
public:
	MainTitleScene(Game* game);

	virtual void processEvent(sf::Event event, sf::Vector2f mousePosition);
	virtual void update(sf::Time deltaTime);
	virtual void render(sf::RenderWindow* window);

private:
	Game* m_game;
	MainTitlePanel* m_panel;
};