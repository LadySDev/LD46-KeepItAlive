#include "Field.h"

Field::Field(Game* game, GameScene* gamescene, sf::ConvexShape shape)
{
	m_game = game;
	m_gamescene = gamescene;
	m_shape = shape;

	m_shape.setFillColor(sf::Color::Black);
}

void Field::plant(std::string name)
{
	m_seed = m_gamescene->getSeedManager()->getSeed(name);
	m_plantAge = 1;
}

void Field::water()
{
	m_water.push_back(true);
}

int Field::harvest()
{
	int alimentQuantity = m_seed->getAlimentQuantity();

	losePlant();

	return alimentQuantity;
}

void Field::losePlant()
{
	m_seed = NULL;
	m_plantAge = 0;
	m_water = std::vector<bool>();
}

void Field::processEvent(sf::Event event, sf::Vector2f mousePosition)
{
}

void Field::update(sf::Time deltaTime)
{
}

void Field::render(sf::RenderWindow* window)
{
	window->draw(m_shape);
}
