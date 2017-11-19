#pragma once
#include <iostream>
#include <string>
#include "Armor.h"
#include "Weapon.h"
#include "Backpack.h"
class Player
{
private:
	std::string name;
	int level;
	Armor armor;
	Weapon weapon;
	Backpack backpack;
public:
	Player();
	~Player();
	void setName(std::string n);
	void setLevel(int l);
	void setArmor(Armor a);
	void setWeapon(Weapon w);
	void setBackpack(Backpack b);
	void addBackpack(Weapon w, int c, Backpack b);
	void addBackpack(Armor a, int c, Backpack b);
	void addBackpack(Potion p, int c, Backpack b);
	int getWeaponCount(Backpack b);
	int getArmorCount(Backpack b);
	int getPotionCount(Backpack b);
	int getLevel();
	std::string getName();
	Armor getArmor();
	Weapon getWeapon();
	Backpack getBackpack();
};

