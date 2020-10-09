#pragma once
#include "GameLevel.h"
#include "HPTimer.h"
class GameController
{
private:
	GameController() {};
	static GameLevel* currentLevel;
	static HPTimer* hpTimer;
public:
	static BYTE* keyboardInput;
	static bool isLoading;
	static void Init();
	static void LoadInitialLevel(GameLevel* level);
	static void SwitchLevel(GameLevel* level);

	static void Render();
	static void Update();
};

