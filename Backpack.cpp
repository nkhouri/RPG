#include "Backpack.h"



void Backpack::setWeaponCount(int w)
{
	w = weaponCount;
}

void Backpack::setArmorCount(int a)
{
	a =  armorCount;
}

void Backpack::setPotionCount(int p)
{
	p  = potionCount;
}

void Backpack::setWeapon(Weapon w, int pos)
{
	weaponList[pos] = w;
}

void Backpack::setArmor(Armor a, int pos)
{
	armorList[pos] = a;
}

void Backpack::setPotion(Potion p, int pos)
{
	potionList[pos] = p;
}

int Backpack::getWeaponCount()
{
	return weaponCount;
}

int Backpack::getArmorCount()
{
	return armorCount;
}

int Backpack::getPotionCount()
{
	return potionCount;
}

Weapon Backpack::getWeapon(int pos)
{
	return weaponList[pos];
}

Armor Backpack::getArmor(int pos)
{
	return armorList[pos];
}

Potion Backpack::getPotion(int pos)
{
	return potionList[pos];
}

Backpack::Backpack()
{
}


Backpack::~Backpack()
{
}
