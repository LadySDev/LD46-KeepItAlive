#include "MainTitleButton.h"

MainTitleButton::MainTitleButton(sf::RectangleShape shape, sf::Text text)
{
	m_shape = shape;
	m_text = text;

	m_isOver = false;
	m_isPressed = false;
}

void MainTitleButton::processEvent(sf::Event event, sf::Vector2f mousePosition)
{
	if (m_shape.getGlobalBounds().contains(mousePosition) && m_isOver == false)
	{
		setOver();
	}
	else if(!m_shape.getGlobalBounds().contains(mousePosition) && m_isOver == true)
	{
		setOut();
	}

	if (m_shape.getGlobalBounds().contains(mousePosition) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		setPressed();
		onClick();
	}
	else if (m_shape.getGlobalBounds().contains(mousePosition) && !sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_isPressed == true)
	{
		setReleased();
	}
}

void MainTitleButton::update(sf::Time deltaTime)
{
	
}

void MainTitleButton::render(sf::RenderWindow* window)
{
	window->draw(m_shape);
	window->draw(m_text);
}

sf::RectangleShape* MainTitleButton::getShape()
{
	return &m_shape;
}

void MainTitleButton::setOver()
{
	if (m_isOver == false)
	{
		m_shape.setTextureRect(sf::IntRect(m_shape.getTextureRect().left, m_shape.getTextureRect().height, m_shape.getTextureRect().width, m_shape.getTextureRect().height));
	}
	m_isOver = true;
}

void MainTitleButton::setOut()
{
	if (m_isOver == true)
	{
		m_shape.setTextureRect(sf::IntRect(m_shape.getTextureRect().left, 0.f, m_shape.getTextureRect().width, m_shape.getTextureRect().height));
	}
	m_isOver = false;
}

void MainTitleButton::setPressed()
{
	if (m_isPressed == false)
	{
		m_shape.setTextureRect(sf::IntRect(m_shape.getTextureRect().left, m_shape.getTextureRect().height * 2, m_shape.getTextureRect().width, m_shape.getTextureRect().height));
		m_text.setCharacterSize(m_text.getCharacterSize() - 2);
		m_text.setOrigin(sf::Vector2f(m_text.getGlobalBounds().width / 2, m_text.getGlobalBounds().height / 2));
	}
	m_isOver = false;
	m_isPressed = true;
}

void MainTitleButton::setReleased()
{
	if (m_isPressed == true)
	{
		setOver();
		m_text.setCharacterSize(m_text.getCharacterSize() + 2);
		m_text.setOrigin(sf::Vector2f(m_text.getGlobalBounds().width / 2, m_text.getGlobalBounds().height / 2));
	}
	m_isPressed = false;
}
