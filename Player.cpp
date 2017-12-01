#include "Player.h"


Player::Player()
{
	level = 1;
	name = "";
	armor = Armor();
	weapon = Weapon();
	health = 10;
	gold = 0;

	aLength = 0;
	wLength = 0;
	pLength = 0;
	//the arrays are defined as empty
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
	return level;
}

void Player::setArmor(Armor a)
{
	armor = a;
}

Armor Player::getArmor()
{
	return armor;
}

void Player::setWeapon(Weapon w)
{
	weapon = w;
}

Weapon Player::getWeapon()
{
	return weapon;
}

void Player::insert(Armor a)
{
}

void Player::insert(Weapon w)
{
}

void Player::insert(Potion p)
{
}

void Player::remove(Armor a)
{
}

void Player::remove(Weapon w)
{
}

void Player::remove(Potion p)
{
}
