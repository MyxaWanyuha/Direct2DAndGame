#include <random>
#include "Point.h"
#include "Game.h"

Game::Game(int fieldWidth) : width(fieldWidth)
{
	int size = fieldWidth * fieldWidth;
	map = new int[size];
	for (int i = 0; i < size; i++)
		map[i] = i + 1;
	MixMap();
}

Game::~Game(){ delete[] map; }

int Game::GetWidth() const { return width; }

int Game::GetCellValue(int _x, int _y)  const { return map[_x * width + _y]; }

inline int* Game::GetCellPtr(int _x, int _y) const { return map + (int64_t)_y * width + _x; }

void Game::MoveRight()
{
	auto p = FindPlayer();
	if (p->GetX() < width - 1)
		Swap(*GetCellPtr(p->GetX(), p->GetY()), *GetCellPtr(p->GetX() + 1, p->GetY()));
	delete p;
}

void Game::MoveLeft()
{
	auto p = FindPlayer();
	if (p->GetX() > 0)
		Swap(*GetCellPtr(p->GetX(), p->GetY()), *GetCellPtr(p->GetX() - 1, p->GetY()));
	delete p;
}

void Game::MoveUp()
{
	auto p = FindPlayer();
	if (p->GetY() > 0)
		Swap(*GetCellPtr(p->GetX(), p->GetY()), *GetCellPtr(p->GetX(), p->GetY() - 1));
	delete p;
}

void Game::MoveDown()
{
	auto p = FindPlayer();
	if (p->GetY() < width - 1)
		Swap(*GetCellPtr(p->GetX(), p->GetY()), *GetCellPtr(p->GetX(), p->GetY() + 1));
	delete p;
}

bool Game::IsWin() const
{
	for (int i = 0; i < width * width - 1; i++)
		if (map[i] > map[i + 1]) return false;
	return true;
}

Point* Game::FindPlayer() const
{
	int player = width * width;
	for(int i = 0; i < player; i++)
		if(map[i] == player)
			return  new Point(i % width, i / width);
}

void Game::Swap(int& p1, int& p2)
{
	p1 = p1 ^ p2;
	p2 = p1 ^ p2;
	p1 = p1 ^ p2;
}

void Game::MixMap()
{
	for (int n = 0; n < 500; n++)
	{
		int com = rand() % 4;
		switch (com)
		{
		case 0:
			MoveRight();
			break;
		case 1:
			MoveLeft();
			break;
		case 2:
			MoveUp();
			break;
		case 3:
			MoveDown();
			break;
		}
	}
}
