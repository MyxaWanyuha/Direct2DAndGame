#pragma once
#include "Character.h"
class Player : public Character
{
public:
	Player(SpriteSheet* baseIdle,
		SpriteSheet* moveR, SpriteSheet* moveL, SpriteSheet* moveU, SpriteSheet* moveD,
		Engine::Rectangle* rectangle,
		int baseHealth = 3, int baseStamina = 10, int baseDamage = 1);
	void UpdateInput();
};

