#pragma once
#include "GameLevel.h"
#include "Game.h"
class Levelgame15 : public GameLevel
{
private:
	int spriteSize;
	SpriteSheet* spriteNums;
	Game* game;
public:
	virtual void Load() override;
	virtual void Unload() override;
	virtual void Render() override;
	virtual void Update(double timeTotal, double timeDelta) override;
};

