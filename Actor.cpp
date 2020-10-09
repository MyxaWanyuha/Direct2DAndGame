#include "Actor.h"

Actor::Actor(Engine::Rectangle* rect) : rectangle(rect){}

Actor::~Actor()
{
	delete rectangle;
}

void Actor::SetRectangle(Engine::Rectangle rect) { *rectangle = rect; }

Engine::Rectangle Actor::GetRectangle() const {	return *rectangle; }

Point Actor::GetPoint() const { return rectangle->GetPosition(); }
