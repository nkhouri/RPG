#include <iostream>
#include <string>
#include "Player.h"


using namespace std;

int main() {
	string nameInput; // needed to take name from console
	Player player = Player(); // set the starting character at the begining of the game
	bool isPlaying = true;

	cout << "Welcome, warrior!\n";
	cout << "What is your warriors name?\n";
	cin >> nameInput;
	player.setName(nameInput); //name is now set into the player class

	while (isPlaying) {
		int decision = 0;
		cout << "What would you like to do?\n";
		cout << "1. Brave the Wilderness\t\t2. Go to the Trader\n3. Manage your inventory\t\t4. Check your stats\n5. Leave FOREVER!\n";
		cin >> decision; // WIP make a switch statement
	}

	return 0;
}