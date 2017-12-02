#include "Weapon.h"
#include <fstream>
#include <cstdlib>

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
	return name;
}

void Weapon::setLevel(int l)
{
	level = l;
}

int Weapon::getLevel()
{
	return level;
}

void Weapon::setDamage(int d)
{
	damage = d;
}

int Weapon::getDamage()
{
	return damage;
}