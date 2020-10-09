#include <dinput.h>
#include <random>
#include "Levelgame15.h"
#include "GameController.h"
#include "GlobalConstants.h"

void Levelgame15::Load()
{
	spriteSize = 256;
	game = new Game(3);
	spriteNums = new SpriteSheet(L"numbers.png", spriteSize, spriteSize, 9);
}

void Levelgame15::Unload()
{
	delete spriteNums;
	delete game;
}

void Levelgame15::Render()
{
	int index = 0;
	for (int j = 0; j < 3; j++)
		for (int i = 0; i < 3; i++)
		{
			spriteNums->Draw(game->GetCellValue(j, i) - 1, i * spriteSize, j * spriteSize);
			index++;
		}

	if(game->IsWin())
	{
		for (int i = 0; i < 100; i++)
		{
			gfx->DrawRectangle(D2D1::RectF(rand() % height, rand() % width, rand() % height,rand() % width),
				(rand() % 100) / 100.f,
				(rand() % 100) / 100.f,
				(rand() % 100) / 100.f,
				(rand() % 100) / 100.f);
			gfx->DrawCircle(rand() % width, rand() % height, rand() % 100,
				(rand() % 100) / 100.f, 
				(rand() % 100) / 100.f,
				(rand() % 100) / 100.f,
				(rand() % 100) / 100.f);
		}
		Sleep(80);
	}
}

void Levelgame15::Update(long long timeTotal, long long timeDelta)
{
	int sleep = 150;
	if (!game->IsWin()) 
	{
		if (GameController::keyboardInput[DIK_A])
		{
			game->MoveLeft();
			Sleep(sleep);
		}
		if (GameController::keyboardInput[DIK_S])
		{
			game->MoveDown();
			Sleep(sleep);
		}
		if (GameController::keyboardInput[DIK_D])
		{
			game->MoveRight();
			Sleep(sleep);
		}if (GameController::keyboardInput[DIK_W])
		{
			game->MoveUp();
			Sleep(sleep);
		}
	}
}
