#pragma once
#include "Point.h"
class Game
{
private:
	int width;
	int* map;
	int* GetCellPtr(int _x, int _y) const;
	Point* FindPlayer() const;
	void Swap(int& p1, int& p2);
	void MixMap();
public:
	Game(int fieldWidth);
	~Game();
	int GetWidth() const;
	int GetCellValue(int _x, int _y) const;
	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();
	bool IsWin() const;
};
