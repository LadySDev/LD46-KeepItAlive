#pragma once

#include "item/Seed.h"
#include <map>
#include "item/SeedManager.h"

class Inventory
{
public:
	Inventory(SeedManager* seedManager);
	void addSeed(std::string name, int quantity);
	std::map<std::string, std::pair<Seed*, int>>* getSeeds();
private:
	SeedManager* m_seedManager;
	std::map<std::string, std::pair<Seed*, int>> m_seeds;
};