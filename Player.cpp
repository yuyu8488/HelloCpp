#include "Player.h"

#include <iostream>
Player::Player()
{
	std::cout << "Player 持失切" << std::endl;
}

Player::~Player()
{
	std::cout << "Player 社瑚切" << std::endl;
}

void Player::Move()
{
	std::cout << "Player ";
	Character::Move();
}

void Player::Attack()
{
}

void Player::Collect()
{
}
