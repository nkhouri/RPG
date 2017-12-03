#pragma once
#include <string>

class Weapon
{
private:
	std::string name;
	int level;
	int damage;
	int price;
public:
	Weapon();
	~Weapon();
	void setName(std::string n);
	std::string getName();
	void setLevel(int l);
	int getLevel();
	void setDamage(int d);
	int getDamage();
	void setPrice(int);
	int getPrice();

	void generateWeapon(int);
	void printWeapon();
};

