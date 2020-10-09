#include "AI.h"
#include <random>
AI::AI(SpriteSheet* baseIdle, SpriteSheet* moveR, SpriteSheet* moveL,
	SpriteSheet* moveU, SpriteSheet* moveD, Engine::Rectangle* rectangle,
	int baseHealth, int baseStamina, int baseDamage)
	: Character(baseIdle, moveR, moveL, moveU, moveD, rectangle,
		baseHealth, baseStamina, baseDamage) 
{
	auto posx = GetRectangle().GetPosition().GetX();
	rx = posx + 128;
	lx = posx - 128;
}

void AI::UpdateMove()
{
	auto posx = GetRectangle().GetPosition().GetX();
	if (isRDirection)
	{
		if (posx < rx)
			MoveRight();
		else
			isRDirection = false;
	}
	else
	{
		if (posx > lx)
			MoveLeft();
		else
			isRDirection = true;
	}
}
