#pragma once

#include "../Game.h"
class Game;

#include "../scene/GameScene.h"
class GameScene;

class Field
{
public:
	Field(Game* game, GameScene* gamescene, sf::ConvexShape shape);

	void plant(std::string name);
	void water();
	int harvest();
	void losePlant();

	virtual void processEvent(sf::Event event, sf::Vector2f mousePosition);
	virtual void update(sf::Time deltaTime);
	virtual void render(sf::RenderWindow* window);

private:
	Game* m_game;
	GameScene* m_gamescene;
	sf::ConvexShape m_shape;
	Seed* m_seed;
	int m_plantAge;
	std::vector<bool> m_water;
};