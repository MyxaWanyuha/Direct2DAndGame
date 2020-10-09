#pragma once
#include "Character.h"
class AI : public Character
{
	bool isRDirection = true;
	int rx;
	int lx;
public:
	AI(SpriteSheet* baseIdle,
	SpriteSheet* moveR, SpriteSheet* moveL, SpriteSheet* moveU, SpriteSheet* moveD,
	Engine::Rectangle* rectangle,
	int baseHealth = 3, int baseStamina = 10, int baseDamage = 1);
	void UpdateMove();
};

