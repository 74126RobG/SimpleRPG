/*
Tinkering
Title		: SimpleRPG
Description : Using bject oriented programming, this program goes through
		a basic story driven RPG of a warrior going to fight the evil troll
		of the caves!
By			: Robert Guziec
Written		: Oct 13, 2025
Last edited : Oct 14, 2025
*/

#include <iostream>
#include "RPGElements.h"
#include "Troll.h"

int main() {

	// Player's choice variable
	char playerChoice = ' ';
	// Initialize stats of player
	RPGElements a;

	// Introduction
	std::cout << "Welcome adventurer!" << std::endl;
	std::cout << "After traveling weeks through the mountains, you found treasure in a cave!" << std::endl;
	std::cout << "But oh no! There is a troll staring you down from the other side!" << std::endl << std::endl;
	std::cout << "Do you engage in combat? (y / n)" << std::endl << std::endl;
	std::cout << "Choice: ";
	std::cin >> playerChoice;

	// Defensive programming
	while ((playerChoice != 'n') && (playerChoice != 'y')){
		std::cout << std::endl << "Please enter a valid choice!" << std::endl;
		std::cout << "Do you engage? (y / n)" << std::endl << std::endl;
		std::cout << "Choice: ";
		std::cin >> playerChoice;
	}
	if ((playerChoice == 'n')) {
		std::cout << std::endl << "You chose not to engage in combat, and have left the cave." << std::endl;
		std::cout << "Who knows what sort of treasures there may have been!" << std::endl;
	}
	else if (playerChoice == 'y') {
		std::cout << std::endl << "You chose to engage and battle the troll! " << std::endl;
		TrollStats z;
		
		// Determine battle victor based on battle value
		if (z.BattleTroll()) {
			std::cout << std::endl << std::endl << "The troll has fainted! You are able to relish the treasures of the cave!";
			std::cout << std::endl << "You win! There are no experience points yet, but I bet you'd level up!" << std::endl << std::endl;
		}
		else {
			std::cout << std::endl << std::endl << "Your hp has reached zero and you have fainted!" ;
			std::cout << std::endl << "The troll continues to guard the cave to this day. The treasures will forever remain untouched." << std::endl << std::endl;
		}
	}

	// Game over messages
	std::cout << std::endl << " * * * * G A M E O V E R * * * * " << std::endl << std::endl;
	system("PAUSE");
	return 0;
}