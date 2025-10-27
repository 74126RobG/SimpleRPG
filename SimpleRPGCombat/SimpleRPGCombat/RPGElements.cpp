#include "RPGElements.h"
#include <random>
#include <iostream>

// Initialize player health
RPGElements::RPGElements()
	: PlayerHP(20)
{
	// Nothing to see here!
}

void RPGElements::PlayerLoseHP(const int damage)
{
	RPGElements::PlayerHP -= (damage);
};

// Return Player amount of HP
int RPGElements::GetPlayerHP() const {
	return PlayerHP;
}

// Is the player still conscious?
bool RPGElements::IsPlayerFaint() {
	if (PlayerHP <= 0) {
		return true;
	}
	else {
		return false;
	}
}

// Roll D20 for attack
int RPGElements::RollD20() const {
	int DValue = 0;
	DValue = rand() % 21;

	return DValue;
}

// Roll D4
int RPGElements::RollD4() const {
	int DValue = 0;
	DValue = rand() % 5;

	return DValue;
}
int RPGElements::RollD8() const {
	int DValue = rand() % 9;
	return DValue;
};

// Determine if successful attack, and how much damage
int RPGElements::MeleeAttack() const {

	int doesAttack = 0;
	int damage = 0;
	int attack = RollD20();

	// TODO: Setup for future critical hit modifications 
	if ((attack >= 5) && (attack <= 18)) {
		doesAttack = 1;
	}
	else if (attack > 18){
		doesAttack = 2;
		std::cout << std::endl << "Critical Hit!!!!" << std::endl;
	}

	if (doesAttack == 1) {
		damage += RollD4();
	}
	else if (doesAttack == 2) {
		damage += 2 * RollD4();
	}

	return damage;
}
int RPGElements::LongBowAttack() const {
	int doesAttack = 0;
	int damage = 0;
	int attack = RollD20();

	// TODO: Setup for future critical hit modifications 
	if ((attack >= 5) && (attack <= 18)) {
		doesAttack = 1;
	}
	else if (attack > 18) {
		doesAttack = 2;
		std::cout << std::endl << "Critical Hit!!!!" << std::endl;
	}

	if (doesAttack == 1) {
		damage += RollD8();
	}
	else if (doesAttack == 2) {
		damage += 2 * RollD8();
	}

	return damage;
};
int RPGElements::PlayerAttack(const int NPCHP) const {

	int playerAttackDamage = 0;
	char playerChoice = 'n';
	const int foeHP = NPCHP;

	std::cout << std::endl << "Your hp is " << RPGElements::GetPlayerHP() << " HP";
	std::cout << std::endl << "It is your turn! What do you do?";
	std::cout << std::endl << std::endl << "a) Melee attack" << std::endl << "b) Long Bow Attack" << std::endl << "c) Psychic ability" << std::endl << std::endl;
	std::cout << "Choice: ";
	std::cin >> playerChoice;
	std::cout << std::endl;

	if (playerChoice == 'a') {
		playerAttackDamage = MeleeAttack();

		if (playerAttackDamage > 0) {
			std::cout << "You swing your sword and do " << playerAttackDamage << " points worth of damage!" << std::endl;
			return playerAttackDamage;
		}
		else {
			std::cout << "You swung your sword and missed!" << std::endl;
			return 0;
		}
	}
	else if (playerChoice == 'b') {
		playerAttackDamage = LongBowAttack();

		if (playerAttackDamage > 0) {
			std::cout << "You shoot your long bow and do " << playerAttackDamage << " points worth of damage!" << std::endl;
			return playerAttackDamage;
		}
		else {
			std::cout << "You shot your bow and missed!" << std::endl;
			return 0;
		}
	}

	else if (playerChoice == 'c') {
		std::cout << "You used your psychic ability against your foe!" << std::endl;
		if (RollD4() > 1) {
			std::cout << "The foe has " << NPCHP << std::endl;;
		}
		else {
			std::cout << "The ability failed!" << std::endl;
		}
		return 0;
	}
	else {
		std::cout << "You tripped over a rock and lost your turn! Enter a valid selection next time!" << std::endl;
		return 0;
	}
};
