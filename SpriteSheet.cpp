#include "SpriteSheet.h"

SpriteSheet::SpriteSheet(wchar_t* filename)
{
	bmp = nullptr;
	HRESULT hr;
	IWICImagingFactory* wicFactory = nullptr;
	hr = CoCreateInstance(
		CLSID_WICImagingFactory,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_IWICImagingFactory,
		(LPVOID*)&wicFactory);

	IWICBitmapDecoder* wicDecoder = nullptr;
	hr = wicFactory->CreateDecoderFromFilename(
		filename,
		NULL,
		GENERIC_READ,
		WICDecodeMetadataCacheOnLoad,
		&wicDecoder);

	IWICBitmapFrameDecode* wicFrame = nullptr;
	hr = wicDecoder->GetFrame(0, &wicFrame);

	IWICFormatConverter* wicConverter = nullptr;
	hr = wicFactory->CreateFormatConverter(&wicConverter);

	hr = wicConverter->Initialize(
		wicFrame,
		GUID_WICPixelFormat32bppPBGRA,
		WICBitmapDitherTypeNone,
		NULL, 0.0,
		WICBitmapPaletteTypeCustom);

	hr = Graphics::gfx->GetRendertarget()->CreateBitmapFromWicBitmap(wicConverter, NULL, &bmp);

	if (wicFactory) wicFactory->Release();
	if (wicDecoder) wicDecoder->Release();
	if (wicFrame) wicFrame->Release();
	if (wicConverter) wicConverter->Release();

	spriteWidth = bmp->GetSize().width;
	spriteHeight = bmp->GetSize().height;
	spritesAcross = 1;
}

SpriteSheet::
SpriteSheet(wchar_t* filename, int sprtWidth, int sprtHeight, int numSprts)
	:SpriteSheet(filename)
{
	spriteWidth = sprtWidth;
	spriteHeight = sprtHeight;
	spritesAcross = (int)bmp->GetSize().width / spriteWidth;
	numSprites = numSprts;
}

SpriteSheet::~SpriteSheet()
{
	if (bmp)bmp->Release();
}

void SpriteSheet::Draw()
{
	Graphics::gfx->GetRendertarget()->DrawBitmap(
		bmp,
		D2D1::RectF(0.f, 0.f, bmp->GetSize().width, bmp->GetSize().height),
		1.f,
		D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
		D2D1::RectF(0.f, 0.f, bmp->GetSize().width, bmp->GetSize().height));
}

void SpriteSheet::Draw(int index, float x, float y)
{
	index %= numSprites;
	D2D_RECT_F src = D2D1::RectF(
		(float)((index % spritesAcross) * spriteWidth),
		(float)((index / spritesAcross) * spriteHeight),
		(float)((index % spritesAcross) * spriteWidth) + spriteWidth,
		(float)((index / spritesAcross) * spriteWidth) + spriteHeight);

	D2D_RECT_F dest = D2D1::RectF(x, y, x + spriteWidth, y + spriteHeight);

	Graphics::gfx->GetRendertarget()->DrawBitmap(bmp, dest, 1.f,
		D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
		//faster//D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
		src);
}