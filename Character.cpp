#include "Character.h"
#include <iostream>

Character::Character() : Gold(0), HP(0)
{
	std::cout << "Character ����" << std::endl;
}
Character::~Character()
{
	std::cout << "Character �Ҹ�" << std::endl;
}

void Character::Move()
{
	std::cout << "Move" << std::endl;
}
