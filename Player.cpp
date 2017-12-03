#include "Player.h"
#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>

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


void Player::printArmorFromInventory(int c)
{
	armorInventory[c].printArmor();
}

void Player::printWeaponFromInventory(int c)
{
	weaponInventory[c].printWeapon();
}

void Player::insert(Armor a)
{
	armorInventory[aLength] = a;
	aLength++;
}

void Player::insert(Weapon w)
{
	weaponInventory[wLength] = w;
	wLength++;
}

void Player::insert(Potion p)
{
	potionInventory[pLength] = p;
	pLength++;
}

void Player::removeArmor(int c)
{
	Armor tmp;
	armorInventory[c] = Armor();
	for (int i = c; i > aLength; i++) {
		tmp = armorInventory[c + 1];
		armorInventory[c + 1] = armorInventory[c];
		armorInventory[c] = tmp;
	}
	aLength--;
}

void Player::removeWeapon (int c)
{
	Weapon tmp;
	weaponInventory[c] = Weapon();
	for (int i = c; i > aLength; i++) {
		tmp = weaponInventory[c + 1];
		weaponInventory[c + 1] = weaponInventory[c];
		weaponInventory[c] = tmp;
	}
	wLength--;
}

void Player::removePotion(int c)
{
	Potion tmp;
	potionInventory[c] = Potion();
	tmp = potionInventory[pLength];
	potionInventory[pLength] = potionInventory[c];
	potionInventory[c] = tmp;

	pLength--;
}

void Player::displayBackpack()
{
	std::cout << "-------- " << name << "'s Inventory --------\n";
	//strat with weapons
	std::cout << "Weapons:\n--------------------\n";
	for (int i = 0; i < wLength; i++) {
		weaponInventory[i].printWeapon();
		std::cout << "--------------------\n";
	}

	//now the armor
	std::cout << "Armor:\n--------------------\n";
	for (int i = 0; i < aLength; i++) {
		armorInventory[i].printArmor();
		std::cout << "--------------------\n";
	}

	//last, the potions
	std::cout << "Potions:\n--------------------\n";
	for (int i = 0; i < pLength; i++) {
		potionInventory[i].printPotion();
		std::cout << "--------------------\n";
	}
}

void Player::generateLoot() {
	srand(time(NULL)); //new seed

	std::cout << "Searching for weapons...\n";
	//determine how many weapons will drop
	std::this_thread::sleep_for(std::chrono::milliseconds(1500)); // sleep the program to updeat the time
	int chance = (rand() % 2) + 1; //1 or 2
	std::cout << "LOOTED WEAPON(s): \n";
	for (int i = 0; i < chance; i++) {
		Weapon weaponGeneration;
		weaponGeneration.generateWeapon(level);
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		weaponGeneration.printWeapon();
		insert(weaponGeneration);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Searching for armor...\n";
	//determine how many armor will drop
	std::this_thread::sleep_for(std::chrono::milliseconds(1500));
	std::cout << "LOOTED ARMOR(s): \n";
	chance = (rand() % 2) + 1; //1 or 2
	for (int i = 0; i < chance; i++) {
		Armor armorGeneration;
		armorGeneration.generateArmor(level);
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		armorGeneration.printArmor();
		insert(armorGeneration);
		std::cout << std::endl;
	}
	std::cout << std::endl;

	//determine how many potions the player will recieve
	std::cout << "Searching for potions...\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(1500));
	std::cout << "LOOTED POTION(s): \n";
	chance = (rand() % 4) + 1; //1 to 4
	for (int i = 0; i < chance; i++) {
		Potion potionGeneration;
		potionGeneration.generatePotion();
		potionGeneration.printPotion();
		insert(potionGeneration);
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
