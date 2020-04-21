#include "Resource.h"

Resource::Resource(float scale)
{
	m_assetPath = "asset/";
	m_scale = scale;

	//AUDIO
	if (!m_bufferMusicTitle.loadFromFile(m_assetPath + "Music-title.wav"))
	{
		EXIT_FAILURE;
	}

	if (!m_bufferBtnOver.loadFromFile(m_assetPath + "blop_2-over.wav"))
	{
		EXIT_FAILURE;
	}

	if (!m_bufferBtnPressed.loadFromFile(m_assetPath + "blop_1-pressed.wav"))
	{
		EXIT_FAILURE;
	}

	//MAIN TITLE
	if (m_mainTitleBG.loadFromFile(m_assetPath + "Ecran_titre_1.2.bmp"))
	{
		EXIT_FAILURE;
	}

	if (m_mainTitleUI.loadFromFile(m_assetPath + "MainTitleUI.png"))
	{
		EXIT_FAILURE;
	}

	//FONT
	if (m_EternityTime.loadFromFile(m_assetPath + "Eternity Time.ttf"))
	{
		EXIT_FAILURE;
	}

	//GAME DAY ACTIONS
	if (m_gameDayActions.loadFromFile(m_assetPath + "GameDayActions.png"))
	{
		EXIT_FAILURE;
	}

	//ITEMS
	if (m_items.loadFromFile(m_assetPath + "GameDayActions.png"))
	{
		EXIT_FAILURE;
	}

	//GAME DAY FIELD
	if (m_gameDayField.loadFromFile(m_assetPath + "GameDayField.png"))
	{
		EXIT_FAILURE;
	}

	if (m_charactersPhoto.loadFromFile(m_assetPath + "Visages.png"))
	{
		EXIT_FAILURE;
	}

	if (m_field.loadFromFile(m_assetPath + "Champs.png"))
	{
		EXIT_FAILURE;
	}

	create();
}

void Resource::create()
{
	m_shapeMainTitleBG.setSize(sf::Vector2f(1920.f * m_scale, 1080.f * m_scale));
	m_shapeMainTitleBG.setTexture(&m_mainTitleBG);
	m_shapeMainTitleBG.setTextureRect(sf::IntRect(0.f, 0.f, 1920.f, 1080.f));

	//Shape Button
	m_mainTitleButtonOut.setSize(sf::Vector2f(198.f * m_scale, 50.f * m_scale));
	m_mainTitleButtonOut.setTexture(&m_mainTitleUI);
	m_mainTitleButtonOut.setTextureRect(sf::IntRect(151.f, 1.f, 198.f, 50.f));

	//Shape Action
	m_gameDayActionUnchecked.setSize(sf::Vector2f(50.f * m_scale, 50.f * m_scale));
	m_gameDayActionUnchecked.setTexture(&m_gameDayActions);
	m_gameDayActionUnchecked.setTextureRect(sf::IntRect(0.f, 0.f, 50.f, 50.f));

	m_gameDayActionChecked.setSize(sf::Vector2f(50.f * m_scale, 50.f * m_scale));
	m_gameDayActionChecked.setTexture(&m_gameDayActions);
	m_gameDayActionChecked.setTextureRect(sf::IntRect(0.f, 50.f, 50.f, 50.f));

	m_gameDayActionButtonOut.setSize(sf::Vector2f(264.f * m_scale, 50.f * m_scale));
	m_gameDayActionButtonOut.setTexture(&m_gameDayActions);
	m_gameDayActionButtonOut.setTextureRect(sf::IntRect(52.f, 1.f, 264.f, 50.f));

	m_gameDayActionVerticalBar.setSize(sf::Vector2f(16.f * m_scale, 459.f * m_scale));
	m_gameDayActionVerticalBar.setTexture(&m_gameDayActions);
	m_gameDayActionVerticalBar.setTextureRect(sf::IntRect(317.f, 1.f, 16.f, 459.f));

	//ITEMS
	m_itemEggplant.setSize(sf::Vector2f(36.f * m_scale, 36.f * m_scale));
	m_itemEggplant.setTexture(&m_items);
	m_itemEggplant.setTextureRect(sf::IntRect(0.f, 0.f, 36.f, 36.f));

	//GAME DAY FIELD
	//Shape Border Character
	m_shapeBorderCharacter.setSize(sf::Vector2f(182.f * m_scale, 235.f * m_scale));
	m_shapeBorderCharacter.setTexture(&m_gameDayField);
	m_shapeBorderCharacter.setTextureRect(sf::IntRect(1.f, 1.f, 182.f, 235.f));

	//Shape Photo Player
	m_shapePlayer.setSize(sf::Vector2f(165.f * m_scale, 218.f * m_scale));
	m_shapePlayer.setTexture(&m_charactersPhoto);
	m_shapePlayer.setTextureRect(sf::IntRect(1030.f, 290.f, 335.f, 429.f));

	//Shape Photo Children
	m_shapeChildren.setSize(sf::Vector2f(165.f * m_scale, 218.f * m_scale));
	m_shapeChildren.setTexture(&m_charactersPhoto);
	m_shapeChildren.setTextureRect(sf::IntRect(1415.f, 260.f, 335.f, 429.f));

	//Shape Border Character State
	m_shapeBorderCharacterState.setSize(sf::Vector2f(182.f * m_scale, 50.f * m_scale));
	m_shapeBorderCharacterState.setTexture(&m_gameDayField);
	m_shapeBorderCharacterState.setTextureRect(sf::IntRect(197.f, 1.f, 182.f, 50.f));

	//Shape Character State
	m_shapeCharacterState.setSize(sf::Vector2f(166.f * m_scale, 34.f * m_scale));
	m_shapeCharacterState.setTexture(&m_gameDayField);
	m_shapeCharacterState.setTextureRect(sf::IntRect(205.f, 52.f, 166.f, 34.f));

	//Shape field
	m_shapeField.setSize(sf::Vector2f(1336.f * m_scale, 1080.f * m_scale));
	m_shapeField.setTexture(&m_field);
	m_shapeField.setTextureRect(sf::IntRect(0.f, 0.f, 1336.f, 1080.f));

	//Shape field selection
	m_shapeFieldSelection.setSize(sf::Vector2f(94.f * m_scale, 94.f * m_scale));
	m_shapeFieldSelection.setTexture(&m_gameDayField);
	m_shapeFieldSelection.setTextureRect(sf::IntRect(380.f, 1.f, 94.f, 94.f));
}

sf::RectangleShape* Resource::getShape(std::string name)
{
	if (name == "shapeMainTitleBG")
	{
		return &m_shapeMainTitleBG;
	}
	else if (name == "mainTitleButtonOut")
	{
		return &m_mainTitleButtonOut;
	}
	else if (name == "gameDayActionUnchecked")
	{
		return &m_gameDayActionUnchecked;
	}
	else if (name == "gameDayActionChecked")
	{
		return&m_gameDayActionChecked;
	}
	else if (name == "gameDayActionButtonOut")
	{
		return&m_gameDayActionButtonOut;
	}
	else if (name == "gameDayActionVerticalBar")
	{
		return&m_gameDayActionVerticalBar;
	}
	else if (name == "itemEggplant")
	{
		return&m_itemEggplant;
	}
	else if (name == "shapeBorderCharacter")
	{
		return&m_shapeBorderCharacter;
	}
	else if (name == "shapePlayer")
	{
		return&m_shapePlayer;
	}
	else if (name == "shapeChildren")
	{
		return&m_shapeChildren;
	}
	else if (name == "shapeBorderCharacterState")
	{
		return&m_shapeBorderCharacterState;
	}
	else if (name == "shapeCharacterState")
	{
		return&m_shapeCharacterState;
	}
	else if (name == "shapeField")
	{
		return&m_shapeField;
	}
	else if (name == "shapeFieldSelection")
	{
		return&m_shapeFieldSelection;
	}
	else
	{
		return nullptr;
	}
}

sf::Font* Resource::getFont(std::string name)
{
	if (name == "eternityTime")
	{
		return &m_EternityTime;
	}
	else
	{
		return nullptr;
	}
}

sf::SoundBuffer* Resource::getBuffer(std::string name)
{
	if (name == "btnOver")
	{
		return &m_bufferBtnOver;
	}
	else if (name == "btnPressed")
	{
		return &m_bufferBtnPressed;
	}
	else if (name == "musicTitle")
	{
		return &m_bufferMusicTitle;
	}
	else
	{
		return nullptr;
	}
}
