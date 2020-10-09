#pragma once
//#include "Levelgame15.h"
//#include "BombermanLevel.h"
#include "Menu.h"
void LoadLevels()
{
    GameController::LoadInitialLevel(new Menu());
    //GameController::LoadInitialLevel(new BombermanLevel());
    //GameController::LoadInitialLevel(new Levelgame15());
}