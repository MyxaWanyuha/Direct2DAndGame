#pragma once
#include "GameLevel.h"
#include "BombermanGame.h"

class BombermanLevel : public GameLevel
{
	SpriteSheet* test;
	BombermanGame* game;
	void DrawMap();
	unsigned long long tick = 0;
	virtual void Load() override;
	virtual void Unload() override;
	virtual void Render() override;
	void DrawDebug();
	virtual void Update(long long timeTotal, long long timeDelta) override;
};

