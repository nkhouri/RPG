#include "Weapon.h"



Weapon::Weapon()
{
	name = "Rusty Sword";
	level = 1;
	damage = 1;
}


Weapon::~Weapon()
{
}

void Weapon::setName(std::string n)
{
	name = n;
}

std::string Weapon::getName()
{
	return std::string();
}

void Weapon::setLevel(int l)
{
	level = l;
}

int Weapon::getLevel()
{
	return 0;
}

void Weapon::setDamage(int d)
{
	damage = d;
}

int Weapon::getDamage()
{
	return 0;
}
