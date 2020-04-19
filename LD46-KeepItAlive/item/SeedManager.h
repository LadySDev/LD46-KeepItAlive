#pragma once

#include <map>
#include "Seed.h"

class SeedManager
{
public:
	SeedManager();
	Seed* getSeed(std::string name);
private:
	std::map<std::string, Seed*> m_seeds;
};