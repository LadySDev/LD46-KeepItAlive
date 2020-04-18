#pragma once

#include <SFML/Graphics.hpp>
#include <functional>

class MainTitleButton
{
public:
	MainTitleButton(sf::RectangleShape shape, sf::Text text);

	virtual void processEvent(sf::Event event, sf::Vector2f mousePosition);
	virtual void update(sf::Time deltaTime);
	virtual void render(sf::RenderWindow* window);

	sf::RectangleShape* getShape();

	std::function<void()> onClick;
private:
	sf::RectangleShape m_shape;
	sf::Text m_text;

	bool m_isOver;
	bool m_isPressed;

	void setOver();
	void setOut();
	void setPressed();
	void setReleased();
};