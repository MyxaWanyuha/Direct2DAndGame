#pragma once
class Point
{
	int x;
	int y;
public:
	Point(int newX, int newY);
	void SetX(int newX);
	void SetY(int newY);
	int GetX() const;
	int GetY() const;
};

