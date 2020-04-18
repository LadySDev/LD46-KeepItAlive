#pragma once

#include <SFML/Graphics.hpp>

#include "Resource.h"

#include "scene/MainTitleScene.h"

class MainTitleScene;

class Game
{
public:
	Game(int width, int height, const char* title, float scale);

	Resource* getResource();

	sf::Vector2f getSize();
	float getScale();

	void close();
private:
	sf::RenderWindow m_window;
	float m_scale;
	Resource* m_resource;

	MainTitleScene* m_mainTitleScene;
};