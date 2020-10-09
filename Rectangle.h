#pragma once
#include "Point.h"

namespace Engine
{
	class Rectangle
	{
	private:
		Point position;//Top left corner
		int width;
		int height;
		bool isCollide;
	public:
		Rectangle(Point pos, int width, int height, bool haveCollision = false);
		void SetPosition(Point newPos);
		Point GetPosition() const;
		int GetLeft() const;
		int GetRight() const;
		int GetTop() const;
		int GetBottom() const;
		int GetWidth() const;
		int GetHeight() const;
		bool CanCollide();
		bool IsIntersected(const Rectangle& other) const;
		int IntersectionSquare(const Rectangle& other) const;
		int IndexOfInnerRectangle(const Rectangle& other) const;
		bool IsInner(const Rectangle& other) const;
		int IntersectLength(int leftTop1, int rightBot1, int leftTop2, int rightBot2) const;
		bool ContainsPoint(const Point& p) const;
	};
}
