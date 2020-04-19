#pragma once

#include <SFML/Graphics.hpp>

#include "Resource.h"

#include "scene/MainTitleScene.h"
class MainTitleScene;

#include "scene/GameScene.h"
class GameScene;

class Game
{
public:
	Game(int width, int height, const char* title, float scale);

	Resource* getResource();

	sf::Vector2f getSize();
	float getScale();

	void launchMainTitleScene();
	void launchGameScene();

	void close();
private:
	sf::RenderWindow m_window;
	float m_scale;
	Resource* m_resource;

	MainTitleScene* m_mainTitleScene;
	GameScene* m_gameScene;

	void processEventCurrentScene(sf::Event event, sf::Vector2f mousePosition);
	void updateCurrentScene(sf::Time deltaTime);
	void renderCurrentScene(sf::RenderWindow* window);

	void resetAllScene();
};