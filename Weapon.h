#pragma once
#include <string>

class Weapon
{
private:
	std::string name;
	int level;
	int damage;
public:
	Weapon();
	~Weapon();
	void setName(std::string n);
	std::string getName();
	void setLevel(int l);
	int getLevel();
	void setDamage(int d);
	int getDamage();

	void generateWeapon(int);
	void printWeapon();
};

