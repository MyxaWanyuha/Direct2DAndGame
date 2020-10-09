#include "Wall.h"

Wall::Wall(SpriteSheet* sprt, Engine::Rectangle* rect)
	:SpriteActor(sprt, rect) {};

void Wall::Destroy()
{
	SpriteActor::SetSprite(new SpriteSheet(L"roundBox.png", 64, 64, 1));
	auto rect = GetRectangle();
	Actor::SetRectangle(Engine::Rectangle(rect.GetPosition(), rect.GetWidth(), rect.GetHeight()));
}
