#include "Point.h"

Point::Point(int newX, int newY) :x(newX), y(newY) {}

void Point::SetX(int newX) { x = newX; }

void Point::SetY(int newY) { y = newY; }

int Point::GetX() const { return x; }

int Point::GetY() const { return y; }

const Point operator+(Point& lhs, Point& rhs)
{
	return Point(lhs.GetX() + rhs.GetX(), lhs.GetY() + rhs.GetY());
}

const Point operator-(Point& lhs, Point& rhs)
{
	return Point(lhs.GetX() - rhs.GetX(), lhs.GetY() - rhs.GetY());
}
