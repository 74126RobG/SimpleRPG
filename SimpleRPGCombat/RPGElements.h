#pragma once

class RPGElements {
public:
	RPGElements();
	void PlayerLoseHP(const int damage);
	int MeleeAttack() const;
	int LongBowAttack() const;
	int RollDx(int sides) const;
	bool IsPlayerFaint();
	int GetPlayerHP() const;
	int PlayerAttack(const int NPCHP) const;
private:
	int PlayerHP;
};
