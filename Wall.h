#pragma once
#include "SpriteActor.h"
class Wall : public SpriteActor
{
public:
	Wall(SpriteSheet* sprt, Engine::Rectangle* rect);
	void Destroy();
};

