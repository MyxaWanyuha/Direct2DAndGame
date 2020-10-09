#include <dinput.h>
#include "Player.h"
#include "GameController.h"

Player::Player(SpriteSheet* baseIdle, SpriteSheet* moveR, SpriteSheet* moveL,
	SpriteSheet* moveU, SpriteSheet* moveD, Engine::Rectangle* rectangle,
	int baseHealth, int baseStamina, int baseDamage)
	: Character(baseIdle, moveR, moveL, moveU, moveD, rectangle,
		baseHealth, baseStamina, baseDamage) {}

void Player::UpdateInput()
{
	if (GameController::keyboardInput[DIK_A])
	{
		MoveLeft();
	}
	else if (GameController::keyboardInput[DIK_S])
	{
		MoveDown();
	}
	else if (GameController::keyboardInput[DIK_D])
	{
		MoveRight();
	}
	else if (GameController::keyboardInput[DIK_W])
	{
		MoveUp();
	}
	else if (GameController::keyboardInput[DIK_SPACE])
	{
		CreateBomb();
	}
	else Idle();
}

