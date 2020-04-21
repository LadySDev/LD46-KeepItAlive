#include "Button.h"

Button::Button(Game* game, sf::RectangleShape shape, sf::Text text)
{
	m_game = game;
	m_shape = shape;
	m_text = text;

	m_isOver = false;
	m_isPressed = false;

	m_soundBtnOver.setBuffer(*m_game->getResource()->getBuffer("btnOver"));
	m_soundBtnOver.setVolume(10.f);

	m_soundBtnPressed.setBuffer(*m_game->getResource()->getBuffer("btnPressed"));
	m_soundBtnPressed.setVolume(10.f);
}

bool Button::processEvent(sf::Event event, sf::Vector2f mousePosition)
{
	bool eventFound = false;

	if (m_shape.getGlobalBounds().contains(mousePosition) && m_isOver == false)
	{
		m_soundBtnOver.play();
		setOver();
	}
	else if(!m_shape.getGlobalBounds().contains(mousePosition) && m_isOver == true)
	{
		setOut();
	}

	if (m_shape.getGlobalBounds().contains(mousePosition) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		eventFound = true;
		m_soundBtnPressed.play();
		setPressed();
		onClick();
	}
	else if (m_isPressed == true && !sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		setReleased();
	}

	return eventFound;
}

void Button::update(sf::Time deltaTime)
{
	
}

void Button::render(sf::RenderWindow* window)
{
	window->draw(m_shape);
	window->draw(m_text);
}

sf::RectangleShape* Button::getShape()
{
	return &m_shape;
}

std::string Button::getText()
{
	return m_text.getString();
}

void Button::setOver()
{
	if (m_isOver == false)
	{
		m_shape.setTextureRect(sf::IntRect(m_shape.getTextureRect().left, 52.f, m_shape.getTextureRect().width, m_shape.getTextureRect().height));
	}
	m_isOver = true;
}

void Button::setOut()
{
	if (m_isOver == true)
	{
		m_shape.setTextureRect(sf::IntRect(m_shape.getTextureRect().left, 1.f, m_shape.getTextureRect().width, m_shape.getTextureRect().height));
	}
	m_isOver = false;
}

void Button::setPressed()
{
	if (m_isPressed == false)
	{
		m_shape.setTextureRect(sf::IntRect(m_shape.getTextureRect().left, 103.f, m_shape.getTextureRect().width, m_shape.getTextureRect().height));
		m_text.setCharacterSize(m_text.getCharacterSize() - 2);
		m_text.setOrigin(sf::Vector2f(m_text.getGlobalBounds().width / 2, m_text.getGlobalBounds().height / 2));
	}
	m_isOver = false;
	m_isPressed = true;
}

void Button::setReleased()
{
	setOver();

	m_text.setCharacterSize(m_text.getCharacterSize() + 2);
	m_text.setOrigin(sf::Vector2f(m_text.getGlobalBounds().width / 2, m_text.getGlobalBounds().height / 2));
	
	m_isPressed = false;
}
