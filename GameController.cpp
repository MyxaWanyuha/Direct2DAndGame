#include "GameController.h"

GameLevel* GameController::currentLevel;
HPTimer* GameController::hpTimer;
bool GameController::isLoading;
BYTE* GameController::keyboardInput;
void GameController::Init()
{
	keyboardInput = new BYTE[256];
	isLoading = true;
	currentLevel = nullptr;
	hpTimer = new HPTimer();
}

void GameController::LoadInitialLevel(GameLevel* level)
{
	isLoading = true;
	currentLevel = level;
	currentLevel->Load();
	isLoading = false;
}

void GameController::SwitchLevel(GameLevel* level)
{
	isLoading = true;
	currentLevel->Unload();
	level->Load();
	delete currentLevel;
	currentLevel = level;
	isLoading = false;
}

void GameController::Render()
{
	if (isLoading) return;
	currentLevel->Render();
}

void GameController::Update()
{
	if (isLoading) return;
	hpTimer->Update();
	currentLevel->Update(hpTimer->GetTimeTotal(), hpTimer->GetTimeDelta());
}
