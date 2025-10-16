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

void Actor::SetPosition(const Position& NewPos)
{
	Pos.X = NewPos.X;
	Pos.Y = NewPos.Y;
}
