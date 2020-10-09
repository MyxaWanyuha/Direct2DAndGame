#pragma once
#include <dinput.h>
#include "GameController.h"
class InputManager
{
private:
	LPDIRECTINPUT8 DirectInput;
	IDirectInputDevice8* DIKeyboard;
	IDirectInputDevice8* DIMouse;
	BYTE keyboardState[256];
public:
	InputManager(){}
	~InputManager();
	bool InitDirectInput(HINSTANCE hInstance, HWND& hwnd);
	void DetectInput(HWND& hwnd);
};

