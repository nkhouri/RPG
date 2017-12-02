#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "Player.h"


using namespace std;

void goToWild(Player player);
Weapon generateWeapon(int);
string generateName();
//void generateLoot(Player player);
int nounCount = 0;
int adjetiveCount = 0;
int main() {
	string nameInput; // needed to take name from console
	Player player = Player(); // set the starting character at the begining of the game
	bool isPlaying = true;
	ifstream reader;

	//testing environment
	//END TEST ENVIRONMENT


	cout << "Welcome, warrior!\n";
	cout << "What is your warriors name?\n";
	cin >> nameInput;
	player.setName(nameInput); //name is now set into the player class

	while (isPlaying) {
		int decision = 0;
		cout << "What would you like to do?\n";
		cout << "1. Brave the Wilderness\t\t2. Go to the Trader\n3. Manage your inventory\t\t4. Check your stats\n5. Leave FOREVER!\n";
		cin >> decision;
		switch (decision) {
		case 1:
			goToWild(player);
			break;
		case 2:
			//goToTrader();
			break;
		case 3:
			//goToInventory();
			break;
		case 4:
			//showStats();
			break;
		case 5:
			isPlaying = false;
			break;
		default:
			cout << "Enter a valid input\n";
			break;
		}
	}

	return 0;
}

//***********************************
//		GO TO WILD
//	Used to determine if the player fights or gets a luck crate
//	Parameter: Player who is traveling into the wild
//***********************************
void goToWild(Player player)
{
	int chance = rand() % 100;
	if (chance > 90) {
		cout << "You wander around the land and find a chest full of loot!\n";
	}
	else {
		cout << "An Enemy is approaching...\n";
		//initiateCombat();
	}
}

//Generate a new weapon
Weapon generateWeapon(int c) //c is player level
{
	srand(time(NULL)); //set the new seed for the generation
	
	Weapon weapon;
	string noun[100]; //hold a max of 100 nouns
	string adjetive[100]; //hold a max of 100 adjetives
	ifstream input;
	input.open("noun.txt");
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
	string nameNoun = noun[(rand() % nCount)];
	string nameAdjetive = adjetive[(rand() % aCount)];
	//store the name into the weapon
	string name = nameAdjetive + " " + nameNoun;
	weapon.setName(name);
	//set the level based on the players level
	if (c <= 5) {
		weapon.setLevel(1);
	}
	else {
		int level = (rand() % c) + 5;
		weapon.setLevel(level);
	}
	//set the damage based on the players level
	//added set multipliers to damage to have a better loot outcome based of player level;

	int damage = (rand() % c) + 5;
	if (c < 15) {
		damage = damage * 1.2; //20% inclrease base
	}
	else if (c >= 15 && c < 30) {
		damage = damage * 1.6; //60% increase at lvl 15
	}
	else {
		damage = damage * 2; //100% increase at 30+
	}
	weapon.setDamage(damage);
	return weapon;
}

//Manually generate damage
int generateDamage(int c) {
	srand(time(NULL)); //set the new seed for the generation

	int damage = (rand() % c) + 5;
	if (c < 15) {
		damage = damage * 1.2; //20% inclrease base
	}
	else if (c >= 15 && c < 30) {
		damage = damage * 1.6; //60% increase at lvl 15
	}
	else {
		damage = damage * 2; //100% increase at 30+
	}

	return damage;
}

//Manually generate a level
int generateLevel(int c) {
	int level;
	if (c <= 5) {
		level = 1;
	}
	else {
		level = (rand() % c) + 5;
	}

	return level;
}

//Manually generate a name
string generateName() {
	srand(time(NULL)); //seeds the number generators

	string noun[100]; //hold a max of 100 nouns
	string adjetive[100]; //hold a max of 100 adjetives
	ifstream input;
	input.open("noun.txt");
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
	string nameNoun = noun[(rand() % nCount)];
	string nameAdjetive = adjetive[(rand() % aCount)];
	//store the name into the weapon
	string name = nameAdjetive + " " + nameNoun;
	cout << name << endl;

	return name;
}