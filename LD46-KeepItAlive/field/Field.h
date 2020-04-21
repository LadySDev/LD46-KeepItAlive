#pragma once

#include <SFML/Audio.hpp>

#include "../Game.h"
class Game;

#include "../scene/GameScene.h"
class GameScene;

#include <functional>

class Field
{
public:
	Field(Game* game, GameScene* gamescene, sf::ConvexShape shape);

	void setSelectionPosition(sf::Vector2f position);
	void setIsForPlant();
	bool isForPlant();
	void setIsForWater();
	bool isForWater();
	void setIsForHarvest();
	bool isForHarvest();
	void endSelection();
	bool isSeedEmpty();

	void plant(std::string name);
	void water();
	int harvest();
	void losePlant();

	virtual bool processEvent(sf::Event event, sf::Vector2f mousePosition);
	virtual void update(sf::Time deltaTime);
	virtual void render(sf::RenderWindow* window);

	std::function<void()> onClick;

private:
	Game* m_game;
	GameScene* m_gamescene;

	sf::ConvexShape m_shape;

	sf::RectangleShape m_shapeSelection;

	sf::Sound m_soundBtnOver;
	sf::Sound m_soundBtnPressed;

	Seed* m_seed;
	int m_plantAge;
	std::vector<bool> m_water;

	bool m_isForPlant;
	bool m_isForWater;
	bool m_isForHarvest;

	bool m_isOver;
	bool m_isPressed;

	void setOver();
	void setOut();
	void setPressed();
	void setReleased();

	bool isInsideTriangle(sf::Vector2f pointT0, sf::Vector2f pointT1, sf::Vector2f pointT2, sf::Vector2f point);
	bool isInsideField(sf::Vector2f mousePosition);
};