#include "Game.h"

int main()
{
	int index = -1;
	float scale = 1;
	//Video Mode
	std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
	for (std::size_t i=0; i<modes.size();++i)
	{
		sf::VideoMode mode = modes[i];
		
		if (mode.width == 1920 && mode.height == 1080)
		{
			index = i;
			scale = 1;
			break;
		}
		else if (mode.width == 1280 && mode.height == 720)
		{
			index = i;
			scale = (1280.f/1920.f);
			break;
		}
		
	}
	
	if (index != -1)
	{
		Game* game = new Game(modes[index].width, modes[index].height, "LD46 Keep It Alive", scale);
	}
	else
	{
		Game* game = new Game(1280, 720, "LD46 Keep It Alive", scale);
	}

	return 0;
}