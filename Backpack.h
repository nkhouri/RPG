#pragma once
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"

class Backpack
{
private:
	int weaponCount, armorCount, potionCount;
	Weapon weaponList[100];
	Armor armorList[100];
	Potion potionList[100];
public:
	void setWeaponCount(int w);
	void setArmorCount(int a);
	void setPotionCount(int p);
	void setWeapon(Weapon w, int pos);
	void setArmor(Armor a, int pos);
	void setPotion(Potion p, int pos);
	int getWeaponCount();
	int getArmorCount();
	int getPotionCount();
	Weapon getWeapon(int pos);
	Armor getArmor(int pos);
	Potion getPotion(int pos);

	Backpack();
	~Backpack();
};

