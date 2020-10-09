#pragma once
#include "Graphics.h"
#include "SpriteSheet.h"
class GameLevel
{
protected:
	static Graphics* gfx;
public:
	static void Init(Graphics* graphics);
	virtual void Load() = 0;
	virtual void Unload() = 0;
	virtual void Render() = 0;
	virtual void Update(long long timeTotal, long long timeDelta) = 0;
};