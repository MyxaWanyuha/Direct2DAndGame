#pragma once
#include <wincodec.h>
#include "Graphics.h"

class SpriteSheet
{
private:
	ID2D1Bitmap* bmp;
	int spriteWidth;
	int spriteHeight;
	int spritesAcross;
	int numSprites;
public:
	SpriteSheet(wchar_t* filename);
	SpriteSheet(wchar_t* filename, int sprtWidth, int sprtHeight, int numSprts);
	~SpriteSheet();
	void Draw();
	void Draw(int index, float x, float y);
};

