#pragma once
#include<string>

class Potion
{
private:
	std::string name;
	int healingPower;
public:
	void setName(std::string n);
	void setHealingPower(int h);
	std::string getName();
	int getHealingPower();
	Potion();
	~Potion();
};