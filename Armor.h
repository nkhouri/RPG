#pragma once
#include <string>

class Armor
{
private:
	std::string name;
	int level;
	int armorRating;
public:
	Armor();
	~Armor();
	void setName(std::string n);
	std::string getName();
	void setLevel(int l);
	int getLevel();
	void setArmorRating(int r);
	int getArmorRating();

	void generateArmor(int);
	void printArmor();
};