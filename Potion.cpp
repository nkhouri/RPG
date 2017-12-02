#include "Potion.h"
#include <ctime>
#include <iostream>

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

void Potion::generatePotion()
{
	srand(time(NULL));

	int potionLevel = (rand() % 4) + 1;
	switch (potionLevel) {
	case 1:
		name = "Small Potion";
		healingPower = 10;
		break;
	case 2:
		name = "Standard Potion";
		healingPower = 25;
		break;
	case 3:
		name = "Large Potion";
		healingPower = 50;
		break;
	case 4:
		name = "Epic Potion";
		healingPower = 100;
		break;
	}
}

void Potion::printPotion()
{
	std::cout << name << std::endl;
	std::cout << "Restores " << healingPower << "HP" << std::endl;
}
