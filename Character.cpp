#include "Character.h"
#include <iostream>

Character::Character()
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
