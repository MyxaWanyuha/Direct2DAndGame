#include <algorithm>
#include "Rectangle.h"
namespace Engine
{
    Rectangle::Rectangle(Point pos, int w, int h, bool haveCollision)
        : position(pos), width(w), height(h), isCollide(haveCollision) {}

    void Rectangle::SetPosition(Point newPos)
    {
        position = newPos;
    }

    Point Rectangle::GetPosition() const { return position; }

    int Rectangle::GetLeft() const { return position.GetX(); }

    int Rectangle::GetRight() const { return position.GetX() + width; }

    int Rectangle::GetTop() const { return position.GetY(); }

    int Rectangle::GetBottom() const { return position.GetY() + height; }

    int Rectangle::GetWidth() const { return width; }

    int Rectangle::GetHeight() const { return height; }

    bool Rectangle::CanCollide() { return isCollide; }

    bool Rectangle::ContainsPoint(const Point& p) const
    {
        return p.GetX() >= GetLeft() && p.GetX() <= GetRight() && p.GetY() >= GetTop() && p.GetY() <= GetBottom();
    }

    bool Rectangle::IsIntersected(const Rectangle& other) const
    {
        return GetLeft() <= other.GetRight() && GetRight() >= other.GetLeft()
            && GetBottom() >= other.GetTop() && GetTop() <= other.GetBottom();
    }

    int Rectangle::IntersectionSquare(const Rectangle& other) const
    {
        return IntersectLength(GetLeft(), GetRight(), other.GetLeft(), other.GetRight())
            * IntersectLength(GetTop(), GetBottom(), other.GetTop(), other.GetBottom());
    }

    int Rectangle::IndexOfInnerRectangle(const Rectangle& other) const
    {
        if (IsInner(other)) return 0;
        if (IsInner(other)) return 1;
        return -1;
    }

    bool Rectangle::IsInner(const Rectangle& other) const
    {
        return GetTop() >= other.GetTop() && GetBottom() <= other.GetBottom()
            && GetRight() <= other.GetRight() && GetLeft() >= other.GetLeft();
    }

    int Rectangle::IntersectLength(int leftTop1, int rightBot1, int leftTop2, int rightBot2) const
    {
        return std::max(std::min(rightBot1, rightBot2) - std::max(leftTop1, leftTop2), 0);
    }
}