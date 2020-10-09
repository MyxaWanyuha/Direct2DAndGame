#pragma once
#include <memory>
#include "Rectangle.h"
class Actor
{
protected:
	Engine::Rectangle* rectangle;
public:
	Actor(Engine::Rectangle* rect);
	~Actor();
	void SetRectangle(Engine::Rectangle rect);
	Engine::Rectangle GetRectangle() const;
	Point GetPoint() const;
};

