#include "BombermanGame.h"
#include "GameController.h"
#include "Graphics.h"
#include "GlobalConstants.h"
#include <string>

BombermanGame::BombermanGame()
{
	CreateMap();

	auto idle = new SpriteSheet(L"m_idle.png", CharTextureSize, CharTextureSize, 1);

	auto left = new SpriteSheet(L"m_left.png", CharTextureSize,
		CharTextureSize, Character::animCountLeftRight);

	auto right = new SpriteSheet(L"m_right.png", CharTextureSize,
		CharTextureSize, Character::animCountLeftRight);

	auto up = new SpriteSheet(L"m_down.png", CharTextureSize,
		CharTextureSize, Character::animCountUpDown);

	auto down = new SpriteSheet(L"m_up.png", CharTextureSize,
		CharTextureSize, Character::animCountUpDown);

	auto characterWidth = CharTextureSize * 0.75f;
	auto characterHeight = CharTextureSize * 0.85f;
	auto rect = new Engine::Rectangle(Point(0, 0), characterWidth, characterHeight);
	player = new Player(idle, right, left, up, down, rect);

	enemies.push_back(new AI(idle, right, left, up, down,
		new Engine::Rectangle(Point(256, 256), characterWidth, characterHeight)));
}

BombermanGame::~BombermanGame()
{
	delete player;
	for (auto e : enemies)
		delete e;
	for (int i = 0; i < map.size(); i++)
		for (int j = 0; j < map[i].size(); j++)
			delete map[i][j];
}

int BombermanGame::GetEnemiesCount() const { return enemies.size(); }

AI* BombermanGame::GetEnemy(int i) { return enemies[i]; }

Player* BombermanGame::GetPlayer() const { return player; }

int BombermanGame::GetMapSize() const { return map.size(); }

int BombermanGame::GetMapSize(int i) const { return map[i].size(); }

SpriteActor* BombermanGame::GetMapCell(int i, int j) { return map[i][j]; }

bool BombermanGame::IsCollideWithMap(Character* character)
{
	auto charRect = character->GetRectangle();
	for (auto line : map)
		for (auto e : line)
		{
			auto rect = e->GetRectangle();
			if (rect.CanCollide() && rect.IsIntersected(charRect))
				return true;
		}
	return false;
}

void BombermanGame::CreateMap()
{
	const char leftTop = 'q';
	const char left = 'l';
	const char leftBot = 'a';
	const char rightTop = 'w';
	const char right = 'r';
	const char rightBot = 's';
	const char top = 't';
	const char bot = 'b';
	const char mid = 'm';
	const char round = 'h';
	std::vector<std::string> strmap
	{
		{ "qllllllllllla" },
		{ "thmhmhmhmhmhb" },
		{ "tmmmmmmmmmmmb" },
		{ "thmhmhmhmhmhb" },
		{ "tmmmmmmmmmmmb" },
		{ "thmhmhmhmhmhb" },
		{ "tmmmmmmmmmmmb" },
		{ "thmhmhmhmhmhb" },
		{ "tmmmmmmmmmmmb" },
		{ "thmhmhmhmhmhb" },
		{ "tmmmmmmmmmmmb" },
		{ "thmhmhmhmhmhb" },
		{ "wrrrrrrrrrrrs" }
	};
	for (int i = 0; i < strmap.size(); i++)
	{
		map.push_back(std::vector<SpriteActor*>());
		for (int j = 0; j < strmap[i].length(); j++)
		{
			switch (strmap[i][j])
			{
			case leftTop:
				CreateMapObject(L"leftTop.png", i, j, TextureSize, TextureSize, false);
				break;
			case left:
				CreateMapObject(L"leftMid.png", i, j, TextureSize, TextureSize, false);
				break;
			case leftBot:
				CreateMapObject(L"leftBot.png", i, j, TextureSize, TextureSize, false);
				break;
			case rightTop:
				CreateMapObject(L"rightTop.png", i, j, TextureSize, TextureSize, false);
				break;
			case right:
				CreateMapObject(L"rightMid.png", i, j, TextureSize, TextureSize, false);
				break;
			case rightBot:
				CreateMapObject(L"rightBot.png", i, j, TextureSize, TextureSize, false);
				break;
			case top:
				CreateMapObject(L"top.png", i, j, TextureSize, TextureSize, false);
				break;
			case bot:
				CreateMapObject(L"Bot.png", i, j, TextureSize, TextureSize, false);
				break;
			case mid:
				CreateMapObject(L"mid.png", i, j, TextureSize, TextureSize, false);
				break;
			case round:
				CreateMapObject(L"round.png", i, j, TextureSize * 0.8f, TextureSize * 0.8f, true);
				break;
			}
		}
	}
}

void BombermanGame::CreateMapObject(const wchar_t* ws, int i, int j, int rectW, int rectH, bool collision)
{
	auto fileName = const_cast<wchar_t*>(ws);
	const int cts = TextureSize;
	auto sprite = new SpriteSheet(fileName, cts, cts, 1);
	auto rect = new Engine::Rectangle(Point(i * cts, j * cts), rectW, rectH, collision);
	map[i].push_back(new SpriteActor(sprite, rect));
}

