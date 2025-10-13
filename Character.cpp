#include "Character.h"
#include <iostream>

Character::Character()
{
	std::cout << "Character »ý¼º" << std::endl;
}
Character::~Character()
{
	std::cout << "Character ¼Ò¸ê" << std::endl;
}

void Character::Move()
{
	std::cout << "Move" << std::endl;
}
