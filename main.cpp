#pragma comment (lib, "dinput8.lib")
#pragma comment (lib, "dxguid.lib")
#pragma comment (lib, "windowscodecs.lib")
#pragma comment (lib, "d2d1.lib")
#pragma comment (lib, "dwrite.lib")

#include <windows.h>
#include "Graphics.h"
#include "GameController.h"
#include "GlobalConstants.h"
#include "Levels.h"
#include "InputManager.h"

Graphics* graphics;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (uMsg == WM_DESTROY) { PostQuitMessage(0); return 0; }
    
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    WNDCLASSEX windowclass;
    ZeroMemory(&windowclass, sizeof(WNDCLASSEX));
    windowclass.cbSize = sizeof(WNDCLASSEX);
    windowclass.hbrBackground = (HBRUSH)COLOR_WINDOW;
    windowclass.hInstance = hInstance;
    windowclass.lpfnWndProc = WindowProc;
    windowclass.lpszClassName = L"MainWindow";
    windowclass.style = CS_HREDRAW | CS_VREDRAW;

    RegisterClassEx(&windowclass);

    RECT rect = { 0, 0, width, height };
    AdjustWindowRectEx(&rect, WS_OVERLAPPEDWINDOW, false, WS_EX_OVERLAPPEDWINDOW);

    HWND windowHandle = CreateWindowExW(WS_EX_OVERLAPPEDWINDOW, L"MainWindow", L"Direct2DGame", WS_OVERLAPPEDWINDOW,
        100, 100, rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, hInstance, 0);
    if (!windowHandle) return -1;

    graphics = new Graphics();
    if (!graphics->Init(windowHandle))
    {
        delete graphics;
        return -2;
    }
    GameController::Init();
    GameLevel::Init(graphics);

    //--------------------
    InputManager* inputManager = new InputManager();
    inputManager->InitDirectInput(hInstance, windowHandle);
    //--------------------
    ShowWindow(windowHandle, nCmdShow);
    
    LoadLevels();

    MSG message;
    message.message = WM_NULL;

    while (message.message != WM_QUIT)
    {
        if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
            DispatchMessage(&message);
        else
        {
            inputManager->DetectInput(windowHandle);
            GameController::Update();
            graphics->BeginDraw();
            GameController::Render();
            graphics->EndDraw();
        }
    }

    delete inputManager;
    delete graphics;
    return 0;
}