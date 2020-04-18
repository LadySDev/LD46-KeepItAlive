#include "MainTitlePanel.h"

MainTitlePanel::MainTitlePanel(Game* game, sf::Vector2f size, sf::Vector2f position, sf::Vector2f origin)
{
	m_game = game;

	m_shape.setSize(size);
	m_shape.setPosition(position);
	m_shape.setOrigin(origin);

	m_colorText = sf::Color::Green;

	//BUTTON NEW GAME
	sf::RectangleShape shapeNewGame = *m_game->getResource()->getShape("mainTitleButtonOut");
	shapeNewGame.setPosition(sf::Vector2f(m_shape.getPosition().x, m_shape.getPosition().y - shapeNewGame.getGlobalBounds().height / 2 - 5));
	shapeNewGame.setOrigin(sf::Vector2f(shapeNewGame.getGlobalBounds().width / 2, shapeNewGame.getGlobalBounds().height / 2));

	sf::Text textNewGame;
	textNewGame.setFont(*m_game->getResource()->getFont("eternityTime"));
	textNewGame.setCharacterSize(20 * m_game->getScale());
	textNewGame.setFillColor(m_colorText);
	textNewGame.setString("NEW GAME");
	textNewGame.setPosition(sf::Vector2f(shapeNewGame.getPosition().x, shapeNewGame.getPosition().y));
	textNewGame.setOrigin(sf::Vector2f(textNewGame.getGlobalBounds().width / 2, textNewGame.getGlobalBounds().height / 2));

	m_btnNewGame = new MainTitleButton(shapeNewGame, textNewGame);
	m_btnNewGame->onClick = [this] {};

	//BUTTON QUIT
	sf::RectangleShape shapeQuit = *m_game->getResource()->getShape("mainTitleButtonOut");
	shapeQuit.setPosition(sf::Vector2f(shapeNewGame.getPosition().x, shapeNewGame.getPosition().y + shapeNewGame.getSize().y + 5));
	shapeQuit.setOrigin(sf::Vector2f(shapeQuit.getGlobalBounds().width / 2, shapeQuit.getGlobalBounds().height / 2));

	sf::Text textQuit;
	textQuit.setFont(*m_game->getResource()->getFont("eternityTime"));
	textQuit.setCharacterSize(20 * m_game->getScale());
	textQuit.setFillColor(m_colorText);
	textQuit.setString("QUIT");
	textQuit.setPosition(sf::Vector2f(shapeQuit.getPosition().x, shapeQuit.getPosition().y));
	textQuit.setOrigin(sf::Vector2f(textQuit.getGlobalBounds().width / 2, textQuit.getGlobalBounds().height / 2));

	m_btnQuit = new MainTitleButton(shapeQuit, textQuit);
	m_btnQuit->onClick = [this] {
		m_game->close();
	};
}

void MainTitlePanel::processEvent(sf::Event event, sf::Vector2f mousePosition)
{
	m_btnNewGame->processEvent(event, mousePosition);
	m_btnQuit->processEvent(event, mousePosition);
}

void MainTitlePanel::update(sf::Time deltaTime)
{
	m_btnNewGame->update(deltaTime);
	m_btnQuit->update(deltaTime);
}

void MainTitlePanel::render(sf::RenderWindow* window)
{
	window->draw(m_shape);

	//BUTTON NEW GAME
	m_btnNewGame->render(window);

	//BUTTON QUIT
	m_btnQuit->render(window);
}
