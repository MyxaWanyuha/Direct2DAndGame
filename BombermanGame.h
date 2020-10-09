#pragma once
#include <vector>
#include <memory>
#include "SpriteActor.h"
#include "Player.h"
#include "AI.h"
#include "Bomb.h"
class BombermanGame
{
private:
	Player* player;
	std::vector<Bomb*> bombs;
	std::vector<std::vector<SpriteActor*>> map;
	std::vector<AI*> enemies;

	void CreateMap();
	void CreateMapObject(const wchar_t* ws, int i, int j, int rectW, int rectH, bool collision);
public:
	int GetEnemiesCount() const;
	AI* GetEnemy(int i);
	Player* GetPlayer() const;
	int GetMapSize() const;
	int GetMapSize(int i) const;
	SpriteActor* GetMapCell(int i, int j);
	bool IsCollideWithMap(Character* character);
	BombermanGame();
	~BombermanGame();
};

