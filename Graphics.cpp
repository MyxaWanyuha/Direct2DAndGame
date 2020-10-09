#include "Graphics.h"

Graphics* Graphics::gfx;
Graphics::Graphics()
{
	if (!gfx) gfx = this;
	factory = nullptr;
	renderTarget = nullptr;
	brush = nullptr;
}

Graphics::~Graphics()
{
	if (brush) brush->Release();
	if (factory) factory->Release();
	if (renderTarget) renderTarget->Release();
	if (dWriteFactory) dWriteFactory->Release();
	if (textFormat) textFormat->Release();
}

bool Graphics::Init(HWND windowHandle)
{
	HRESULT res = D2D1CreateFactory(D2D1_FACTORY_TYPE::D2D1_FACTORY_TYPE_SINGLE_THREADED, &factory);
	if (res != S_OK) return false;

	RECT rect;
	GetClientRect(windowHandle, &rect);
	
	factory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(), 
		D2D1::HwndRenderTargetProperties(windowHandle, D2D1::SizeU(rect.right, rect.bottom)), 
		&renderTarget);
	if (res != S_OK) return false;

	res = DWriteCreateFactory(
		DWRITE_FACTORY_TYPE_SHARED,
		__uuidof(dWriteFactory),
		reinterpret_cast<IUnknown**>(&dWriteFactory));

	res = dWriteFactory->CreateTextFormat(
		L"Arial",
		NULL,
		DWRITE_FONT_WEIGHT_NORMAL,
		DWRITE_FONT_STYLE_NORMAL,
		DWRITE_FONT_STRETCH_NORMAL,
		50,
		L"", //locale
		&textFormat);

	textFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
	textFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);

	res = renderTarget->CreateSolidColorBrush(D2D1::ColorF(0,0,0,0), &brush);
	return res == S_OK;
}

ID2D1RenderTarget* Graphics::GetRendertarget() { return renderTarget; }

void Graphics::BeginDraw() { renderTarget->BeginDraw(); }

void Graphics::EndDraw() { renderTarget->EndDraw(); }

void Graphics::ClearScreen(float r, float g, float b)
{
	renderTarget->Clear(D2D1::ColorF(r, g, b));
}

void Graphics::DrawCircle(float x, float y, float radius, float r, float g, float b, float a)
{
	brush->SetColor(D2D1::ColorF(r, g, b, a));
	renderTarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(x, y), radius, radius), brush, 3.0f);
}

void Graphics::DrawRectangle(D2D1_RECT_F rect, float r, float g, float b, float a)
{
	brush->SetColor(D2D1::ColorF(r, g, b, a));
	renderTarget->DrawRectangle(rect, brush, 3.f);
}

void Graphics::DrawPoint(int x, int y, int depth, float r, float g, float b, float a)
{
	brush->SetColor(D2D1::ColorF(r, g, b, a));
	auto rect = D2D1::RectF(x, y, x, y);
	renderTarget->DrawRectangle(rect, brush, depth);
}

void Graphics::DrawLine(int x1, int y1, int x2, int y2, float r, float g, float b, float a)
{
	brush->SetColor(D2D1::ColorF(r, g, b, a));
	auto p1 = D2D1::Point2F(x1, y1);
	auto p2 = D2D1::Point2F(x2, y2);
	renderTarget->DrawLine(p1, p2, brush);
}

void Graphics::DrawGraphicsText(const wchar_t* string, int length)
{
	brush->SetColor(D2D1::ColorF(1, 0, 0, 1));
	 renderTarget->DrawTextW(
		string,
		length,
		textFormat,
		 D2D1::RectF(0, 0, renderTarget->GetSize().width, renderTarget->GetSize().height),
		brush);
}
