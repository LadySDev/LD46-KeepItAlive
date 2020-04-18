#include "Game.h"

int main()
{
	int index;
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
			scale = 0.66;
			break;

		}
	}
	
	Game* game = new Game(modes[index].width, modes[index].height, "LD46 Keep It Alive", scale);

	return 0;
}