#include "Player.h"


Player::Player()
{
	level = 1;
	name = "";
	armor = Armor();
	weapon = Weapon();
}


Player::~Player()
{
}

void Player::setName(std::string n)
{
	name = n;
}

std::string Player::getName()
{
	return std::string();
}

void Player::setLevel(int l)
{
	level = l;
}

int Player::getLevel()
{
	return 0;
}

void Player::setArmor(Armor a)
{
	armor = a;
}

Armor Player::getArmor()
{
	return Armor();
}

void Player::setWeapon(Weapon w)
{
	weapon = w;
}

Weapon Player::getWeapon()
{
	return Weapon();
}
