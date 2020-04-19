#include "Inventory.h"

Inventory::Inventory(SeedManager* seedManager)
{
	m_seedManager = seedManager;
}

void Inventory::addSeed(std::string name, int quantity)
{
	std::map<std::string, std::pair<Seed*, int>>::const_iterator it = m_seeds.find(name);
	if (it != m_seeds.end())
	{
		m_seeds[name].second = m_seeds[name].second + quantity;
	}
	else {
		m_seeds[name] = std::pair<Seed*, int>(m_seedManager->getSeed(name), quantity);
	}
}

std::map<std::string, std::pair<Seed*, int>>* Inventory::getSeeds()
{
	return &m_seeds;
}
