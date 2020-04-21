#pragma once

#include <string>

class Seed
{
public:
	Seed(std::string name, int price, int aliment, int waterFrequency);

	std::string getName();
	int getAlimentQuantity();
private:
	std::string m_name;
	int m_price;
	int m_aliment;
	int m_waterFrequency;
};