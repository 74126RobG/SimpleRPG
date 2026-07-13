#include "RPGElements.h"
#include "Troll.h"
#include <random>
#include <iostream>

// Initialize troll HP
TrollStats::TrollStats()
	:TrollHP(15)
{
	// Nothing here but the wild growl of the troll!
}

// Is the NPC still conscious?
bool TrollStats::IsTrollFaint() {
	if (TrollHP <= 0) {
		return true;
	}
	else {
		return false;
	}
}
// Return NPC amount of HP
int TrollStats::GetTrollHP() const {
	return TrollHP;
}

// Battle the NPC!
bool TrollStats::BattleTroll() {

	int NPCAttackDamage = 0;

	while ((TrollStats::IsTrollFaint() || RPGElements::IsPlayerFaint()) != true) {

		// Attack from player
		TrollHP -= RPGElements::PlayerAttack(GetTrollHP());
		std::cout << std::endl;

		// Check to make sure the troll hasn't fainted yet. If not, troll try to attack!
		if (TrollStats::IsTrollFaint() == false) {

			if (RollDx(20) > 4) {
				NPCAttackDamage = RPGElements::MeleeAttack();
				if (NPCAttackDamage == 0) {
					std::cout << "The troll swung their sword and missed!" << std::endl << std::endl;
				}
				else {
					std::cout << "The troll swung their sword and hit you for " << NPCAttackDamage << " points of damage!" << std::endl << std::endl;;
					RPGElements::PlayerLoseHP(NPCAttackDamage);
				}
			}
			else
				std::cout << "The Troll got distracted by a butterfly!" << std::endl << std::endl;
		}
	}

	if (IsTrollFaint())
		return true;
	else
		return false;
}
