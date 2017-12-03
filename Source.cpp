#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <thread>
#include <chrono>
#include "Player.h"


using namespace std;

void goToWild(Player&);
//void generateLoot(Player);
int nounCount = 0;
int adjetiveCount = 0;
int main() {
	string nameInput; // needed to take name from console
	Player player = Player(); // set the starting character at the begining of the game
	bool isPlaying = true;
	ifstream reader;

	//testing environment
	player.setName("Nick");
	player.setLevel(11);
	cout << player.getName() << " at generated level " << player.getLevel() << endl;
	system("pause");
	player.generateLoot();
	cout << "GENERATION 2\n";
	player.generateLoot();

	cout << "Printing the backpack after 2 generations of loot\n";
	player.displayBackpack();
	system("pause");
	return 0;
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
void goToWild(Player &player)
{
	int chance = rand() % 100;
	if (chance > 90) {
		cout << "You wander around the land and find a chest full of loot!\n";
		player.generateLoot();
		player.generateExp();
	}
	else {
		cout << "An Enemy is approaching...\n";
		//initiateCombat();
	}
}

/*
void generateLoot(Player p) {
	srand(time(NULL)); //new seed

	cout << "Searching for weapons...\n";
	//determine how many weapons will drop
	std::this_thread::sleep_for(std::chrono::milliseconds(1500)); // sleep the program to updeat the time
	int chance = (rand() % 2) + 1; //1 or 2
	cout << "LOOTED WEAPON(s): \n";
	for (int i = 0; i < chance; i++) {
		Weapon weaponGeneration;
		weaponGeneration.generateWeapon(p.getLevel());
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		weaponGeneration.printWeapon();
		p.insertWeapon(weaponGeneration);
		cout << endl;
	}
	cout << endl;
	cout << "Searching for armor...\n";
	//determine how many armor will drop
	std::this_thread::sleep_for(std::chrono::milliseconds(1500));
	cout << "LOOTED ARMOR(s): \n";
	chance = (rand() % 2) + 1; //1 or 2
	for (int i = 0; i < chance; i++) {
		Armor armorGeneration;
		armorGeneration.generateArmor(p.getLevel());
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		armorGeneration.printArmor();
		p.insert(armorGeneration);
		cout << endl;
	}
	cout << endl;

	//determine how many potions the player will recieve
	cout << "Searching for potions...\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(1500));
	cout << "LOOTED POTION(s): \n";
	chance = (rand() % 4) + 1; //1 to 4
	for (int i = 0; i < chance; i++) {
		Potion potionGeneration;
		potionGeneration.generatePotion();
		potionGeneration.printPotion();
		p.insert(potionGeneration);
		cout << endl;
	}
	cout << endl;
}
*/