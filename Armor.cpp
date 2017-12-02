#include "Armor.h"
#include <ctime>
#include <fstream>
#include <iostream>


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

void Armor::generateArmor(int c)
{
	srand(time(NULL)); //set the new seed for the generation

	std::string noun[100]; //hold a max of 100 nouns
	std::string adjetive[100]; //hold a max of 100 adjetives
	std::ifstream input;
	input.open("armorNoun.txt");
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

	int armor = (rand() % level) + 2;
	if (c < 15) {
		armor = armor * 1.5; //20% inclrease base
	}
	else if (c >= 15 && c < 30) {
		armor = armor * 1.8; //60% increase at lvl 15
	}
	else {
		armor = armor * 2.2; //100% increase at 30+
	}
	armorRating = armor;
}

void Armor::printArmor()
{
	std::cout << name << std::endl;
	std::cout << "Level: " << level << std::endl;
	std::cout << "Protection: " << armorRating << std::endl;
}
