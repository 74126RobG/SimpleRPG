#include "RPGElements.h"
#include "Troll.h"
#include <random>
#include <iostream>

// Initialize troll HP
TrollStats::TrollStats()
	:TrollHP(15)
{
	// Nothing but the wild growl of the troll!
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

		// Check to make sure the troll hasn't fainted yet. If not, troll will attack!
		if (TrollStats::IsTrollFaint() == false) {
			NPCAttackDamage = RPGElements::MeleeAttack();
			if (NPCAttackDamage == 0) {
				std::cout << "The troll swung their sword and missed!" << std::endl << std::endl;
			}
			else {
				std::cout << "The troll swung their sword and hit you for " << NPCAttackDamage << " points of damage!" << std::endl << std::endl;;
				RPGElements::PlayerLoseHP(NPCAttackDamage);
			}
		}
	}
	if (IsTrollFaint())
		return true;
	else
		return false;
}
