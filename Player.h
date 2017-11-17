#pragma once
#include <iostream>
#include <string>
#include "Armor.h"
#include "Weapon.h"
class Player
{
private:
	std::string name;
	int level;
	Armor armor;
	Weapon weapon;
public:
	Player();
	~Player();
	void setName(std::string n);
	std::string getName();
	void setLevel(int l);
	int getLevel();
	void setArmor(Armor a);
	Armor getArmor();
	void setWeapon(Weapon w);
	Weapon getWeapon();
};

