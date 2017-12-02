#pragma once
#include <iostream>
#include <string>
#include "Armor.h"
#include "Weapon.h"
#include "Backpack.h"

const int MAX_ITEMS = 1000;
class Player
{
private:
	std::string name;
	int level;
	int health;
	int gold;
	Armor armor;
	Weapon weapon;

	//make 3 arrays for the 3 different items
	Armor armorInventory[MAX_ITEMS]; //sorted array
	Weapon weaponInventory[MAX_ITEMS]; //sorted array
	Potion potionInventory[MAX_ITEMS]; //sorted array
	int aLength, wLength, pLength; //lengths for the arays
public:
	Player();
	~Player();
	void setName(std::string n);
	void setLevel(int l);
	void setArmor(Armor a);
	void setWeapon(Weapon w);
	int getLevel();
	std::string getName();
	Armor getArmor();
	Weapon getWeapon();

	//define the functions for the 3 arrays
	void insert(Armor);
	void insert(Weapon);
	void insert(Potion);
	void removeArmor(int);
	void removeWeapon(int);
	void removePotion(int);

};

