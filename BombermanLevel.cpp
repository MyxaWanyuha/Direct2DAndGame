#include <dinput.h>
#include <string>
#include "BombermanLevel.h"
#include "SpriteSheet.h"
#include "GameController.h"
#include "GlobalConstants.h"
#include "Player.h"

void BombermanLevel::Load()
{
	game = new BombermanGame();
}

void BombermanLevel::Unload()
{
	delete game;
}

void RenderChar(Character* pers, unsigned long long tick)
{
	auto pos = pers->GetRectangle().GetPosition();
	pers->GetCurrentSprite()->Draw(pers->UpdateAnimNum(tick), pos.GetX(), pos.GetY());
}

void BombermanLevel::DrawMap()
{
	for (int i = 0; i < game->GetMapSize(); i++)
		for (int j = 0; j < game->GetMapSize(i); j++)
			game->GetMapCell(i, j)->Draw(0, i * CharTextureSize, j * CharTextureSize);
}

void BombermanLevel::Render()
{
	tick++;
	gfx->ClearScreen(1, 1, 1);
	DrawMap();
	for (int i = 0; i < game->GetEnemiesCount(); i++)
		RenderChar(game->GetEnemy(i), tick);
	RenderChar(game->GetPlayer(), tick);

	//DrawDebug();
}

void BombermanLevel::DrawDebug()
{
	//draw map rect
	for (int i = 0; i < game->GetMapSize(); i++)
		for (int j = 0; j < game->GetMapSize(i); j++)
		{
			auto r = game->GetMapCell(i, j)->GetRectangle();
			auto d2r = D2D1::RectF(r.GetLeft(), r.GetTop(), r.GetRight(), r.GetBottom());
			gfx->DrawRectangle(d2r, 0, 1, 0, 1);
		}
	//other
	auto prect = game->GetPlayer()->GetRectangle();
	//draw dead
	for (int i = 0; i < game->GetEnemiesCount(); i++)
		if (prect.IsIntersected(game->GetEnemy(i)->GetRectangle()))
			gfx->DrawGraphicsText(L"YouDead", 8);
	//draw player rect
	auto rect = D2D1::RectF(prect.GetLeft(), prect.GetTop(), prect.GetRight(), prect.GetBottom());
	gfx->DrawRectangle(rect, 0, 1, 1, 1);
	auto pstand = game->GetPlayer()->GetCharacterStand();
	gfx->DrawPoint(pstand.GetX(), pstand.GetY(), 5);
	//draw enemies rect
	for (int i = 0; i < game->GetEnemiesCount(); i++)
	{
		auto erect = game->GetEnemy(i)->GetRectangle();
		auto rect = D2D1::RectF(erect.GetLeft(), erect.GetTop(), erect.GetRight(), erect.GetBottom());
		gfx->DrawRectangle(rect, 1, 0, 0, 1);
	}
	//ContaiosPoint
	for (int i = 0; i < game->GetMapSize(); i++)
		for (int j = 0; j < game->GetMapSize(i); j++)
		{
			auto cell = game->GetMapCell(i, j)->GetRectangle();
			if (cell.ContainsPoint(pstand))
				gfx->DrawCircle(cell.GetPosition().GetX() + TextureSize/2, cell.GetPosition().GetY() + TextureSize / 2, 30, 1, 1, 1, 1);
		}
}

void BombermanLevel::Update(long long timeTotal, long long timeDelta)
{
	for (int i = 0; i < game->GetEnemiesCount(); i++)
	{
		auto lastPos = game->GetEnemy(i)->GetRectangle();
		game->GetEnemy(i)->UpdateMove();
		if (game->IsCollideWithMap(game->GetEnemy(i)))
			game->GetEnemy(i)->SetRectangle(lastPos);
	}

	auto lastPos = game->GetPlayer()->GetRectangle();
	game->GetPlayer()->UpdateInput();
	if (game->IsCollideWithMap(game->GetPlayer()))
		game->GetPlayer()->SetRectangle(lastPos);
}
