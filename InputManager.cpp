#include "InputManager.h"

InputManager::~InputManager()
{
	DIKeyboard->Unacquire();
	DIMouse->Unacquire();
	DirectInput->Release();
}

bool InputManager::InitDirectInput(HINSTANCE hInstance, HWND& hwnd)
{
	HRESULT hr;
	hr = DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&DirectInput, NULL);

	hr = DirectInput->CreateDevice(GUID_SysKeyboard, &DIKeyboard, NULL);
	hr = DirectInput->CreateDevice(GUID_SysMouse, &DIMouse, NULL);

	hr = DIKeyboard->SetDataFormat(&c_dfDIKeyboard);
	hr = DIKeyboard->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);

	hr = DIMouse->SetDataFormat(&c_dfDIMouse);
	hr = DIMouse->SetCooperativeLevel(hwnd, DISCL_EXCLUSIVE | DISCL_NOWINKEY | DISCL_FOREGROUND);

	return true;
}

void InputManager::DetectInput(HWND& hwnd)
{
	DIMOUSESTATE mouseCurrState;

	BYTE keyboardState[256];

	DIKeyboard->Acquire();
	DIMouse->Acquire();

	DIMouse->GetDeviceState(sizeof(DIMOUSESTATE), &mouseCurrState);
	DIKeyboard->GetDeviceState(sizeof(keyboardState), (LPVOID)&keyboardState);

	if (keyboardState[DIK_ESCAPE] & 0x80)
		PostMessage(hwnd, WM_DESTROY, 0, 0);

	for (int i = 0; i < 256; i++)
		GameController::keyboardInput[i] = keyboardState[i] & 0x80;

	//if (mouseCurrState.lX != mouseLastState.lX)
	//{
	//	scaleX -= (mouseCurrState.lX * 0.001f);
	//}
	//if (mouseCurrState.lY != mouseLastState.lY)
	//{
	//	scaleY -= (mouseCurrState.lY * 0.001f);
	//}
}
