#pragma once
#include "Actor.h"
#include "SpriteSheet.h"

class Character : public Actor
{
private:
	SpriteSheet* currentSprite;
	SpriteSheet* idle;
	SpriteSheet* right;
	SpriteSheet* left;
	SpriteSheet* up;
	SpriteSheet* down;
	int health;
	int stamina;
	int damage;
	int speed = 3;
	unsigned long long lastTick = 6;
	unsigned long long animNum = 0;
public:
	static const byte animCountUpDown = 2;
	static const byte animCountLeftRight = 4;
	Character(SpriteSheet* baseIdle, 
		SpriteSheet* moveR, SpriteSheet* moveL, SpriteSheet* moveU, SpriteSheet* moveD,
		Engine::Rectangle* rectangle,
		int baseHealth = 3, int baseStamina = 10, int baseDamage = 1);
	~Character();
	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();
	void Idle();
	int UpdateAnimNum(unsigned long long tick);
	SpriteSheet* GetCurrentSprite() const { return currentSprite; }
	int GetHealth() const { return health; }
	Point GetCharacterStand() const;
	void CreateBomb();
};

