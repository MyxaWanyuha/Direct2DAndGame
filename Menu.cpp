#include "Levelgame15.h"
#include "BombermanLevel.h"
#include "Menu.h"
#include "GameController.h"
#include <dinput.h>
void Menu::Load(){}

void Menu::Unload(){}

void Menu::Render()
{
	gfx->ClearScreen(0, 0, 0);
	auto m = L"Esc - exit\n1 - Game15\n2 - Bomberman";
	auto l = wcslen(m);
	gfx->DrawGraphicsText(m, l);
}

void Menu::Update(double timeTotal, double timeDelta)
{
	if (GameController::keyboardInput[DIK_1])
		GameController::SwitchLevel(new Levelgame15());
	if (GameController::keyboardInput[DIK_2])
		GameController::SwitchLevel(new BombermanLevel());
}
