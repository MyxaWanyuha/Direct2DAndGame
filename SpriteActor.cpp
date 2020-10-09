#include "SpriteActor.h"

void SpriteActor::Draw(int index, float x, float y)
{
	sprite->Draw(index, x, y);
}

void SpriteActor::SetSprite(SpriteSheet* newSprite)
{
	delete sprite;
	sprite = newSprite;
}

SpriteActor::SpriteActor(SpriteSheet* sprt, Engine::Rectangle* rect)
	:sprite(sprt), Actor(rect) {}

SpriteActor::~SpriteActor()
{
	delete sprite;
}
