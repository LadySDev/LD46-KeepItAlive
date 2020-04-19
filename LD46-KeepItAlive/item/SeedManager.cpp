#include "SeedManager.h"

SeedManager::SeedManager()
{
	m_seeds["eggplant"] = new Seed("eggplant", 20, 30);
}

Seed* SeedManager::getSeed(std::string name)
{
	return m_seeds[name];
}
