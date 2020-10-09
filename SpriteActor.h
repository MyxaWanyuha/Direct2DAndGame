#pragma once
#include "Actor.h"
#include "SpriteSheet.h"
class SpriteActor : public Actor
{
private:
	SpriteSheet* sprite;
public:
	void Draw(int index, float x, float y);
	void SetSprite(SpriteSheet* newSprite);
	SpriteActor(SpriteSheet* sprt, Engine::Rectangle* rect);
	~SpriteActor();
};

