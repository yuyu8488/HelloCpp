#include "Player.h"

#include <iostream>
Player::Player()
{
	std::cout << "Player ������" << std::endl;
}

Player::~Player()
{
	std::cout << "Player �Ҹ���" << std::endl;
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
