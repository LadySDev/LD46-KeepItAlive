#include "Player.h"

Player::Player(Game* game)
{
	m_game = game;

	m_borderPhoto = *m_game->getResource()->getShape("shapeBorderCharacter");
	m_borderPhoto.setPosition(sf::Vector2f(0, 0));
	m_borderPhoto.setOrigin(sf::Vector2f(0, 0));

	m_shapePhoto = *m_game->getResource()->getShape("shapePlayer");
	m_shapePhoto.setPosition(sf::Vector2f(m_borderPhoto.getPosition().x + (8 * m_game->getScale()), m_borderPhoto.getPosition().y + (8 * m_game->getScale())));
	m_shapePhoto.setOrigin(sf::Vector2f(0, 0));

	m_borderState = *m_game->getResource()->getShape("shapeBorderCharacterState");
	m_borderState.setPosition(sf::Vector2f(m_borderPhoto.getPosition().x, m_borderPhoto.getPosition().y + m_borderPhoto.getGlobalBounds().height - (0.4 * m_game->getScale())));
	m_borderState.setOrigin(sf::Vector2f(0, 0));

	m_shapeState = *m_game->getResource()->getShape("shapeCharacterState");
	m_shapeState.setPosition(sf::Vector2f(m_borderState.getPosition().x + (8 * m_game->getScale()), m_borderState.getPosition().y + (8 * m_game->getScale())));
	m_shapeState.setOrigin(sf::Vector2f(0, 0));
}

void Player::setState(std::string state)
{
	m_state = state;
}

void Player::setAlimentQuantity(int quantity)
{
	m_alimentQuantity = quantity;
}

void Player::setPosition(sf::Vector2f position)
{
	m_borderPhoto.setPosition(position);
	m_shapePhoto.setPosition(sf::Vector2f(m_borderPhoto.getPosition().x + (8 * m_game->getScale()), m_borderPhoto.getPosition().y + (8 * m_game->getScale())));
	m_borderState.setPosition(sf::Vector2f(m_borderPhoto.getPosition().x, m_borderPhoto.getPosition().y + m_borderPhoto.getGlobalBounds().height - (0.4 * m_game->getScale())));
	m_shapeState.setPosition(sf::Vector2f(m_borderState.getPosition().x + (8 * m_game->getScale()), m_borderState.getPosition().y + (8 * m_game->getScale())));
}

void Player::update(sf::Time deltaTime)
{
	if (m_state == m_game->getCharacterStates().at(0)) //satiated
	{
		m_shapeState.setTextureRect(sf::IntRect(m_shapeState.getTextureRect().left, 52.f, m_shapeState.getTextureRect().width, m_shapeState.getTextureRect().height));
	}
	else if (m_state == m_game->getCharacterStates().at(1)) //hungry
	{
		m_shapeState.setTextureRect(sf::IntRect(m_shapeState.getTextureRect().left, 87.f, m_shapeState.getTextureRect().width, m_shapeState.getTextureRect().height));
	}
	else if (m_state == m_game->getCharacterStates().at(2)) //starved
	{
		m_shapeState.setTextureRect(sf::IntRect(m_shapeState.getTextureRect().left, 122.f, m_shapeState.getTextureRect().width, m_shapeState.getTextureRect().height));
	}
	else if (m_state == m_game->getCharacterStates().at(3)) //dead
	{
		m_shapeState.setTextureRect(sf::IntRect(m_shapeState.getTextureRect().left, 157.f, m_shapeState.getTextureRect().width, m_shapeState.getTextureRect().height));
	}
}

void Player::render(sf::RenderWindow* window)
{
	window->draw(m_borderPhoto);
	window->draw(m_shapePhoto);
	window->draw(m_borderState);
	window->draw(m_shapeState);
}
