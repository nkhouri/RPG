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
	Armor tmp;
	armorInventory[aLength] = a;
	for (int i = aLength; i > 0; i--) {
		if (armorInventory[i].getName() <= armorInventory[i + 1].getName()) {
			tmp = armorInventory[i + 1];
			armorInventory[i + 1] = armorInventory[i];
			armorInventory[i] = tmp;
		}
	}
	aLength++;
}

void Player::insert(Weapon w)
{
	Weapon tmp;
	weaponInventory[wLength] = w;
	for (int i = wLength; i > 0; i--) {
		if (weaponInventory[i].getName() <= weaponInventory[i + 1].getName()) {
			tmp = weaponInventory[i + 1];
			weaponInventory[i + 1] = weaponInventory[i];
			weaponInventory[i] = tmp;
		}
	}
	wLength++;
}

void Player::insert(Potion p)
{
	potionInventory[pLength] = p;
	pLength++;
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
