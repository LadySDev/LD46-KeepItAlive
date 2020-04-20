#include "Seed.h"

Seed::Seed(std::string name, int price, int aliment, int waterFrequency)
{
	m_name = name;
	m_price = price;
	m_aliment = aliment;
	m_waterFrequency = waterFrequency;
}

int Seed::getAlimentQuantity()
{
	return m_aliment;
}
