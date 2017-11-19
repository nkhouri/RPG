#include <iostream>
#include <string>
#include <fstream>
#include "Player.h"


using namespace std;

void goToWild(Player player);
void generateLoot(Player player);
int nounCount = 0;
int adjetiveCount = 0;
string noun[1000];
string adjetive[1000];
int main() {
	string nameInput; // needed to take name from console
	Player player = Player(); // set the starting character at the begining of the game
	bool isPlaying = true;
	ifstream reader;

	//PRE GAME GEREATION
	reader.open("nouns.txt");

	while (!reader.eof()) {
		reader >> noun[nounCount];
		nounCount++;
	}
	reader.close();
	reader.open("adjetives.txt");
	while (!reader.eof()) {
		reader >> adjetive[adjetiveCount];
		adjetiveCount++;
	}
	reader.close();


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
		//generateLoot(player);
	}
	else {
		cout << "An Enemy is approaching...\n";
		//initiateCombat();
	}
}

//***************************************
//		LOOT GENERATOR
//	Used to generate a random set of loot for the player to take
//	Parameter: Player who is receiving the loot
//***************************************
void generateLoot(Player player)
{
	//have a maximum of 2 items of 1 type to loot at 1 time
	//gen weapons
	int luck = rand() % 2; //make the user either get 0, 1, or 2 items
	for (int i = 0; i < luck; i++) {
		Weapon genW = Weapon();		//holds the wepon to generate attributes
		int luckp = rand() % 4;		//gives more damage to a weapon with this roll
		int randA = rand() % adjetiveCount;
		int randN = rand() % nounCount;
		string name = adjetive[randA] + " " + noun[randN];
		genW.setName(name);
		luck = rand() % (player.getLevel() + 3) + (player.getLevel() - 3); //sets the level of the sword
		if (luck <= 0)	//this catches an error that would cause the sword to do negative damage if the player is a low level
			luck = 0;
		genW.setLevel(luck);
		genW.setDamage(luckp + player.getLevel());
		player.addBackpack(genW, player.getWeaponCount(player.getBackpack), player.getBackpack); //adding the generated weapon into the backpack
	}
	int luck = rand() % 2; //next, the armor
	for (int i = 0; i < luck; i++) {
		Armor genA = Armor();	//holds armor to generate attributes
		int luckp = rand() % 2;		//gives extra armor on top of the level
		int randA = rand() % adjetiveCount;
		int randN = rand() % nounCount;
		string name = adjetive[randA] + " " + noun[randN];
		genA.setName(name);
		luck = rand() % (player.getLevel() + 3) + (player.getLevel() - 3);
		if (luck <= 0)	//this catches an error that would cause the sword to do negative damage if the player is a low level
			luck = 0;
		genA.setLevel(luck);
		genA.setArmorRating(luckp + player.getLevel());
		player.addBackpack(genA, player.getArmorCount(player.getBackpack()), player.getBackpack());
	}
	int luck = rand() % 3; //last, the potion
	for (int i = 0; i < luck; i++) {
		Potion genP = Potion();
		luck = rand() % 3;
		if (luck == 0) {
			genP.setName("Small Healing Potion");
			genP.setHealingPower(10);
		}
		else if (luck = 1) {
			genP.setName("Medium Healing Potion");
			genP.setHealingPower(20);
		}
		else if (luck = 2) {
			genP.setName("Large Healing Potion");
			genP.setHealingPower(30);
		}
		else if (luck = 3) {
			genP.setName("Epic Healing Potion");
			genP.setHealingPower(40);
		}
		player.addBackpack(genP, player.getPotionCount(player.getBackpack()), player.getBackpack());
	}
}
