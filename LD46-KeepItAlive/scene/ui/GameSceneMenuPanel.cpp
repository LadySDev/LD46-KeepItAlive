#include "GameSceneMenuPanel.h"

GameSceneMenuPanel::GameSceneMenuPanel(Game* game, GameScene* gameScene)
{
	m_game = game;
	m_gameScene = gameScene;

	m_shape.setSize(sf::Vector2f(300 * m_game->getScale(), 300 * m_game->getScale()));
	m_shape.setPosition(sf::Vector2f(m_game->getSize().x / 2, m_game->getSize().y / 2));
	m_shape.setOrigin(sf::Vector2f(m_shape.getGlobalBounds().width / 2, m_shape.getGlobalBounds().height / 2));
	m_shape.setFillColor(sf::Color::White);

	m_colorText = sf::Color(239, 132, 100);

	//Button Resume
	sf::RectangleShape shapeResume = *m_game->getResource()->getShape("mainTitleButtonOut");
	shapeResume.setPosition(sf::Vector2f(m_shape.getPosition().x, m_shape.getPosition().y - shapeResume.getGlobalBounds().height - 5));
	shapeResume.setOrigin(sf::Vector2f(shapeResume.getGlobalBounds().width / 2, shapeResume.getGlobalBounds().height / 2));

	sf::Text textResume;
	textResume.setFont(*m_game->getResource()->getFont("eternityTime"));
	textResume.setCharacterSize(20 * m_game->getScale());
	textResume.setFillColor(m_colorText);
	textResume.setString("RESUME");
	textResume.setPosition(sf::Vector2f(shapeResume.getPosition().x, shapeResume.getPosition().y));
	textResume.setOrigin(sf::Vector2f(textResume.getGlobalBounds().width / 2, textResume.getGlobalBounds().height / 2));
	
	m_btnResume = new Button(shapeResume, textResume);
	m_btnResume->onClick = [this] {
		m_gameScene->inactiveMenu();
	};

	//Button New Game
	sf::RectangleShape shapeNewGame = *m_game->getResource()->getShape("mainTitleButtonOut");
	shapeNewGame.setPosition(sf::Vector2f(shapeResume.getPosition().x, shapeResume.getPosition().y + shapeResume.getSize().y + 5));
	shapeNewGame.setOrigin(sf::Vector2f(shapeNewGame.getGlobalBounds().width / 2, shapeNewGame.getGlobalBounds().height / 2));

	sf::Text textNewGame;
	textNewGame.setFont(*m_game->getResource()->getFont("eternityTime"));
	textNewGame.setCharacterSize(20 * m_game->getScale());
	textNewGame.setFillColor(m_colorText);
	textNewGame.setString("NEW GAME");
	textNewGame.setPosition(sf::Vector2f(shapeNewGame.getPosition().x, shapeNewGame.getPosition().y));
	textNewGame.setOrigin(sf::Vector2f(textNewGame.getGlobalBounds().width / 2, textNewGame.getGlobalBounds().height / 2));
	
	m_btnNewGame = new Button(shapeNewGame, textNewGame);
	m_btnNewGame->onClick = [this] {
		m_game->launchGameScene();
	};

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

	m_btnQuit = new Button(shapeQuit, textQuit);
	m_btnQuit->onClick = [this] {
		m_game->close();
	};
}

void GameSceneMenuPanel::processEvent(sf::Event event, sf::Vector2f mousePosition)
{
	m_btnResume->processEvent(event, mousePosition);
	m_btnNewGame->processEvent(event, mousePosition);
	m_btnQuit->processEvent(event, mousePosition);
}

void GameSceneMenuPanel::update(sf::Time deltaTime)
{
	m_btnResume->update(deltaTime);
	m_btnNewGame->update(deltaTime);
	m_btnQuit->update(deltaTime);
}

void GameSceneMenuPanel::render(sf::RenderWindow* window)
{
	window->draw(m_shape);

	//BUTTON RESUME
	m_btnResume->render(window);

	//BUTTON NEW GAME
	m_btnNewGame->render(window);

	//BUTTON QUIT
	m_btnQuit->render(window);
}
