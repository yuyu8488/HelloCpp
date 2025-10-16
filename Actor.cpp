#include "Actor.h"

Actor::Actor() : Shape('?'), Pos(0,0)
{
}

Actor::~Actor()
{
}

void Actor::Tick()
{

}

void Actor::SetActorLocation(const Vector2& NewPos)
{
	Pos = NewPos;
}

void Actor::SetActorLocation(const int& X, const int& Y)
{
	Pos = Vector2(X, Y);
}
