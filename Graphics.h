#pragma once
#include <Windows.h>
#include <d2d1.h>
#include <wchar.h>
#include <dwrite.h>

class Graphics
{
private:
	ID2D1Factory* factory;
	ID2D1HwndRenderTarget* renderTarget;
	ID2D1SolidColorBrush* brush;
	IDWriteFactory* dWriteFactory;
	IDWriteTextFormat* textFormat;
public:
	static Graphics* gfx;
	Graphics();
	~Graphics();
	bool Init(HWND windowHandle);
	ID2D1RenderTarget* GetRendertarget();
	ID2D1SolidColorBrush* GetBrush() { return brush; }
	
	void BeginDraw();
	void EndDraw();

	void ClearScreen(float r = 1, float g = 0, float b = 0);
	void DrawCircle(float x, float y, float radius, float r = 1, float g = 0, float b = 0, float a = 1);
	void DrawRectangle(D2D1_RECT_F rect, float r = 1, float g = 0, float b = 0, float a = 1);
	void DrawPoint(int x, int y, int depth = 1, float r = 1, float g = 0, float b = 0, float a = 1);
	void DrawLine(int x1, int y1, int x2, int y2, float r = 1, float g = 0, float b = 0, float a = 1);
	void DrawGraphicsText(const wchar_t* string, int length);
};

