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

void Player::addBackpack(Armor a, int c, Backpack b)
{
	b.setArmor(a, c);
}

void Player::addBackpack(Potion p, int c, Backpack b)
{
	b.setPotion(p, c);
}

int Player::getWeaponCount(Backpack b)
{
	return b.getWeaponCount();
}

int Player::getArmorCount(Backpack b)
{
	return b.getArmorCount();
}

int Player::getPotionCount(Backpack b)
{
	return b.getArmorCount();
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

void Player::setBackpack(Backpack b)
{
}

void Player::addBackpack(Weapon w, int c, Backpack b)
{
	b.setWeapon(w, c);
}

Weapon Player::getWeapon()
{
	return weapon;
}

Backpack Player::getBackpack()
{
	return backpack;
}
