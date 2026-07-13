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

int RPGElements::RollDx(int sides) const{

	int DValue = 0;
	DValue = rand() % (sides +1);
	return DValue;
};


// Determine if successful attack, and how much damage
int RPGElements::MeleeAttack() const {

	int doesAttack = 0;
	int damage = 0;
	int attack = RollDx(20);

	// TODO: Setup for future critical hit modifications 
	if ((attack >= 5) && (attack <= 18)) {
		doesAttack = 1;
	}
	else if (attack > 18){
		doesAttack = 2;
		std::cout << std::endl << "Critical Hit!!!!" << std::endl;
	}

	if (doesAttack == 1) {
		damage += RollDx(4);
	}
	else if (doesAttack == 2) {
		damage += 2 * RollDx(4);
	}

	return damage;
}
int RPGElements::LongBowAttack() const {
	int doesAttack = 0;
	int damage = 0;
	int attack = RollDx(20);

	// TODO: Setup for future critical hit modifications 
	if ((attack >= 5) && (attack <= 18)) {
		doesAttack = 1;
	}
	else if (attack > 18) {
		doesAttack = 2;
		std::cout << std::endl << "Critical Hit!!!!" << std::endl;
	}

	if (doesAttack == 1) {
		damage += RollDx(8);
	}
	else if (doesAttack == 2) {
		damage += 2 * RollDx(8);
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

	// Melee attack
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
	// Bow attack
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
	// Psychich ability choice
	else if (playerChoice == 'c') {
		std::cout << "You muster all your might for a psychic ability against your foe!" << std::endl << std::endl;
		int psyAbility = RollDx(4);

		if (psyAbility == (1 || 3)) {
			std::cout << "You were able to read your enemy's mind!" << std::endl;
			std::cout << "The foe has " << NPCHP << std::endl;
			return 0;
		}
		else if (psyAbility == 2) {
			std::cout << "You feel a tingling sensation within your finger tips. Could this be?" << std::endl;
			std::cout << "Is this really??" << std::endl << std::endl;

			std::cout << "F I R E B A L L !!!!!!!!" << std::endl;

			//Roll for damage
			int playerAttackDamage = 0;
			for (int i = 0; i < 8; i++)
				playerAttackDamage += RollDx(6);

			std::cout << "Wowee! You hit your foe for " << playerAttackDamage << " worth of damage!" << std::endl;
			return playerAttackDamage;
		}
		else {
			std::cout << "The ability failed! Does that ever really work in real life?" << std::endl;
			return 0;
		}
	}
	else {
		std::cout << "You tripped over a rock and lost your turn! Enter a valid selection next time!" << std::endl;
		return 0;
	}
};
