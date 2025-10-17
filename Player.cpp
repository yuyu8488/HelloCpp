#include "Player.h"

Player::Player()
{
	Vector2 Pos(1, 1);
	
	SetActorLocation(Pos);
	SetShape('P');
}

Player::~Player()
{
	Actor::~Actor();
}

void Player::Tick()
{

}

void Player::Move(const int& Input)
{
	Vector2 Pos = GetActorLocation();
	switch (Input)
	{
	case 'w':
		SetActorLocation(Pos - Vector2(0,-1));
		break;
	case 's':
		SetActorLocation(Pos + Vector2(0,1));
		break;
	case 'a':
		SetActorLocation(Pos.X - 1, Pos.Y);
		break;
	case 'd':
		SetActorLocation(Pos.X + 1, Pos.Y);
		break;
	default:
		break;
	}
}

