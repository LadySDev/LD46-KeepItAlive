#include "Field.h"

Field::Field(Game* game, GameScene* gamescene, sf::ConvexShape shape)
{
	m_game = game;
	m_gamescene = gamescene;
	m_shape = shape;

	m_shape.setFillColor(sf::Color::Black);

	m_shapeSelection = *m_game->getResource()->getShape("shapeFieldSelection");
	m_shapeSelection.setOrigin(sf::Vector2f(m_shapeSelection.getGlobalBounds().width / 2, m_shapeSelection.getGlobalBounds().height / 2));

	m_soundBtnOver.setBuffer(*m_game->getResource()->getBuffer("btnOver"));
	m_soundBtnOver.setVolume(10.f);

	m_soundBtnPressed.setBuffer(*m_game->getResource()->getBuffer("btnPressed"));
	m_soundBtnPressed.setVolume(10.f);

	m_isOver = false;
	m_isPressed = false;

	m_isForPlant = false;
	m_isForWater = false;
	m_isForHarvest = false;
}

void Field::setSelectionPosition(sf::Vector2f position)
{
	m_shapeSelection.setPosition(position);
}

void Field::setIsForPlant()
{
	if (m_seed == NULL)
	{
		m_isForPlant = true;
	}
}

bool Field::isForPlant()
{
	return m_isForPlant;
}

void Field::setIsForWater()
{
	if (m_seed != NULL)
	{
		m_isForWater = true;
	}
}

bool Field::isForWater()
{
	return m_isForWater;
}

void Field::setIsForHarvest()
{
	if (m_seed != NULL)
	{
		m_isForHarvest = true;
	}
}

bool Field::isForHarvest()
{
	return m_isForHarvest;
}

void Field::endSelection()
{
	m_isForPlant = false;
	m_isForWater = false;
	m_isForHarvest = false;
}

bool Field::isSeedEmpty()
{
	return m_seed == NULL;
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

bool Field::processEvent(sf::Event event, sf::Vector2f mousePosition)
{
	bool eventFound = false;

	if (isInsideField(mousePosition) && m_isOver == false)
	{
		if ((m_isForPlant == true && m_seed == NULL)
			|| (m_isForWater == true && m_seed != NULL)
			|| (m_isForHarvest == true && m_seed != NULL))
		{
			m_soundBtnOver.play();
			setOver();
		}
	}
	else if (!isInsideField(mousePosition) && m_isOver == true)
	{
		if ((m_isForPlant == true && m_seed == NULL)
			|| (m_isForWater == true && m_seed != NULL)
			|| (m_isForHarvest == true && m_seed != NULL))
		{
			setOut();
		}
	}

	if (isInsideField(mousePosition) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if ((m_isForPlant == true && m_seed == NULL)
			|| (m_isForWater == true && m_seed != NULL)
			|| (m_isForHarvest == true && m_seed != NULL))
		{
			eventFound = true;
			m_soundBtnPressed.play();
			setPressed();
			onClick();
		}
	}
	else if (m_isPressed == true && !sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		setReleased();
	}

	return eventFound;
}

void Field::update(sf::Time deltaTime)
{
}

void Field::render(sf::RenderWindow* window)
{
	window->draw(m_shape);

	if ((m_isForPlant == true && m_seed == NULL)
		|| (m_isForWater && m_seed != NULL)
		|| (m_isForHarvest && m_seed != NULL))
	{
		window->draw(m_shapeSelection);
	}	
}

void Field::setOver()
{
	if (m_isOver == false)
	{
		m_shapeSelection.setTextureRect(sf::IntRect(m_shapeSelection.getTextureRect().left, 96, m_shapeSelection.getTextureRect().width, m_shapeSelection.getTextureRect().height));
	}
	m_isOver = true;
}

void Field::setOut()
{
	if (m_isOver == true)
	{
		m_shapeSelection.setTextureRect(sf::IntRect(m_shapeSelection.getTextureRect().left, 1, m_shapeSelection.getTextureRect().width, m_shapeSelection.getTextureRect().height));
	}
	m_isOver = false;
}

void Field::setPressed()
{
	if (m_isPressed == false)
	{
		m_shapeSelection.setTextureRect(sf::IntRect(m_shapeSelection.getTextureRect().left, 199, m_shapeSelection.getTextureRect().width, m_shapeSelection.getTextureRect().height));
	}
	m_isOver = false;
	m_isPressed = true;
}

void Field::setReleased()
{
	setOver();
	

	m_isPressed = false;
}

bool Field::isInsideTriangle(sf::Vector2f pointT0, sf::Vector2f pointT1, sf::Vector2f pointT2, sf::Vector2f point)
{
	//First
	int valDefault1 = (pointT0.x - pointT1.x) * (pointT0.y - pointT2.y) -
		(pointT0.y - pointT1.y) * (pointT0.x - pointT2.x);
	int valFound1 = (pointT0.x - pointT1.x) * (pointT0.y - point.y) -
		(pointT0.y - pointT1.y) * (pointT0.x - point.x);

	bool  first = (valDefault1 >= 0 && valFound1 >= 0) || (valDefault1 <= 0 && valFound1 <= 0);

	//Second
	int valDefault2 = (pointT1.x - pointT2.x) * (pointT1.y - pointT0.y) -
		(pointT1.y - pointT2.y) * (pointT1.x - pointT0.x);
	int valFound2 = (pointT1.x - pointT2.x) * (pointT1.y - point.y) -
		(pointT1.y - pointT2.y) * (pointT1.x - point.x);

	bool  second = (valDefault2 >= 0 && valFound2 >= 0) || (valDefault2 <= 0 && valFound2 <= 0);

	//Third
	int valDefault3 = (pointT2.x - pointT0.x) * (pointT2.y - pointT1.y) -
		(pointT2.y - pointT0.y) * (pointT2.x - pointT1.x);
	int valFound3 = (pointT2.x - pointT0.x) * (pointT2.y - point.y) -
		(pointT2.y - pointT0.y) * (pointT2.x - point.x);

	bool  third = (valDefault3 >= 0 && valFound3 >= 0) || (valDefault3 <= 0 && valFound3 <= 0);

	return (first && second && third);
}

bool Field::isInsideField(sf::Vector2f mousePosition)
{
	bool isInsideTriangle1 = isInsideTriangle(m_shape.getPoint(0), m_shape.getPoint(1), m_shape.getPoint(2), mousePosition);
	bool isInsideTriangle2 = isInsideTriangle(m_shape.getPoint(2), m_shape.getPoint(3), m_shape.getPoint(0), mousePosition);

	return (isInsideTriangle1 || isInsideTriangle2);
}
