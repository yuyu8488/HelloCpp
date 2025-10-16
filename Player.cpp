#include "Player.h"

Player::Player()
{
	Position Pos(1, 1);
	
	SetPosition(Pos);
	SetShape('P');
}

Player::~Player()
{
	
}

void Player::Tick()
{

}
