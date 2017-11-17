#include "Armor.h"



Armor::Armor()
{
	name = "Rusty Chestpiece";
	level = 1;
	armorRating = 1;
}


Armor::~Armor()
{
}

void Armor::setName(std::string n)
{
	name = n;
}

std::string Armor::getName()
{
	return std::string();
}

void Armor::setLevel(int l)
{
	level = l;
}

int Armor::getLevel()
{
	return level;
}

void Armor::setArmorRating(int r)
{
	armorRating = r;
}

int Armor::getArmorRating()
{
	return armorRating;
}
