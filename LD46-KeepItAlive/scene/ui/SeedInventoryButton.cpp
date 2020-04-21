#include "SeedInventoryButton.h"

SeedInventoryButton::SeedInventoryButton(Game* game, sf::RectangleShape shape, sf::Text text, sf::Text quantity)
{
	m_game = game;
	m_shape = shape;
	m_text = text;
	m_textQuantity = quantity;

	m_isOver = false;
	m_isPressed = false;

	m_soundBtnOver.setBuffer(*m_game->getResource()->getBuffer("btnOver"));
	m_soundBtnOver.setVolume(10.f);

	m_soundBtnPressed.setBuffer(*m_game->getResource()->getBuffer("btnPressed"));
	m_soundBtnPressed.setVolume(10.f);
}

bool SeedInventoryButton::processEvent(sf::Event event, sf::Vector2f mousePosition)
{
	bool eventFound = false;

	if (m_shape.getGlobalBounds().contains(mousePosition) && m_isOver == false)
	{
		m_soundBtnOver.play();
		setOver();
	}
	else if (!m_shape.getGlobalBounds().contains(mousePosition) && m_isOver == true)
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

void SeedInventoryButton::update(sf::Time deltaTime)
{
	
}

void SeedInventoryButton::render(sf::RenderWindow* window)
{
	window->draw(m_shape);
	window->draw(m_text);
	window->draw(m_textQuantity);
}

sf::RectangleShape* SeedInventoryButton::getShape()
{
	return &m_shape;
}

std::string SeedInventoryButton::getText()
{
	return m_text.getString();
}

void SeedInventoryButton::setQuantity(std::string quantityText)
{
	m_textQuantity.setString(quantityText);
}

void SeedInventoryButton::setOver()
{
	if (m_isOver == false)
	{
		m_shape.setTextureRect(sf::IntRect(m_shape.getTextureRect().left, 52.f, m_shape.getTextureRect().width, m_shape.getTextureRect().height));
	}
	m_isOver = true;
}

void SeedInventoryButton::setOut()
{
	if (m_isOver == true)
	{
		m_shape.setTextureRect(sf::IntRect(m_shape.getTextureRect().left, 1.f, m_shape.getTextureRect().width, m_shape.getTextureRect().height));
	}
	m_isOver = false;
}

void SeedInventoryButton::setPressed()
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

void SeedInventoryButton::setReleased()
{
	setOver();

	m_text.setCharacterSize(m_text.getCharacterSize() + 2);
	m_text.setOrigin(sf::Vector2f(m_text.getGlobalBounds().width / 2, m_text.getGlobalBounds().height / 2));

	m_isPressed = false;
}
