#include "Weapon.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

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

void Weapon::generateWeapon(int c) //c is player level
{
	srand(time(NULL)); //set the new seed for the generation

	std::string noun[100]; //hold a max of 100 nouns
	std::string adjetive[100]; //hold a max of 100 adjetives
	std::ifstream input;
	input.open("weaponNoun.txt");
	int nCount = 0;
	while (!input.eof()) {
		input >> noun[nCount];
		nCount++;
	}
	input.close();
	input.open("adjetive.txt");
	int aCount = 0;
	while (!input.eof()) {
		input >> adjetive[aCount];
		aCount++;
	}
	std::string nameNoun = noun[(rand() % nCount)];
	std::string nameAdjetive = adjetive[(rand() % aCount)];
	//store the name into the weapon
	name = nameAdjetive + " " + nameNoun;
	//set the level based on the players level
	if (c <= 5) {
		level = 1;
	}
	else {
		level = (rand() % c) + 5;
	}
	//set the damage based on the players level
	//added set multipliers to damage to have a better loot outcome based of player level;

	int dmg = (rand() % level) + 2;
	if (c < 15) {
		dmg = dmg * 1.2; //20% inclrease base
	}
	else if (c >= 15 && c < 30) {
		dmg = dmg * 1.6; //60% increase at lvl 15
	}
	else {
		dmg = dmg * 2; //100% increase at 30+
	}
	damage = dmg;
}

void Weapon::printWeapon()
{
	std::cout << name << std::endl;
	std::cout << "Level: " << level << std::endl;
	std::cout << "Damage: " << damage << std::endl;
}
