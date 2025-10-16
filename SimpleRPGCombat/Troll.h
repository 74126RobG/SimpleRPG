#pragma once
#include "RPGElements.h"

class TrollStats : public RPGElements {
public:
	TrollStats();
	bool IsTrollFaint();
	int GetTrollHP() const;
	bool BattleTroll();
private:
	int TrollHP;
};