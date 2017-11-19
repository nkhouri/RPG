#include "Potion.h"

void Potion::setName(std::string n)
{
	name = n;
}

void Potion::setHealingPower(int h)
{
	healingPower = h;
}

std::string Potion::getName()
{
	return name;
}

int Potion::getHealingPower()
{
	return healingPower;
}

Potion::Potion()
{
	name = "";
	healingPower = 0;
}


Potion::~Potion()
{
}
