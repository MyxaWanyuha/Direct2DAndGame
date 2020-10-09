#include "Character.h"
#include "GlobalConstants.h"
Character::Character(SpriteSheet* baseIdle, SpriteSheet* moveR, SpriteSheet* moveL,
	SpriteSheet* moveU, SpriteSheet* moveD,
	Engine::Rectangle* rect, int baseHealth, int baseStamina, int baseDamage)
	: idle(baseIdle), currentSprite(baseIdle), 
	right(moveR), left(moveL), up(moveU), down(moveD), Actor(rect),
	health(baseHealth), stamina(baseStamina), damage(baseDamage) {}

Character::~Character()
{
	delete idle;
	delete right;
	delete left;
	delete up;
	delete down;
}

void Character::MoveRight()
{
	currentSprite = right;
	auto pos = rectangle->GetPosition();
	auto newX = pos.GetX() + speed;
	if ((newX + CharTextureSize) < width)
		rectangle->SetPosition(Point(newX, pos.GetY()));
}

void Character::MoveLeft()
{
	currentSprite = left;
	auto pos = rectangle->GetPosition();
	auto newX = pos.GetX() - speed;
	if (newX > 0)
		rectangle->SetPosition(Point(newX, pos.GetY()));
}

void Character::MoveUp()
{
	currentSprite = up;
	auto pos = rectangle->GetPosition();
	auto newY = pos.GetY() - speed;
	if(newY > 0)
		rectangle->SetPosition(Point(pos.GetX(), newY));
}

void Character::MoveDown()
{
	currentSprite = down;
	auto pos = rectangle->GetPosition();
	auto newY = pos.GetY() + speed;
	if ((newY + CharTextureSize + CharTextureSize * 0.13f) < height)
		rectangle->SetPosition(Point(pos.GetX(), newY));
}

void Character::Idle()
{
	currentSprite = idle;
}

int Character::UpdateAnimNum(unsigned long long tick)
{ 
	if ((tick - lastTick) > 6)
	{
		lastTick = tick;
		animNum++;
	}
	return animNum % animCountLeftRight; 
}

Point Character::GetCharacterStand() const
{
	return Point(rectangle->GetRight() - rectangle->GetWidth() / 2, rectangle->GetBottom());
}

void Character::CreateBomb()
{
	//персонаж должен сообщить игре что он поставил бомбу?
	//или игра должна контролировать все действия персонажей и реагировать на них?
	//no way...
}
