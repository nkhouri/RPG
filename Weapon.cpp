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
	return std::string();
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

Weapon Weapon::generateWeapon(int c) //c is player level
{
	std::string noun[100]; //hold a max of 100 nouns
	std::string adjetive[100]; //hold a max of 100 adjetives
	std::ifstream input;
	input.open("noun.txt");
	int nCount = 0;
	while (!input.eof()) {
		input >> noun[nCount];
	}
	input.close();
	input.open("adjetive.txt");
	int aCount = 0;
	while (!input.eof()) {
		input >> adjetive[aCount];
	}
	Weapon w = Weapon();
	std::string nameNoun = noun[(rand() % nCount) + 1];
	std::string nameAdjetive = adjetive[(rand() % aCount) + 1];
	//store the name into the weapon
	w.setName(nameNoun + " " + nameAdjetive);
	//set the level based on the players level
	if (c > 5) {
		w.setLevel(1);
	}
	else {
		int level = (rand() % c) + 5;
		w.setLevel(level);
	}
	//set the damage based on the players level
	//added set multipliers to damage to have a better loot outcome based of player level;

	int damage = (rand() % c) + 5;
	if (c < 15) {
		damage = damage * 1.2; //20% inclrease base
	}
	else if (c >= 15 && c < 30) {
		damage = damage * 1.6; //60% increase at lvl 15
	}
	else {
		damage = damage * 2; //100% increase at 30+
	}
	w.setDamage(damage);

	return w;
}
